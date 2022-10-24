//
// Created by jesse on 9/27/2022.
//


#include "Navigation.h"

using namespace std;


// Navigation :: Navigation() {
//     cout << "This is the constructor" << endl;
// }
// Navigation :: ~Navigation() {
//     cout << "This is the deconstructor" << endl;
// }



bool Navigation :: readNetwork(string _mapName){
    cout << "reading the network file." << endl;
    ifstream in;
    string trash1;
    int trash2;
    in.open(_mapName);
    in >> trash1;
    numNodes = stoi(trash1);
    // check for getline to clear
    if(!in.is_open()){
        cout << "fail to open file" << endl;
        exit(-1);
    }
    else{

        for(int i = 0; i < numNodes; i++){

            vector<int> cost1;
            for(int j = 0; j < numNodes; j++){
                in >> trash2;
                cost1.push_back(trash2);
            }

            costsMatrix.push_back(cost1);

        }
        for(int i = 0; i < costsMatrix.size(); i++){
            for(int j = 0; j < costsMatrix.size(); j++){
                cout << costsMatrix[i][j] << " " ;
            } cout << endl;
        }
        return true;
    }
}






queue<int> Navigation :: computeShortestPath(int _startInd, int _endInd){
    queue<int> thePath;
    priority_queue<Node, vector<Node>, Node> PQ;
    // create node n with n.cost = 0, n.path = a
    cout << "This is compute shortest function" << endl;
    Node n;
    n.cost = 0;
    n.path.push(_startInd);
    PQ.push(n);

    cout << "entering while loop" << endl;
    while(PQ.top().path.back() != _endInd){
        Node current;
        current = PQ.top();
        PQ.pop();
        int lastOne = current.path.back();

        for(int i = 0; i < numNodes; i++){
            if(costsMatrix[lastOne][i] > 0) {
                Node nn;
                nn.cost = current.cost + costsMatrix[lastOne][i];
                nn.path = current.path;
                nn.path.push(i);
                PQ.push(nn);


            }
        }
        if(PQ.empty()){
            return PQ.top().path;
        }
    }

    return PQ.top().path;

}

// prints out to the console the path stored in _path
void Navigation :: printPath(queue<int> _path){

    while(!_path.empty()){
        cout << _path.front() << endl;
        _path.pop();
    }

}