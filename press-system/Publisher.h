#ifndef Publisher_h
#define Publisher_h
#include<iostream>
using namespace std;
class Publisher {
private:
    string name;
    string city;
    int yearOfPublication;

public:
    // Constructors
    Publisher();
    Publisher(std::string n, std::string c, int y);
    // Copy Constructor, Destructor
    Publisher(const Publisher& other);
    ~Publisher();


    string getName() const;
    string getCity() const;
    int getYearOfPublication() const;

    void setName(string n);
    void setCity(string c);
    void setYearOfPublication(int y);

    void changeName(const string& newName);
    void updateCity(const string& newCity);
    void printPublisherInfo() const;
    void setPublisherInfo();
    bool isOldPublisher() const;
};
#endif 
