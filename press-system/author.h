#ifndef Author_h
#define Author_h
#include<iostream>
using namespace std;
class Author {
private:
    string name;
    int age;
    string gender;
    string cnic; // Assuming CNIC is a string
    int experience; // Years of experience

public:
    
    Author();
    Author(string n, int a, string g,string c, int e);
        Author(const Author& other);
    ~Author();

      string getName() const;
    int getAge() const;
    string getGender() const;
    string getCnic() const;
    int getExperience() const;
    void setName(string n);
    void setAge(int a);
    void setGender(string g);
    void setCnic(string c);
    void setExperience(int e);
    void setAuthorInfo();
    void printAuthor() const;
};
#endif
