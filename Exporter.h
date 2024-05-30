#pragma once
#include <vector>


class Exporter {
private:
    std::vector<std::vector<int>> consequentsList;
public:
    explicit Exporter(std::vector<std::vector<int>> consequentsList);
    void exportToTikz();
};
