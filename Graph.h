#pragma once
#include <string>
#include <vector>

class Graph {
private:
    int nodesAmount{};
    std::vector<std::vector<int>> consequentsList;

    void addEdgeList(int u, int i);
    void createGraphHamilton(int saturation);
    void createGraphNonHamilton(int vertex);

public:
    const static std::string argumentHamilton;
    const static std::string argumentNonHamilton;

    explicit Graph(const std::string& argument);

    std::vector<std::vector<int>>* getList();
};