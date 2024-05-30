#include "Hamilton.h"
#include <iostream>
#include <algorithm>

using namespace std;

Hamilton::Hamilton(Graph *graph) : graph(graph){
    list = *graph->getList();
    nodesAmount = list.size();
}

void Hamilton::runHamiltonianCycleSearch(){
    vector<int> path(nodesAmount, -1);
    path[0] = 0;
    if (!searchHamiltonianCycle(path, 1)) {
        cout << "No Hamiltonian cycle found" << endl;
        return;
    }

    cout << "Hamiltonian cycle: ";
    for (int i = 0; i < nodesAmount; ++i) {
        cout << path[i] + 1 << " ";
    }
    cout << path[0] + 1 << endl;
}

bool Hamilton::searchHamiltonianCycle(vector<int> &path, int currentPathIndex){
    if (currentPathIndex == nodesAmount) {
        if (find(list[path[currentPathIndex - 1]].begin(), list[path[currentPathIndex - 1]].end(), path[0]) != list[path[currentPathIndex - 1]].end()) {
            return true;
        }
        return false;
    }

    for (int nextNode = 1; nextNode < nodesAmount; ++nextNode) {
        if (canAddToPath(nextNode, path, currentPathIndex)) {
            path[currentPathIndex] = nextNode;
            if (searchHamiltonianCycle(path, currentPathIndex + 1)) {
                return true;
            }
            path[currentPathIndex] = -1;
        }
    }
    return false;
}

bool Hamilton::canAddToPath(int nextNode, vector<int> &path, int currentPathIndex){
    if (find(list[path[currentPathIndex - 1]].begin(), list[path[currentPathIndex - 1]].end(), nextNode) == list[path[currentPathIndex - 1]].end()) {
        return false;
    }
    if (find(path.begin(), path.begin() + currentPathIndex, nextNode) != path.begin() + currentPathIndex) {
        return false;
    }
    return true;
}