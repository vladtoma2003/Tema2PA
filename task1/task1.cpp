#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#define PATH "date.in"

typedef struct graph {
    std::vector<std::vector<int>> E;
    int size;
}Graph;

Graph *citire_noCost(std::ifstream &in) {
    auto g = new Graph;

    in >> g->size;
    int m;
    in >> m;

    std::string line;
    std::getline(in, line);

    while(std::getline(in, line)) {
        std::istringstream ss(line);
        std::string word;
        std::vector<int> v;

        while(ss >> word) {
            v.push_back(std::stoi(word));
        }

        g->E.push_back(v);
    }

    return g;
}

void printGraph(Graph *g) {
    for(auto i : g->E) {
        for(auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ifstream in(PATH);
    if(!in.is_open()) {
        std::cout << "Could not open file!" << std::endl;
        return 1;
    }

    auto g = citire_noCost(in);
    printGraph(g);

    // sortare topologica

    return 0;
}