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
 * Folosind sortarea topologica, calculez distanta minima de la sursa la fiecare nod.
 * Functia returneaza un vector de intregi, unde pe pozitia i se afla distanta de la sursa la nodul i.
 * Daca nu exista drum de la sursa la nodul i, atunci distanta va fi INT_MAX(infinit).
 * Daca exista drum, atunci distanta va fi cea minima.
 */
int *getDistance(Graph *g) {
    auto distance = new int[g->size+1];
    for(int i = 1; i <= g->size; ++i) {
        distance[i] = INT_MAX; // initializez vectorul de distance cu inf
    }

    distance[g->source] = 0; // distanta de la sursa la sursa este 0

    std::vector<int> in_degree(g->size+1, 0); // vectorul de grade de intrare
    for(int i = 1; i <= g->size; ++i) {
        for(auto u : g->V[i]->neighbours) {
            in_degree[u->neighbour]++; // incrementez gradele de intrare
        }
    }

    std::queue<int> q;
    for(int i = 1; i <= g->size; ++i) {
        if(in_degree[i] == 0) {
            q.push(i); // adaug in coada nodurile cu gradul de intrare 0
        }
    }
    std::vector<int> order;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(auto v : g->V[u]->neighbours) {
            in_degree[v->neighbour]--;
            if(in_degree[v->neighbour] == 0) {
                q.push(v->neighbour);
            }
        }
    }

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