#include "hashTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
HashTable::HashTable(int s)
{
  tableSize = s;
  list<string> list;
  for(int i=0; i<tableSize;i++)
    table.push_back(list);
}

int hashWord(string word);
void HashTable::insert(string word)
{
  if(word.length() >= 3){
    int index = hashWord(word);
    table[index].push_back(word);
  }
}
bool HashTable::checkWord(string word)
{
  int index = hashWord(word);
  if(table[index].front() == word)
    return true;
  else{
    list<string>::iterator i = table[index].begin();
    while(*i!=word && i!=table[index].end()){
      ++i;
    }
    if(*i == word){
      return true;}
    else
      return false;
  }
}
int HashTable::hashWord(string word)
{
  unsigned long long hash = 0;
  int index = 0;
  unsigned long long pow = 1;
  for(int i = 0;i<word.length();i++){
    hash += ((int)word[0])*pow;
    pow*=3;
  }
  index = hash % tableSize;
  return index;
}
