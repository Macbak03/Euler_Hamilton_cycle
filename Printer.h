#pragma once
#include "Graph.h"

class Printer {
private:
    Graph* graph;

public:
    explicit Printer(Graph* graph);
    void print();
};