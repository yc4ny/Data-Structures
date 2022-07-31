#include <iostream>
#include <algorithm>
#include "heap.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;
void printCode(heapNode* n,string c,map<char,string> &m);
int main(int argc,char* argv[])
{
  if(argc != 2)
    {
      return 1;
    }
  string file = argv[1];
  FILE *fp = fopen(argv[1], "r");
  // if the file wasn't found, output and error message and exit
  if ( fp == NULL ) {
    cout << "File '" << argv[1] << "' does not exist!" << endl;
    exit(2);
  }
  // read in each character, one by one.  Note that the fgetc() will
  // read in a single character from a file, and returns EOF when it
  // reaches the end of a file.
  char g;
  vector<char> v;
  vector<int> f;
  vector<char> orig;
  while ( (g = fgetc(fp)) != EOF ){
    v.push_back(g);
  }
  v.pop_back();
  orig=v;
  // rewinds the file pointer, so that it starts reading the file
  // again from the begnning
  rewind(fp);
  fclose(fp);
  f.push_back(1);
  std::sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    if(i+1!=v.size() &&  v.at(i)==v.at(i+1)){
      int tot = f.back()+1;
      f.pop_back();
      f.push_back(tot);
      
    }
    else if(i!=0){
      f.push_back(1);
    }
  }
  if(f.back()==1)
    f.pop_back();
  heap h;
  int c=0;
  for(int i=0;i<f.size();i++){
    c+=f.at(i);
    heapNode* num= new heapNode(f.at(i),v.at(c-1));
    h.insert(num);
  }
  int s =1;
  while(s<h.getSize()){
    heapNode* q = new heapNode();
    q->left = h.findMin();
    h.deleteMin();
    q->right = h.findMin();
    h.deleteMin();
    int a= q->left->getCount()+q->right->getCount();
    q->setCount(a);
    h.insert(q);
  }
  string code="";
  map<char,string> look;
  printCode(h.findMin(),code,look);
  // a nice pretty separator                                                 
  cout << "----------------------------------------" << endl;
  map<char,string>::iterator it;
  int nbits = 0;
  for(int i =0;i<orig.size();i++){
    it= look.find(orig.at(i));
    cout<<it->second<<"\n";
    nbits+=it->second.length();
  }
  cout << "----------------------------------------" << endl;
  int obits = 8*orig.size();
  cout<<"Compression ratio of "<<(double)obits/nbits<<"\n";
  double cost=((double)nbits)/orig.size();
  cout<<"The cost of the huffman tree is "<<cost<<" "<<"bits per character."<<"\n";
  return 0;
}
string traverseCode(vector<int> v);
void printCode(heapNode* n,string c,map<char,string> &m)
{
  if(!n)
    return;
  if(n->left==NULL && n->right==NULL){
    if(n->getAlpha()==32)
      cout<<"space "<< c<<"\n";
    else
    cout<<n->getAlpha()<<" "<< c<<"\n";
    m[n->getAlpha()]=c;
  }
  printCode(n->left,c+"0",m);
  printCode(n->right,c+"1",m);
}
string traverseCode(vector<int> v)
{
  string code = "";
  for(int i=0;i<v.size();i++){
    code+=v.at(i);
  }
  return code;
}
