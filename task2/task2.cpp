#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#define INPATH "date.in"
#define OUTPATH "date.out"

typedef struct vecin {
    int neighbour;
    int cost;
}vecin;

typedef struct node {
    int value;
    int color;
    int parent;
    std::vector<vecin*> neighbours;
}node;

typedef struct graph {
    std::vector<node*> V;
    int size;
    int source;
}Graph;

/*
 * Functia asta functioneaza asemanator cu cea din task1.
 * Singura diferenta este ca aici se citeste si costul.
 * In plus, se salveaza si sursa.
 */
Graph* citire(std::ifstream& in) {
    auto g = new Graph;
    in >> g->size;
    int m;
    in >> m;
    in >> g->source;

    g->V.resize(g->size+1);

    for(int i = 1; i <= g->size; ++i) {
        g->V[i] = new node;
        g->V[i]->value = i;
        g->V[i]->color = 0;
        g->V[i]->parent = -1;
    }


    std::string line;
    std::getline(in, line);

    while(std::getline(in, line)) {
        std::istringstream ss(line);
        std::string word;
        std::vector<int> v;

        while(ss >> word) {
            v.push_back(std::stoi(word));
        }

        auto vec = new vecin;
        vec->neighbour = v[1];
        vec->cost = v[2];
        g->V[v[0]]->neighbours.push_back(vec);

    }

    return g;
}

/*
 * Functia asta afiseaza graful. Este folosita doar pentru debugging.
 */
void printGraph(Graph *g) {
    std::cout << "no. of nodes:" << g->size << std::endl;
    for(int i = 1; i <= g->size; ++i) {
        std::cout << i << ":";
        for(auto u : g->V[i]->neighbours) {
            std::cout << u->neighbour << "(" << u->cost << ") ";
        }
        std::cout << std::endl;
    }
}

/*
 * Functia asta exploreaza graful si adauga nodurile in ordinea
 * in care sunt terminate de DFS.
 */
void explore(Graph *g, int u, std::vector<int> *order) {
    g->V[u]->color = 1;
    for(auto v : g->V[u]->neighbours) {
        if(g->V[v->neighbour]->color == 0) {
            explore(g, v->neighbour, order);
        }
    }
    order->push_back(u);
    g->V[u]->color = 2;
}

/*
 * Functia asta sorteaza topologic nodurile.
 * Este folosita pentru a calcula distantele minime.
 * Este functia de sortare topologica data la curs.
 */
std::vector<int> topSort(Graph *g) {
    std::vector<int> order;
    for(int i = 1; i <= g->size; ++i) {
        if(g->V[i]->color == 0) {
            explore(g, i, &order);
        }
    }
    std::reverse(order.begin(), order.end());
    return order;
}

/*
 * Functia asta calculeaza distantele minime.
 * Se foloseste de sortarea topologica.
 */
std::vector<int> getDistance(Graph *g) {
    std::vector<int> order = topSort(g);
    std::vector<int> distance(g->size+1, INT_MAX);

    distance[g->source] = 0;

    for(auto u : order) {
        for(auto v : g->V[u]->neighbours) {
            distance[v->neighbour] = std::min(distance[v->neighbour], distance[u] + v->cost);
        }
    }

    return distance;

}

void task2() {
    std::ifstream in(INPATH);
    if(!in.is_open()) {
        std::cout << "Could not open file!" << std::endl;
        return;
    }

    Graph *g = citire(in);
//    printGraph(g);

    auto distance = getDistance(g);
    std::ofstream out(OUTPATH);
    if(!out.is_open()) {
        std::cout << "Could not open file!" << std::endl;
        return;
    }

    for(int i = 1; i <= g->size; ++i) {
        out << distance[i] << " ";
    }

}