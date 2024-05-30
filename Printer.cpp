#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer(Graph *graph) : graph(graph){}

void Printer::print() {
    cout<<"type>";
    cin>>graph->type;
    if (graph->type == "list") {
        printList();
    } else if (graph->type == "matrix") {
        printMatrix();
    } else if (graph->type == "table") {
        printTable();
    }
}

void Printer::printMatrix() {
    vector<vector<int>> matrix = *graph->getMatrix();
    cout<<"  | ";
    for(int i = 1; i<=matrix.size(); i++){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"--+-";
    for(int i = 1; i<2*matrix.size(); i++){
        cout<<"-";
    }
    cout<<endl;
    for (int i = 0; i<matrix.size(); i++) {
        cout<<i+1<<" | ";
        for (int j = 0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Printer::printList() {
    vector<vector<int>> list = *graph->getList();
    for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << " - ";
        for (int j: list[i]) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void Printer::printTable() {
    for (auto &edge: *graph->getTable()) {
        cout << "(" << edge.first + 1 << ", " << edge.second + 1 << ")" << endl;
    }
}