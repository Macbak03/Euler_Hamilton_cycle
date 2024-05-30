#pragma once
#include <string>
#include <vector>

class Graph {
private:
    int nodesAmount{};
    std::vector<std::vector<int>> matrix;
    std::vector<std::pair<int, int>> table;
    std::vector<std::vector<int>> consequentsList;

    void addEdgeList(int u, int i);
    void createGraphHamilton(int saturation);
    void createGraphNonHamilton(int vertex);

    void createTableFromList();
    void createMatrixFromList();
public:
    const static std::string argumentHamilton;
    const static std::string argumentNonHamilton;
    std::string type;

    explicit Graph(const std::string& argument);

    std::vector<std::vector<int>>* getList();
    std::vector<std::vector<int>>* getMatrix();
    std::vector<std::pair<int, int>>* getTable();
};