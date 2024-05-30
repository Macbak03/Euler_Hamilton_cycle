#include <iostream>
#include "Graph.h"
#include "Action.h"

int main() {

    Graph graphHamilton(Graph::argumentHamilton);
    //Graph graphNonHamilton(Graph::argumentNonHamilton);
    //Action action(&graphNonHamilton, Graph::argumentNonHamilton);
    Action action(&graphHamilton, Graph::argumentHamilton);
    action.handleAction();

    return 0;
}