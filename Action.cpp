#include "Action.h"
#include "Printer.h"
#include "Exporter.h"
#include "Euler.h"
#include "Hamilton.h"
#include <iostream>
#include <utility>
#include <iomanip>
#include <stack>

using namespace std;

Action::Action(Graph *graph, std::string argument) : graph(graph), argument(std::move(argument)) {}

int Action::handleAction() {
    string actionName;
    bool keepRunning = true;
    while (keepRunning) {
        cout << "action>";
        cin >> actionName;

        if (cin.eof()) {
            break;
        }

        int actionType = checkActionType(actionName);
        switch (actionType) {
            case 1: { //Help
                showHelp();
                break;
            }
            case 2: { //Print
                auto printer = Printer(graph);
                printer.print();
                break;
            }
            case 3: { //Euler
                auto *euler = new Euler(*graph->getList());
                vector<int> eulerCycle = euler->findEulerianCycle();
                Euler::printCycle(eulerCycle);
                delete euler;
                break;
            }
            case 4: { //Hamilton
                auto* hamilton = new Hamilton(*graph->getList());
                hamilton->hasHamiltonianCycle();
                delete hamilton;
                break;
            }
            case 5: { //Export
                auto *exporter = new Exporter(*graph->getList());
                exporter->exportToTikz();
                delete exporter;
                break;
            }
            case 6: {
                keepRunning = false;
                break;
            }
            default: {
                cout << "Invalid action. Type Help for action consequentsList.\n";
                break;
            }
        }
    }
    return 0;
}

int Action::checkActionType(const std::string &action) {
    if (action == "Help") {
        return 1;
    } else if (action == "Print") {
        return 2;
    } else if (action == "Euler") {
        return 3;
    } else if (action == "Hamilton") {
        return 4;
    } else if (action == "Export") {
        return 5;
    } else if (action == "Exit") {
        return 6;
    } else {
        return -1;
    }
}

void Action::showHelp() {
    int width = 15;
    cout << left;
    cout << setw(width) << "Help" << "Show this message\n";
    cout << setw(width) << "Printer" << "Printer the graph in chosen type\n";
    cout << setw(width) << "Euler" << "Finds the Euler cycle in graph\n";
    cout << setw(width) << "Hamilton" << "Finds the Hamilton cycle in graph\n";
    cout << setw(width) << "Export" << "Export the graph to tikzpicture\n";
    cout << setw(width) << "Exit" << "Exits the program\n";
}

