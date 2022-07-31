// This program shows how C-based file I/O works.  It will open a
// file, read in the first two strings, and print them to the screen.

// included so we can use cout
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

/**
 *A node that holds a pointer to the next course and its name
 */
struct courseNode{
  /**                                                                         
   * the name of the course                                                                         
   */
  string name;
  /**                                                                         
   * the total edges the node has                                                                         
   */
  int edges;
  /**                                                                         
   * the number of edges that are coming to the course                                                                          
   */
  int indegree;
  /**                                                                         
   * pointer to the next courses                                                                         
   */
  courseNode *next;
};
// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    string s1;
    /**
     *a vector of courseNodes
     */
    vector <courseNode*> courses;
    /**
     * loop goes through reading the whole file and saving as courseNodes      
     */
    /*! performs a topological sort on a file if possible
    ...
    */
    while(true){
      file >> s1;
       if(s1 == "0")
	 file >> s1;
       if(s1 == "0")
	  break;
       courseNode* c = new courseNode();
       for(int i =0;i<courses.size();i++){
	 if(courses.at(i)->name==s1){
	   stack <courseNode*> num;
	   c=courses.at(i)->next;
	   while(c){
	     num.push(c);
	     c=c->next;
	   }
	   file >> s1;
	   int in =0;
	   for(int j =0;j<courses.size();j++){
	     if(courses.at(j)->name==s1){
	       in = 1;
		 }
	   }
	   if(in == 0){
	     courseNode* z = new courseNode();
	     z->name = s1;
	     courses.push_back(z);
	   }
	   courseNode* d = new courseNode();
	   d->name = s1;
	   c = d;
	     while(num.size()!=0){
	       num.top()->next = c;
	       c = num.top();   
	       num.pop();
	     }
	   courses.at(i)->next = c;
	   break;
	 }
       }
       if(c->name==""){
	 c->name = s1;
	 file >> s1;
	 courseNode* d = new courseNode();
	 d->name = s1;
	 c->next = d;
	 courses.push_back(c);
	 int in =0;
	 for(int j =0;j<courses.size();j++){
	   if(courses.at(j)->name==s1){
	     in = 1;
	   }
	 }
	 if(in ==0){
	   courseNode* r = new courseNode();
	   r->name =s1;
	   courses.push_back(r);
	 }
       }
    }
    // string comparison done with ==, but not shown here
    // close the file before exiting
    file.close();
    courseNode* f;
    for(int i=0;i<courses.size();i++){
      f= courses.at(i)->next;
      while(f){
	f= f->next;
      }
    }
    int matrix[courses.size()][courses.size()];
    for(int i =0;i<courses.size();i++){
    for(int k=0;k<courses.size();k++){
	matrix[i][k]=0;
    }
    }
    for(int i=0;i<courses.size();i++){
	  stack<courseNode*> s;
	  courseNode* node = courses.at(i)->next;
	  while(node){
	    s.push(node);
	    node = s.top()->next;
	  }
	  while(s.size() !=0){
	    for(int k=0;k<courses.size();k++){
	      if(s.top()->name == courses.at(k)->name){
		matrix[i][k]=1;
	      }
	      if(i==k)
		matrix[i][k]=0;
	    }
	    s.pop();
	  }
    }
    int row =0;
    int col =0;
    int cou = 0;
    while(col<courses.size()){
      while(row<courses.size()){
	if(matrix[row][col]==1){
	  col++;
	  row=0;
	}
	else
	  row++;
      }
      cout<< courses.at(col)->name<<endl;
      for(int i=0;i<courses.size();i++){
	matrix[col][i]=0;
	matrix[i][col]=1;
      }
      cou++;
      if(cou<courses.size())
	col=0;
      else 
	break;
      row=0;
    }
    return 0;
}

