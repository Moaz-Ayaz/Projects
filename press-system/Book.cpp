#include "Book.h"
#include "limits"
#include <iostream>
using namespace std;
// Default Constructor
Book::Book() : name("Untitled"), author(), price(0.0), publisher() {}
void Book::increasePrice(double price) { this->price += price; }
void Book::decreasePrice(double price) { this->price -= price; }
// Parameterized Constructor
Book::Book(string n, const Author &a, double p, const Publisher &pub)
    : name(n), author(a), price(max(0.0, p)), publisher(pub) {}

// Copy Constructor
Book::Book(const Book &other)
    : name(other.name), author(other.author), price(other.price),
      publisher(other.publisher) {}

// Destructor
Book::~Book() {}

string Book::getName() const { return name; }
Author Book::getAuthor() const { return author; }
double Book::getPrice() const { return price; }
Publisher Book::getPublisher() const { return publisher; }

void Book::setName(string n) { name = n; }
void Book::setAuthor(const Author &a) { author = a; }
void Book::setPrice(double p) { price = max(0.0, p); }
void Book::setPublisher(const Publisher &pub) { publisher = pub; }

void Book::setBookInfo(const Author &a, const Publisher &p) {
  cout << "\n--- Enter Book Details ---" << endl;
  cout << "Enter Book Name: ";

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, name);

  cout << "Enter Price (in Rupees): ";
  while (!(cin >> price) || price < 0.0) {
    cout << "Invalid price. Please enter a non-negative number: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  this->price = max(0.0, price);

  // Set Author and Publisher objects (passed in from the main arrays)
  author = a;
  publisher = p;

  cout << "Book details set successfully. Author and Publisher linked." << endl;
}

void Book::updatePublisher(const Publisher &newPub) {
  publisher = newPub;
  cout << "Book's publisher updated successfully to " << newPub.getName() << "."
       << endl;
}

void Book::applyDiscount(double percentage) {
  if (percentage >= 0.0 && percentage <= 100.0) {
    double oldPrice = price;
    price = price * (1.0 - (percentage / 100.0));
    cout << "Applied " << percentage << "% discount. Price changed from "
         << oldPrice << " to " << price << " Rs." << endl;
  } else {
    cout << "Invalid discount percentage. Must be between 0 and 100." << endl;
  }
}

void Book::printBookDetails() const {
  cout << "\n==================================" << endl;
  cout << "📚 Book Name: " << name << endl;
  cout << "💰 Price: " << price << " Rs." << endl;
  cout << "Status: " << (isExpensive() ? "Expensive Book" : "Affordable Book")
       << endl;
  cout << "----------------------------------" << endl;
  cout << "👤 Author Details:" << endl;
  author.printAuthor();
  cout << "----------------------------------" << endl;
  cout << "🏢 Publisher Details:" << endl;
  publisher.printPublisherInfo();
  cout << "==================================" << endl;
}

bool Book::isExpensive() const { return price > 2000.0; }

// Operator Overloads

// Increase Price (Book + amount)
Book Book::operator+(double amount) const {
  return Book(name, author, price + amount, publisher);
}

// Decrease Price (Book - amount)
Book Book::operator-(double amount) const {
  // Ensure price doesn't go below zero
  double newPrice = price - amount;
  return Book(name, author, std::max(0.0, newPrice), publisher);
}

// Comparison by Price (Book > otherBook)
bool Book::operator>(const Book &other) const { return price > other.price; }

// Comparison by Price (Book < otherBook)
bool Book::operator<(const Book &other) const { return price < other.price; }

// Comparison by Author Name (Book == otherBook)
bool Book::operator==(const Book &other) const {
  return author.getName() == other.author.getName();
}

// Comparison by Publication Year (Book != otherBook)
bool Book::operator!=(const Book &other) const {
  return publisher.getYearOfPublication() !=
         other.publisher.getYearOfPublication();
}
