#include <iostream>
#include <string>
using namespace std;
#ifndef LIFECYCLE_H
#define LIFECYCLE_H

  // ---------------------------------------------------  class definition
  class MyObject {
  public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor
    string getName() const;
    void setName(const string newName);
    friend ostream& operator<<(ostream& output, const MyObject& obj);
  private:
    string name;
    int id;
  };
#endif
