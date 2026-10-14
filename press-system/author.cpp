#include"author.h"
#include<limits>
#include<iostream>
using namespace std;
Author::Author() : name("N/A"), age(0), gender("N/A"), cnic("N/A"), experience(0) {}

// Parameterized Constructor
Author::Author(string n, int a, string g, string c, int e)
    : name(n), age(a), gender(g), cnic(c), experience(e) {}

// Copy Constructor
Author::Author(const Author& other)
    : name(other.name), age(other.age), gender(other.gender), cnic(other.cnic), experience(other.experience) {}

Author::~Author() {}


string Author::getName() const { return name; }
int Author::getAge() const { return age; }
string Author::getGender() const { return gender; }
string Author::getCnic() const { return cnic; }
int Author::getExperience() const { return experience; }

void Author::setName(string n) { name = n; }
void Author::setAge(int a) { age = a; }
void Author::setGender(string g) { gender = g; }
void Author::setCnic(string c) { cnic = c; }
void Author::setExperience(int e) { experience = e; }


void Author::setAuthorInfo() {
    cout << "\n--- Enter Author Details ---" << endl;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    
    cout << "Enter Age: ";
    while (!(cin >> age) || age < 0) {
        cout << "Invalid age. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "Enter Gender (M/F/Other): ";
    cin >> gender;
    
    cout << "Enter CNIC: ";
    cin >> cnic;

    cout << "Enter Experience (Years): ";
    while (!(cin >> experience) || experience < 0) {
        cout << "Invalid experience. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Author details set successfully." << endl;
}

void Author::printAuthor() const {
    cout << "Author Name: " << name << endl;
   cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Experience: " << experience << " years" << endl;
}
