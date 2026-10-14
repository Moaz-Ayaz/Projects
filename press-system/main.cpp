#include "Book.h"
#include "Publisher.h"
#include "author.h"
#include <iostream>
using namespace std;

// Function prototypes for menu handling
void printMenu();
void enterDetailsMenu(Book books[], int &bCount, Author authors[], int &aCount,
                      Publisher pubs[], int &pCount);
void compareBookMenu(Book books[], int bCount);

int main() {
  // Arrays as requested
  Book books[10];
  Publisher publishers[3];
  Author authors[4];

  // Counters to track valid entries
  int bookCount = 0;
  int pubCount = 0;
  int authCount = 0;

  int choice;
  do {
    printMenu();
    cout << "Select option: ";
    cin >> choice;

    switch (choice) {
    case 1:
      enterDetailsMenu(books, bookCount, authors, authCount, publishers,
                       pubCount);
      break;

    case 2: // Update Publisher Details via Book
      if (bookCount == 0) {
        cout << "No books available to update publisher info." << endl;
      } else {
        int idx;
        cout << "Select Book index (0 to " << bookCount - 1 << "): ";
        cin >> idx;
        if (idx >= 0 && idx < bookCount) {
          cout << "Current Publisher City: "
               << books[idx].getPublisher().getCity() << endl;
          string newCity;
          cout << "Enter new city: ";
          cin.ignore();
          getline(cin, newCity);
          // Use the accessor that returns a reference to modify actual object
          books[idx].getPublisher().updateCity(newCity);
        } else {
          cout << "Invalid index." << endl;
        }
      }
      break;

    case 3: // Apply Discount
      if (bookCount == 0) {
        cout << "No books available." << endl;
      } else {
        int idx;
        double disc;
        cout << "Select Book index (0 to " << bookCount - 1 << "): ";
        cin >> idx;
        if (idx >= 0 && idx < bookCount) {
          cout << "Enter discount percentage: ";
          cin >> disc;
          books[idx].applyDiscount(disc);
        }
      }
      break;

    case 4: // Change Price (+ or -)
      if (bookCount == 0) {
        cout << "No books available." << endl;
      } else {
        int idx, subOp;
        double amount;
        cout << "Select Book index (0 to " << bookCount - 1 << "): ";
        cin >> idx;
        if (idx >= 0 && idx < bookCount) {
          cout << "1. Increase Price\n2. Decrease Price\nChoice: ";
          cin >> subOp;
          cout << "Enter amount: ";
          cin >> amount;
          if (subOp == 1) {
            books[idx].increasePrice(amount);
          } else if (subOp == 2) {
            books[idx].decreasePrice(amount);
          }
        }
      }
      break;

    case 5: // Check is expensive
      if (bookCount == 0) {
        cout << "No books available." << endl;
      } else {
        int idx;
        cout << "Select Book index (0 to " << bookCount - 1 << "): ";
        cin >> idx;
        if (idx >= 0 && idx < bookCount) {
          if (books[idx].isExpensive())
            cout << "Yes, this book is expensive (> 2000 PKR)." << endl;
          else
            cout << "No, this book is affordable." << endl;
        }
      }
      break;

    case 6: // Print complete info
      if (bookCount == 0)
        cout << "No books recorded." << endl;
      for (int i = 0; i < bookCount; i++) {
        cout << "Index [" << i << "]:";
        books[i].printBookDetails();
      }
      break;

    case 7: // Compare books
      compareBookMenu(books, bookCount);
      break;

    case 0:
      cout << "Exiting Press System..." << endl;
      break;

    default:
      cout << "Invalid option." << endl;
    }

  } while (choice != 0);

  return 0;
}

void printMenu() {
  cout << "\n--- Menu ---" << endl;
  cout << "1. Enter Details (Book/Author/Publisher)" << endl;
  cout << "2. Update Publisher Details (via Book)" << endl;
  cout << "3. Apply Discount" << endl;
  cout << "4. Change Price (Increase/Decrease)" << endl;
  cout << "5. Check if Book is Expensive" << endl;
  cout << "6. Print Complete Book Information" << endl;
  cout << "7. Compare Books" << endl;
  cout << "0. Exit" << endl;
}

void enterDetailsMenu(Book books[], int &bCount, Author authors[], int &aCount,
                      Publisher pubs[], int &pCount) {
  int choice;
  cout << "\n-- Entry Submenu --" << endl;
  cout << "1. Add New Author (Max 4, Curr: " << aCount << ")" << endl;
  cout << "2. Add New Publisher (Max 3, Curr: " << pCount << ")" << endl;
  cout << "3. Create New Book (Max 10, Curr: " << bCount << ")" << endl;
  cout << "Enter choice: ";
  cin >> choice;

  if (choice == 1) {
    if (aCount < 4) {
      authors[aCount].setAuthorInfo();
      aCount++;
      cout << "Author added successfully." << endl;
    } else
      cout << "Author Limit Reached." << endl;
  } else if (choice == 2) {
    if (pCount < 3) {
      pubs[pCount].setPublisherInfo();
      pCount++;
      cout << "Publisher added successfully." << endl;
    } else
      cout << "Publisher Limit Reached." << endl;
  } else if (choice == 3) {
    if (bCount < 10) {
      // Must have author and publisher first
      if (aCount == 0 || pCount == 0) {
        cout << "Error: You need at least one Author and one Publisher defined "
                "first."
             << endl;
        return;
      }

      string title;
      double price;
      int aIdx, pIdx;

      cout << "Enter Book Title: ";
      cin.ignore();
      getline(cin, title);
      cout << "Enter Price: ";
      cin >> price;

      // Select Author
      cout << "Select Author Index (0-" << aCount - 1 << "): " << endl;
      for (int i = 0; i < aCount; i++)
        cout << i << ". " << authors[i].getName() << endl;
      cin >> aIdx;

      // Select Publisher
      cout << "Select Publisher Index (0-" << pCount - 1 << "): " << endl;
      for (int i = 0; i < pCount; i++)
        cout << i << ". " << pubs[i].getName() << endl;
      cin >> pIdx;

      if (aIdx >= 0 && aIdx < aCount && pIdx >= 0 && pIdx < pCount) {
        books[bCount] = Book(title, authors[aIdx], price, pubs[pIdx]);
        bCount++;
        cout << "Book created successfully." << endl;
      } else {
        cout << "Invalid Index selected." << endl;
      }

    } else
      cout << "Book Limit Reached." << endl;
  }
}

void compareBookMenu(Book books[], int bCount) {
  if (bCount < 2) {
    cout << "Need at least 2 books to compare." << endl;
    return;
  }

  int idx1, idx2, type;
  cout << "Enter index of Book 1: ";
  cin >> idx1;
  cout << "Enter index of Book 2: ";
  cin >> idx2;

  if (idx1 >= 0 && idx1 < bCount && idx2 >= 0 && idx2 < bCount) {
    cout << "Compare by: 1. Price 2. Author 3. Publication Year\nChoice: ";
    cin >> type;

    if (type == 1) {
      // Uses operator >
      if (books[idx1] > books[idx2])
        cout << books[idx1].getName() << " is more expensive than "
             << books[idx2].getName() << endl;
      else if (books[idx2] > books[idx1])
        cout << books[idx2].getName() << " is more expensive than "
             << books[idx1].getName() << endl;
      else
        cout << "Both have the same price." << endl;
    } else if (type == 2) {
      // Uses operator ==
      if (books[idx1] == books[idx2])
        cout << "Both books are written by the same author ("
             << books[idx1].getAuthor().getName() << ")." << endl;
      else
        cout << "Books are written by different authors." << endl;
    } else if (type == 3) {
      // Uses operator < (checks year)
      if (books[idx1] < books[idx2])
        cout << books[idx1].getName() << " has an older publisher than "
             << books[idx2].getName() << endl;
      else if (books[idx2] < books[idx1])
        cout << books[idx2].getName() << " has an older publisher than "
             << books[idx1].getName() << endl;
      else
        cout << "Publishers established in the same year." << endl;
    }
  } else {
    cout << "Invalid indices." << endl;
  }
}
