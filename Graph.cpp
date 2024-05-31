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

    // Create a Hamiltonian path by connecting each node to the next one
    for (int i = 1; i < nodesAmount; ++i) {
        addEdgeList(i, i + 1);
    }
    // Close the cycle by connecting the last node to the first node
    addEdgeList(nodesAmount, 1);

    numberOfEdges -= nodesAmount;  // We already added nodesAmount edges

    // Add random edges until we reach the desired saturation
    while (numberOfEdges > 0) {
        int node = rand() % nodesAmount + 1;
        int consequent = rand() % nodesAmount + 1;
        if (node != consequent) {
            bool exist = false;
            for (int neighbor : consequentsList[node - 1]) {
                if (neighbor == consequent) {
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                addEdgeList(node, consequent);
                numberOfEdges--;
            }
        }
    }
}

void Graph::addEdgeList(int node, int neighbor) {
    consequentsList[node - 1].push_back(neighbor);    // Adjust for 0-based indexing
    consequentsList[neighbor - 1].push_back(node);    // Adjust for 0-based indexing
}

void Graph::createGraphNonHamilton(int vertex) {
    consequentsList[vertex].clear();
    for (auto &neighbors: consequentsList) {
        neighbors.erase(remove(neighbors.begin(), neighbors.end(), vertex+1), neighbors.end());
    }
}

std::vector<std::vector<int>> *Graph::getList() {
    return &consequentsList;
}
