#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;

// Student structure - stores student information
struct Student {
  string rollNumber;
  string name;
  string university;
  string batch;
  int semester;
  string degree;
  Student *next; // pointer for linked list (collision handling)
};

// Hash Table class
class HashTable {
private:
  Student *table[11]; // array of 11 pointers

  // helper functions
  int convertToInt(string rollNumber);
  int getHashIndex(string rollNumber);

public:
  // constructor and destructor
  HashTable();
  ~HashTable();

  // main functions
  void insert(string rollNumber, string name, string university, string batch,
              int semester, string degree);
  Student *search(string rollNumber);
  void deleteStudent(string rollNumber);
  void updateSemester(string rollNumber, int newSemester);
  void updateDegree(string rollNumber, string newDegree, string newBatch);
  void updateBatch(string rollNumber, string newBatch);
  void display(string rollNumber);
  void displayAll();
  void showStatus();
};
void startprogram(HashTable ht);
#endif
