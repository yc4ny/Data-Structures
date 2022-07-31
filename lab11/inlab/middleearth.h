#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
  /**
   *make private variables to hold the worlds
   */
  /*! the number of cities and the size of the world
    ...
  */
    int num_city_names, xsize, ysize;
    /*! vector of positions of the cities
    
    */
    vector<float> xpos, ypos;
    /*! vector of all the cities
    */
    vector<string> cities;
    /*! pointer to the distances of the cities
    */
    float *distances;
    /*! map of the positions of the cities
    */
    map<string, int> indices;

public:
    /**
     *MiddleEarth constructor that produces a world object
     */
    /*! @brief A constructor that builds the world
      @param xsize The size of the world from x
      @param ysize The size of the world from y
      @param num_cities the number of cities in the world
      @param seed random seed
    */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    /*! destructor                                                                         
     */
    ~MiddleEarth();
    /*! method that prints out the world                                                                         
     */
    void print();
    /*!prints out separated distances                                                                         
     */
    void printTable();
    /*! @brief a method that returns distance
      @param city1 name of city1
      @param city2 name of city2
     */
    float getDistance (string city1, string city2);
    /*! returns vector of strings of the roadmap                                                                         
     */
    vector<string> getItinerary(unsigned int length);
};

#endif
