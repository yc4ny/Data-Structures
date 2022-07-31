#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);
/**
 *program runs and calculates traveling salesperson problem
 *from the 5 paramters passed in from the hobbits world. 
 *The program has a vector that has all the destinations and 
 *is then sort from the second destination to the last. The
 *program then goes through all the permuatations by using the other
 *methods and finds the shortest path and the shows the shortest path.
 */
int main (int argc, char **argv) {
  // check the number of parameters                                                  
  if ( argc != 6 ) {
    cout << "Usage: " << argv[0] << " <world_height> <world_width> "
	 << "<num_cities> <random_seed> <cities_to_visit>" << endl;
    exit(0);
  }
  // we'll assume the parameters are all well-formed                                 
  int width, height, num_cities, rand_seed, cities_to_visit;
  sscanf (argv[1], "%d", &width);
  sscanf (argv[2], "%d", &height);
  sscanf (argv[3], "%d", &num_cities);
  sscanf (argv[4], "%d", &rand_seed);
  sscanf (argv[5], "%d", &cities_to_visit);
  // Create the world, and select your itinerary                                     
  MiddleEarth me(width, height, num_cities, rand_seed);
  vector<string> dests = me.getItinerary(cities_to_visit);
  sort(dests.begin()+1,dests.end());                           
  string first = dests.at(0);
  float smallDist = computeDistance(me,first,dests);;
  float temp=0;
  vector<string> print = dests;                                                 
  while(next_permutation(dests.begin()+1,dests.end())){
    temp = computeDistance(me,first,dests);
    if(temp<smallDist){
      print = dests;
      smallDist = temp;
    }
  }
  first = print.at(0);
  cout<<"Smallest distance: "<<smallDist<<endl;
  printRoute(first,print);
  return 0;
}

/**
 * This method will compute the full distance of the cycle that starts                 
 * at the 'start' parameter, goes to each of the cities in the dests                   
  * vector IN ORDER, and ends back at the 'start' parameter.                            
  */
/**
 *computes the distance from the starting city to all the other cities and back
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {                         
  float dist=0.0;
  string begin = start;
  string last = dests.back();
  for(int i=0;i<dests.size();i++){
    dist+=me.getDistance(begin,dests.at(i));
    begin = dests.at(i);
  }
  dist +=me.getDistance(dests.at(0),last);
  return dist;
}

/**
 * This method will print the entire route, starting and ending at the
 * 'start' parameter.  The output should be of the form:                               
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor            
 */
void printRoute (string start, vector<string> dests) {                                                               
  bool print = false;
  for(int i=0;i<dests.size();i++){
    cout<< dests.at(i)<<" -> ";
  }
  cout<<start<<endl;
}
