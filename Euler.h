#pragma once
#include <vector>
#include "Graph.h"


class Euler {
private:
    Graph* graph;
    std::vector<std::vector<int>> consequentsList;

    void DFS(std::vector<bool>& visited, int nodeIndex);
    bool areAllNodesConnected();
    bool hasEulerianCycle();
public:
    explicit Euler(std::vector<std::vector<int>> consequentsList);

    std::vector<int> findEulerianCycle();
    static void printCycle(const std::vector<int>& cycle);
};

