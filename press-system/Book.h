#ifndef Book_h
#define Book_h
#include "Publisher.h"
#include "author.h"
#include <iostream>
using namespace std;
class Book {
private:
  string name;
  Author author;
  double price;
  Publisher publisher;

public:
  // Constructors
  Book();
  Book(string n, const Author &a, double p, const Publisher &pub);
  // Copy Constructor, Destructor
  Book(const Book &other);
  ~Book();

  string getName() const;
  Author getAuthor() const;
  double getPrice() const;
  Publisher getPublisher() const;

  void setName(string n);
  void setAuthor(const Author &a);
  void setPrice(double p);
  void setPublisher(const Publisher &pub);
  void increasePrice(double price);
  void decreasePrice(double price);

  void setBookInfo(const Author &a, const Publisher &p);
  void updatePublisher(const Publisher &newPub);
  void applyDiscount(double percentage);
  void printBookDetails() const;
  bool isExpensive() const;

  // Operator Overloads
  // Increase/Decrease Price
  Book operator+(double amount) const; // Increase price
  Book operator-(double amount) const; // Decrease price

  // Comparison Operators
  bool operator>(const Book &other) const;  // Compare by Price
  bool operator<(const Book &other) const;  // Compare by Price
  bool operator==(const Book &other) const; // Compare by Authors (Name)
  bool operator!=(const Book &other) const; // Compare by Publication Year
};

#endif
