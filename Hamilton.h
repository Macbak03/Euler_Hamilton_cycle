#pragma once
#include "Graph.h"
#include <vector>

class Hamilton {
private:
    Graph* graph;
    std::vector<std::vector<int>> consequentsList;
    int nodesAmount;

    bool canAddToPath(int nextNode, const std::vector<int>& path, int currentPathIndex);
    bool searchHamiltonianCycle(std::vector<int> &path, int currentPathIndex);
public:
    explicit Hamilton(std::vector<std::vector<int>> consequentsList);

    void hasHamiltonianCycle();
};