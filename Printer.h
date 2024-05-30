#pragma once
#include "Graph.h"

class Printer {
private:
    Graph* graph;

    void printMatrix();
    void printList();
    void printTable();
public:
    explicit Printer(Graph* graph);
    void print();
};