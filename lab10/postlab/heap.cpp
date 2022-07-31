#include "heap.h"
#include "heapNode.h"
#include <iostream>
using namespace std;

heap::heap():list(101), size(0){}

int heap::getSize(){
  return size;
}
bool heap::isEmpty()
{
  if(size==0)
    return true;
  else
    return false;
}
void heap::insert(heapNode* a){
  if(size==list.size()-1)
    list.resize(list.size()*2);
  int hole=++size;
  for(; hole>1 && *a<*list[hole/2];hole/=2)
    list[hole]=list[hole/2];
  list[hole]=a;
}

void heap::deleteMin(){
  if(isEmpty())
    cout<<"heap is empty"<<endl;
  list[1]=list[size--];
  int hole=1;
  int child;
  heapNode* temp=list[hole];
  for(;hole*2<=size;hole=child){
    child=hole*2;
    if(child!=size && *list[child+1]<*list[child]){
      child++;
    }
    if(*list[child]<*temp){
      list[hole]=list[child];
    }
    else break;
  }
  list[hole]=temp;
}
    
heapNode* heap::findMin()
{
  return list[1];
}

vector<heapNode*> heap::getVect()
{
  return list;
}
