#include "Hamilton.h"
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

Hamilton::Hamilton(vector<vector<int>> consequentsList) : consequentsList(std::move(consequentsList)){
    nodesAmount = this->consequentsList.size();
}

bool Hamilton::canAddToPath(int nextNode, const vector<int>& path, int currentPathIndex) {
    if (find(path.begin(), path.begin() + currentPathIndex, nextNode) != path.begin() + currentPathIndex) {
        return false;
    }
    if (find(consequentsList[path[currentPathIndex - 1] - 1].begin(), consequentsList[path[currentPathIndex - 1] - 1].end(), nextNode) == consequentsList[path[currentPathIndex - 1] - 1].end()) {
        return false;
    }
    return true;
}

bool Hamilton::searchHamiltonianCycle(vector<int>& path, int currentPathIndex) {
    if (currentPathIndex == nodesAmount) {
        if (find(consequentsList[path[currentPathIndex - 1] - 1].begin(), consequentsList[path[currentPathIndex - 1] - 1].end(), path[0]) != consequentsList[path[currentPathIndex - 1] - 1].end()) {
            return true;
        }
        return false;
    }

    for (int nextNode = 1; nextNode <= nodesAmount; ++nextNode) {
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

void Hamilton::hasHamiltonianCycle() {
    vector<int> path(nodesAmount, -1);
    path[0] = 1;
    if (!searchHamiltonianCycle(path, 1)) {
        cout << "No Hamiltonian cycle found" << endl;
        return;
    }

    cout << "Hamiltonian cycle: ";
    for (int i = 0; i < nodesAmount; ++i) {
        cout << path[i] << " ";
    }
    cout << path[0] << endl;
}