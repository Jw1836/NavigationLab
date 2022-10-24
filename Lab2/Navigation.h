#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

#include "NavigationInterface.h"

using namespace std;

struct Node { // comparator function
    int cost;
    queue<int> path;

    bool operator() (Node const& n1, Node const& n2) {
        return n1.cost > n2.cost;
    }
};

class Navigation : public NavigationInterface {
public:
    Navigation() {};
    ~Navigation() {};

    // This function reads in the contents of the file _mapName.
    // The function can assume that the contents of the specified conform with the specs given in the README.txt file
    // Returns true if the file is read in successfully, false otherwise
    bool readNetwork(string _mapName);

    // This function computes and returns the least-cost path from node indexed _startInd to node indexed as _endInd
    // for the map that was last read (in the readMap function).  The resulting path must be stored in an integer queue
    // with each entry in the queue denoting the next node in the path.  First front of the queue should be _startInd
    // and the back of the queue should be _endInd.
    // For example, in map1.txt, solveMap(13, 1) should return the shortest path from node 13 to node 1, which is:
    //      13, 9, 10, 7, 3, 2, 1
    // You can assume that readNetwork(_mapName) is called before this function and that a path from _startInd to _endInd exists
    queue<int> computeShortestPath(int _startInd, int _endInd);

    // prints out to the console the path stored in _path
    void printPath(queue<int> _path);
private:
    int numNodes;
    vector < vector<int> > costsMatrix;


};

#endif