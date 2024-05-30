#include "Exporter.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <random>

using namespace std;

Exporter::Exporter(std::vector<std::vector<int>> consequentsList) : consequentsList(std::move(consequentsList)){}

void Exporter::exportToTikz() {
    int listSize = consequentsList.size();
    ofstream file("Graph.tex");

    if (!file.is_open()) {
        cout << "Error: Cannot open file." << endl;
        return;
    }

    file << "\\input{name}\n";
    file << "\\documentclass{standalone}\n";
    file << "\\usepackage{tikz}\n";
    file << "\\begin{document}\n";
    file << "\\begin{tikzpicture}\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(1.0, 10.0);

    for (int i = 0; i < listSize; ++i) {
        double offsetY = dis(gen);
        file << "\\node[shape=circle,draw=black] (" << i + 1 << ") at (" << i * 2 << "," << offsetY << ") {" << i + 1 << "};\n";
    }

    for (int i = 0; i < listSize; ++i) {
        for (int j : consequentsList[i]) {
            file << "\\path [-](" << i + 1 << ") edge (" << j + 1 << ");\n";
        }
    }

    file << "\\end{tikzpicture}\n";
    file << "\\end{document}\n";

    file.close();

    cout << "Graph has been exported to TikZ." << endl;
}
