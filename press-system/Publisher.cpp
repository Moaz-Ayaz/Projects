#include "Publisher.h"
#include <iostream>
#include <limits>
using namespace std;
int getCurrentYear() {
  time_t t = time(0);
  struct tm *now = localtime(&t);
  return now->tm_year + 1900;
}

// Default Constructor
Publisher::Publisher()
    : name(" Press"), city("Lahore"), yearOfPublication(getCurrentYear()) {}

// Parameterized Constructor
Publisher::Publisher(string n, string c, int y)
    : name(n), city(c), yearOfPublication(y) {}

// Copy Constructor
Publisher::Publisher(const Publisher &other)
    : name(other.name), city(other.city),
      yearOfPublication(other.yearOfPublication) {}

Publisher::~Publisher() {}

string Publisher::getName() const { return name; }
string Publisher::getCity() const { return city; }
int Publisher::getYearOfPublication() const { return yearOfPublication; }

void Publisher::setName(string n) { name = n; }
void Publisher::setCity(string c) { city = c; }
void Publisher::setYearOfPublication(int y) { yearOfPublication = y; }

void Publisher::changeName(const std::string &newName) {
  name = newName;
  cout << "Publisher name updated to: " << name << endl;
}

void Publisher::updateCity(const std::string &newCity) {
  city = newCity;
  cout << "Publisher city updated to: " << city << endl;
}

void Publisher::printPublisherInfo() const {
  cout << "Publisher Name: " << name << endl;
  cout << "City: " << city << endl;
  cout << "Publication Year: " << yearOfPublication << endl;
  cout << "Status: " << (isOldPublisher() ? "Old Publisher" : "New Publisher")
       << endl;
}

void Publisher::setPublisherInfo() {
  cout << "\n--- Enter Publisher Details ---" << endl;
  cout << "Enter Name: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, name);
  cout << "Enter City: ";
  getline(cin, city);
  int currentYear = getCurrentYear();
  cout << "Enter Year of Publication (e.g., " << currentYear << "): ";
  while (!(cin >> yearOfPublication) || yearOfPublication <= 0 ||
         yearOfPublication > currentYear) {
    cout << "Invalid year. Must be a positive year up to " << currentYear
         << ": ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cout << "Publisher details set successfully." << endl;
}

bool Publisher::isOldPublisher() const {
  return (getCurrentYear() - yearOfPublication) > 10;
}
