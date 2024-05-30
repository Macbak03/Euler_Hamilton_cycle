#pragma once
#include <vector>


class Euler {
private:
    std::vector<std::vector<int>> consequentsList;

    void DFS(std::vector<bool>& visited, int node);
    bool areAllNodesConnected();
    bool hasEulerianCycle();
public:
    explicit Euler(std::vector<std::vector<int>> consequentsList);

    std::vector<int> findEulerianCycle();
    static void printCycle(const std::vector<int>& cycle);
};

