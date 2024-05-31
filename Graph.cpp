#include "Graph.h"
#include "InvalidDataException.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>


using namespace std;


const std::string Graph::argumentHamilton = "--hamilton";
const std::string Graph::argumentNonHamilton = "--non-hamilton";

Graph::Graph(const string &argument) {
    cout << "nodes>";
    cin >> nodesAmount;
    if(nodesAmount<1){
        throw InvalidDataException("nodes amount cannot be less than 1");
    }
    cin.ignore();

    consequentsList = vector<vector<int>>(nodesAmount);

    int saturation = 0;

    if (argument == argumentNonHamilton) {
        saturation = 50;
        createGraphHamilton(saturation);
        createGraphNonHamilton(rand() % nodesAmount);
    } else if (argument == argumentHamilton) {
        cout << "saturation>";
        cin >> saturation;
        if(saturation != 30 && saturation != 70){
            throw InvalidDataException("saturation must be 30 or 70");
        }
        createGraphHamilton(saturation);
    }

}

void Graph::createGraphHamilton(int saturation) {
    int maxEdges = nodesAmount * (nodesAmount - 1) / 2;
    int numberOfEdges = maxEdges * saturation / 100;

    srand(time(nullptr));

    for (int i = 1; i < nodesAmount; ++i) {
        int u = rand() % i;
        addEdgeList(u, i);
    }

    while (numberOfEdges > nodesAmount - 1) {
        int u = rand() % nodesAmount;
        int v = rand() % nodesAmount;
        if (u != v) {
            bool exist = false;
            for (int neighbor: consequentsList[u]) {
                if (neighbor == v) {
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                addEdgeList(u, v);
                numberOfEdges--;
            }
        }
    }
}

void Graph::addEdgeList(int u, int v) {
    consequentsList[u].push_back(v);
    consequentsList[v].push_back(u);
}

void Graph::createGraphNonHamilton(int vertex) {
    consequentsList[vertex].clear();
    for (auto &neighbors: consequentsList) {
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), vertex), neighbors.end());
    }
}

std::vector<std::vector<int>> *Graph::getList() {
    return &consequentsList;
}
