#include <iostream>
#include <string>
#include <queue>
#include "NavigationInterface.h"
#include "Navigation.h"

using namespace std;

extern void writeImage2File(queue<int> thePath, string _mapName);

// ********************************************
//
//  ./navigate [map] [startInd] [endInd]
//
// ********************************************
int main(int argc, char *argv[]) {

    // process the inputs from the command line
    if (argc < 4) {
        cout << "Not enough parameters" << endl;
        return 0;
    }

    string mapName = argv[1];
    int startInd = stoi(argv[2]);
    int endInd = stoi(argv[3]);

    cout << "Solving map " << mapName << " from Node " << startInd << " to Node " << endInd << endl;

    // instantiate an instance of the class you create (in Navigation.h and Navigation.cpp)
    NavigationInterface *nav = new Navigation();

    // make calls to functions in the Navigate class
    nav->readNetwork(mapName);
    queue<int> thePath = nav->computeShortestPath(startInd, endInd);
    nav->printPath(thePath);

    // make a call that creats a Map.bmp, which shows the shortest path computed through the road network
    writeImage2File(thePath, mapName);

    delete nav;

    return 0;
}






