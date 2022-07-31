#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std; 
class HashTable{
 public:
  HashTable(int s); //Constructor 
  void insert(string word);
  vector<list<string> > table;
  bool checkWord(string word);
 private:
  int tableSize;
  int hashWord(string word);
};
#endif
