#pragma once
#include "Graph.h"
#include <vector>

class Hamilton {
private:
    Graph* graph;
    std::vector<std::vector<int>> list;
    int nodesAmount;

    bool canAddToPath(int nextNode, std::vector<int> &path, int currentPathIndex);
    bool searchHamiltonianCycle(std::vector<int> &path, int currentPathIndex);
public:
    explicit Hamilton(Graph* graph);

    void runHamiltonianCycleSearch();
};