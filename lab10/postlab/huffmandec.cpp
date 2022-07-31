// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "heapNode.h"
using namespace std;

void fixTree(heapNode* node,string code,char c);
char trav(heapNode* node, char bits);
// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    heapNode* root = new heapNode();
    
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        cout << "character '" << character << "' has prefix code '"
             << prefix << "'" << endl;
	fixTree(root,prefix,character[0]);
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits: " << allbits << endl;
   // close the file before exiting
    file.close();
    //decode message
    heapNode *k = root;
    string e="";
    for(int i=0;i<allbits.length();i++){
	if(allbits.at(i)=='1')
	  k=k->right;
	else if(allbits.at(i)=='0')
	  k=k->left;
	if(trav(k,allbits[i])=='\0'){}
      
      else{
	e+=trav(k,allbits[i]);
	k=root;
      }
    }
    cout<<"--------------------------------------"<<endl;
    cout<<e<<endl;
}
void fixTree(heapNode* node,string code,char c)
{
  int s = 0;
    if(code.at(s) == '1'){
      if(s==code.length()-1){
	heapNode *n = new heapNode(1,c);
	node->right = n;
      }
      else{
	if(node->right==NULL){
	  heapNode *n = new heapNode();
	  node->right = n;
	}
	code = code.substr(1,code.length());
	fixTree(node->right,code,c);
      }
    }
    else if(code.at(s) == '0'){
      if(s==code.length()-1){
        heapNode *n = new heapNode(1,c);
	node->left = n;
      }
      else{
	if(node->left==NULL){
          heapNode *n = new heapNode();
          node->left = n;
        }
	code = code.substr(1,code.length());
        fixTree(node->left,code,c);
      }
    }
}
char trav(heapNode* node, char bits)
{
  int s =0;
  if(bits=='1'){
  if(node->right==NULL)
    return node->getAlpha();
  else
    return '\0';
  }
else{
  if(node->left==NULL)
    return node->getAlpha();
  else
    return '\0';
		    }
}
