#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(Graph *graph) : graph(graph){}

void Printer::print() {
    vector<vector<int>> list = *graph->getList();
    for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << " - ";
        for (int j: list[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}