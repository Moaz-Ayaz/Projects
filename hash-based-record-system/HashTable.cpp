#include "HashTable.h"

// Constructor - set all pointers to NULL
HashTable::HashTable() {
  for (int i = 0; i < 11; i++) {
    table[i] = NULL;
  }
}

// Destructor - delete all students
HashTable::~HashTable() {
  for (int i = 0; i < 11; i++) {
    Student *current = table[i];
    while (current != NULL) {
      Student *temp = current;
      current = current->next;
      delete temp;
    }
  }
}

// Convert roll number to integer
// Example: "2024-cs-055" becomes 2024055
int HashTable::convertToInt(string rollNumber) {
  int number = 0;

  // go through each character
  for (int i = 0; i < rollNumber.length(); i++) {
    // check if it's a digit
    if (rollNumber[i] >= '0' && rollNumber[i] <= '9') {
      number = number * 10 + (rollNumber[i] - '0');
    }
  }

  return number;
}

// Hash function - get index using modulo
int HashTable::getHashIndex(string rollNumber) {
  int num = convertToInt(rollNumber);
  int index = num % 11;
  return index;
}

// Insert new student
void HashTable::insert(string rollNumber, string name, string university,
                       string batch, int semester, string degree) {

  // check if student already exists
  if (search(rollNumber) != NULL) {
    cout << "\nError: Student already exists!" << endl;
    return;
  }

  // get hash index
  int index = getHashIndex(rollNumber);

  // create new student
  Student *newStudent = new Student();
  newStudent->rollNumber = rollNumber;
  newStudent->name = name;
  newStudent->university = university;
  newStudent->batch = batch;
  newStudent->semester = semester;
  newStudent->degree = degree;
  newStudent->next = NULL;

  // check if index is empty
  if (table[index] == NULL) {
    // no collision
    table[index] = newStudent;
    cout << "\nStudent added at index " << index << " (No collision)" << endl;
  } else {
    // collision - add at start of linked list
    cout << "\nCollision at index " << index << "!" << endl;
    newStudent->next = table[index];
    table[index] = newStudent;
    cout << "Student added using chaining" << endl;
  }
}

// Search for student by roll number
Student *HashTable::search(string rollNumber) {

  // get hash index
  int index = getHashIndex(rollNumber);

  // search in linked list at that index
  Student *current = table[index];

  while (current != NULL) {
    if (current->rollNumber == rollNumber) {
      return current;
    }
    current = current->next;
  }

  return NULL; // not found
}

// Delete student
void HashTable::deleteStudent(string rollNumber) {

  // get hash index
  int index = getHashIndex(rollNumber);

  Student *current = table[index];
  Student *previous = NULL;

  // search for student
  while (current != NULL) {
    if (current->rollNumber == rollNumber) {

      // student found - delete it
      if (previous == NULL) {
        // student is first in list
        table[index] = current->next;
      } else {
        // student is in middle or end
        previous->next = current->next;
      }

      delete current;
      cout << "\nStudent deleted successfully!" << endl;
      return;
    }

    previous = current;
    current = current->next;
  }

  cout << "\nStudent not found!" << endl;
}

// Update semester
void HashTable::updateSemester(string rollNumber, int newSemester) {

  Student *student = search(rollNumber);

  if (student == NULL) {
    cout << "\nStudent not found!" << endl;
    return;
  }

  if (newSemester < 1 || newSemester > 8) {
    cout << "\nInvalid semester! Enter between 1-8" << endl;
    return;
  }

  student->semester = newSemester;
  cout << "\nSemester updated successfully!" << endl;
}

// Update degree (batch must also change)
void HashTable::updateDegree(string rollNumber, string newDegree,
                             string newBatch) {

  Student *student = search(rollNumber);

  if (student == NULL) {
    cout << "\nStudent not found!" << endl;
    return;
  }

  student->degree = newDegree;
  student->batch = newBatch;
  cout << "\nDegree and batch updated successfully!" << endl;
}

// Update batch only
void HashTable::updateBatch(string rollNumber, string newBatch) {

  Student *student = search(rollNumber);

  if (student == NULL) {
    cout << "\nStudent not found!" << endl;
    return;
  }

  student->batch = newBatch;
  cout << "\nBatch updated successfully!" << endl;
}

// Display one student
void HashTable::display(string rollNumber) {

  Student *student = search(rollNumber);

  if (student == NULL) {
    cout << "\nStudent not found!" << endl;
    return;
  }

  cout << "Student Details:" << endl;
  cout << "Roll Number: " << student->rollNumber << endl;
  cout << "Name: " << student->name << endl;
  cout << "University: " << student->university << endl;
  cout << "Batch: " << student->batch << endl;
  cout << "Semester: " << student->semester << endl;
  cout << "Degree: " << student->degree << endl;
  cout << "Hash Index: " << getHashIndex(rollNumber) << endl;
}

// Display all students
void HashTable::displayAll() {

  cout << "All Students:" << endl;

  int count = 0;

  // go through each index
  for (int i = 0; i < 10; i++) {

    if (table[i] != NULL) {
      cout << "\nIndex [" << i << "]:" << endl;

      Student *current = table[i];
      int position = 1;

      // go through linked list at this index
      while (current != NULL) {
        cout << "  Position " << position << ":" << endl;
        cout << "    Roll No: " << current->rollNumber << endl;
        cout << "    Name: " << current->name << endl;
        cout << "    Semester: " << current->semester << endl;
        cout << "    Degree: " << current->degree << endl;

        current = current->next;
        position++;
        count++;
      }
    }
  }

  if (count == 0) {
    cout << "\nNo students found!" << endl;
  }

  cout << "\nTotal students: " << count << endl;
}

// Show hash table status
void HashTable::showStatus() {

  cout << "Hash Table Status:" << endl;
  cout << "Table Size: 11" << endl;

  int total = 0;
  int collisions = 0;

  // check each index
  for (int i = 0; i < 11; i++) {
    cout << "Index [" << i << "]: ";

    if (table[i] == NULL) {
      cout << "Empty" << endl;
    } else {
      Student *current = table[i];
      int count = 0;

      // count students at this index
      while (current != NULL) {
        count++;
        total++;
        current = current->next;
      }

      cout << count << " student(s)";

      if (count > 1) {
        cout << " - COLLISION!";
        collisions = collisions + (count - 1);
      }

      cout << endl;
    }
  }

  cout << "Total Students: " << total << endl;
  cout << "Total Collisions: " << collisions << endl;
}
void startprogram(HashTable ht) {
  int choice;
  while (true) {

    // show menu
    cout << "Menu:" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Search Student" << endl;
    cout << "3. Delete Student" << endl;
    cout << "4. Update Student" << endl;
    cout << "5. Display All Students" << endl;
    cout << "6. Show Hash Table Status" << endl;
    cout << "0. Exit" << endl;
    while (true) {
      cout << "Enter choice: ";
      cin >> choice;
      if (cin.fail()) {
        cin.clear();            // clear error flag
        cin.ignore(1000, '\n'); // ignore bad input
        cout << "\nError: Please enter a number!" << endl;
        continue; // go back to menu
        cin.ignore();
      }
      break;
    }
    if (choice == 1) {
      // add student
      string rollNumber, name, university, batch, degree;
      int semester;

      cout << "\n--- Add New Student ---" << endl;
      cout << "Enter Roll Number: ";
      cin >> rollNumber;

      cin.ignore();
      cout << "Enter Name: ";
      getline(cin, name);

      cout << "Enter University: ";
      getline(cin, university);

      cout << "Enter Batch: ";
      getline(cin, batch);
      while (true) {
        cout << "Enter Semester (1-8): ";
        cin >> semester;
        if (cin.fail()) {
          cin.clear();            // clear error flag
          cin.ignore(1000, '\n'); // ignore bad input
          cout << "\nError: Please enter a number!" << endl;
          continue; // go back to menu
          cin.ignore();
        } else if (semester < 1 || semester > 8) {
          cout << "\nError: Semester must be between 1 and 8!" << endl;
          continue;
        }
        break;
      }
      cin.ignore(1000, '\n');
      cout << "Enter Degree: ";
      getline(cin, degree);

      ht.insert(rollNumber, name, university, batch, semester, degree);
    } else if (choice == 2) {
      // search student
      string rollNumber;

      cout << "\n--- Search Student ---" << endl;
      cout << "Enter Roll Number: ";
      cin >> rollNumber;

      ht.display(rollNumber);
    } else if (choice == 3) {
      // delete student
      string rollNumber;
      char confirm;

      cout << "\n--- Delete Student ---" << endl;
      cout << "Enter Roll Number: ";
      cin >> rollNumber;

      ht.display(rollNumber);

      cout << "\nAre you sure? (y/n): ";
      cin >> confirm;

      if (confirm == 'y' || confirm == 'Y') {
        ht.deleteStudent(rollNumber);
      } else {
        cout << "\nDeletion cancelled" << endl;
      }
    } else if (choice == 4) {
      // update student
      string rollNumber;
      int updateChoice;

      cout << "\n--- Update Student ---" << endl;
      cout << "Enter Roll Number: ";
      cin >> rollNumber;

      if (ht.search(rollNumber) == NULL) {
        cout << "\nStudent not found!" << endl;
        continue;
      }

      ht.display(rollNumber);

      cout << "\nWhat to update?" << endl;
      cout << "1. Update Semester" << endl;
      cout << "2. Update Degree (batch will also change)" << endl;
      cout << "3. Update Batch only" << endl;
      cout << "Enter choice: ";
      cin >> updateChoice;

      if (updateChoice == 1) {
        int newSemester;
        while (true) {
          cout << "Enter Semester (1-8): ";
          cin >> newSemester;
          if (cin.fail()) {
            cin.clear();            // clear error flag
            cin.ignore(1000, '\n'); // ignore bad input
            cout << "\nError: Please enter a number!" << endl;
            continue; // go back to menu
            cin.ignore();
          } else if (newSemester < 1 || newSemester > 8) {
            cout << "\nError: Semester must be between 1 and 8!" << endl;
            continue;
          }
          ht.updateSemester(rollNumber, newSemester);
          break;
        }
      } else if (updateChoice == 2) {
        string newDegree, newBatch;
        cin.ignore();
        cout << "Enter new degree: ";
        getline(cin, newDegree);
        cout << "Enter new batch: ";
        getline(cin, newBatch);
        ht.updateDegree(rollNumber, newDegree, newBatch);
      } else if (updateChoice == 3) {
        string newBatch;
        cin.ignore();
        cout << "Enter new batch: ";
        getline(cin, newBatch);
        ht.updateBatch(rollNumber, newBatch);
      } else {
        cout << "\nInvalid choice!" << endl;
      }
    } else if (choice == 5) {
      // display all
      ht.displayAll();
    } else if (choice == 6) {
      // show status
      ht.showStatus();
    } else if (choice == 0) {
      // exit
      cout << "\nThank you!" << endl;
      cout << "Project by: Sameer, Nosherwan, Moaz" << endl;
      break;
    } else {
      cout << "\nInvalid choice! Try again." << endl;
    }
  }
}
