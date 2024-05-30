#include "Euler.h"
#include <utility>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

Euler::Euler(std::vector<std::vector<int>> consequentsList): consequentsList(std::move(consequentsList)) {
    /* this->consequentsList = vector<vector<int>>{{2, 10},
                                                 {1, 3},
                                                 {2, 4, 5, 10},
                                                 {3, 5, 6, 8},
                                                 {3, 4, 6, 7},
                                                 {4, 5, 7, 8},
                                                 {5, 6, 8, 10},
                                                 {4, 6, 7, 9},
                                                 {8, 10},
                                                 {1, 3, 7, 9}};*/
/*    this->consequentsList = vector<vector<int>>{{2},
                                                {1, 3},
                                                {2, 4, 5},
                                                {3, 6, 7, 8},
                                                {3, 7},
                                                {4, 8},
                                                {4, 5},
                                                {4, 6}};*/
    //this->consequentsList = vector<vector<int>> {{2,4}, {1,3}, {2,4}, {1,3}, {}};
}

void Euler::DFS(std::vector<bool> &visited, int node) {
    visited[node] = true;
    for (int consequent: consequentsList[node]) {
        if (!visited[consequent]) {
            DFS(visited, consequent);
        }
    }
}

bool Euler::areAllNodesConnected() {
    int graphSize = consequentsList.size();
    vector<bool> visited(graphSize, false);

    // Find a node with non-zero degree
    int startingNode = -1;
    for (int i = 0; i < graphSize; ++i) {
        if (!consequentsList[i].empty()) {
            startingNode = i;
            break;
        }
    }

    // If there are no edges in the graph, it is trivially connected
    if (startingNode == -1) {
        return true;
    }

    // Start DFS from a node with non-zero degree
    DFS(visited, startingNode);

    // Check if all node with non-zero degree are visited
    for (int i = 0; i < graphSize; ++i) {
        if (!consequentsList[i].empty() && !visited[i]) {
            return false;
        }
    }

    return true;
}

bool Euler::hasEulerianCycle() {
    if (!areAllNodesConnected()) {
        return false;
    }

    for (const auto &edges: consequentsList) {
        if (edges.size() % 2 != 0) {
            return false;
        }
    }

    return true;
}

std::vector<int> Euler::findEulerianCycle() {
    vector<int> cycle;
    if (!hasEulerianCycle()) {
        return cycle;
    }

    stack<int> path;
    vector<int> resultList;
    vector<vector<int>> list = consequentsList;

    path.push(1);
    int currentNodeIndex = 0;

    while (!path.empty()) {
        int currentNode = currentNodeIndex + 1;
        if (!list[currentNodeIndex].empty()) {

            int nextNode = list[currentNodeIndex][0];
            int nextNodeIndex = nextNode - 1;

            list[nextNodeIndex].erase(
                    find(list[nextNodeIndex].begin(), list[nextNodeIndex].end(), currentNode));

            list[currentNodeIndex].erase(list[currentNodeIndex].begin());
            currentNodeIndex = nextNodeIndex;
            path.push(currentNodeIndex + 1);
        } else {
            resultList.push_back(path.top());
            path.pop();
            if (!path.empty()) {
                currentNodeIndex = path.top() - 1;
            }

        }
    }

    reverse(resultList.begin(), resultList.end());
    return resultList;
}

void Euler::printCycle(const std::vector<int>& cycle) {
    if (!cycle.empty()){
        for(int node: cycle){
            cout<<node<<" ";
        }
    } else {
        cout<<"No Eulerian cycle found";
    }
    cout<<endl;
}
