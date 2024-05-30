#include <iostream>
#include "Graph.h"
#include "Action.h"
#include "InvalidDataException.h"

using namespace std;

int main(int argc, char *argv[]) {
    Graph *graph;
    if (argc == 2 && string(argv[1]) == Graph::argumentHamilton) {
        try {
            graph = new Graph(Graph::argumentHamilton);
        } catch (InvalidDataException &exception) {
            cerr << exception.what() << endl;
            return 1;
        }
    } else if (argc == 2 && string(argv[1]) == Graph::argumentNonHamilton) {
        try {
            graph = new Graph(Graph::argumentNonHamilton);
        } catch (InvalidDataException &exception) {
            cerr << exception.what() << endl;
            return 1;
        }
    } else {
        cerr << "Invalid argument";
        return 1;
    }


    Action action(graph, argv[1]);
    action.handleAction();

    return 0;
}