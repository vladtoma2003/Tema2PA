#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#define INPATH "test"
#define OUTPATH "date.out"
#define INF 1000000000

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
Graph* citire3(std::ifstream& in) {
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
void printGraph3(Graph *g) {
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
* 
*/
std::vector<int> A_Star(Graph *g) {
    std::vector<int> distances(g->size+1, INF);
    distances[g->source] = 0;

    // functie lambda care compara 2 valori
    auto cmp = [](std::pair<int, int> left, std::pair<int, int> right) {
        return left.first > right.first;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q(cmp);

    q.push(std::make_pair(0, g->source));

    while(!q.empty()) {
        auto current = q.top();
        q.pop();

        int current_cost = current.first;
        int current_node = current.second;

        if(current_node == g->size) {
            break;
        }

        for(auto u : g->V[current_node]->neighbours) {
            int new_cost = distances[current_node] + u->cost;
            if(new_cost < distances[u->neighbour]) {
                distances[u->neighbour] = new_cost;
                int remaining_cost = u->cost + std::min(30, distances[u->neighbour]);
                q.push(std::make_pair(remaining_cost, u->neighbour));
            }
        }
    }

    return distances;
}

void task3() {
    for(int j = 1; j <= 10; ++j) {
        std::ifstream in(INPATH + std::to_string(j) + ".in");
        if (!in.is_open()) {
            std::cout << "Fisierul " << INPATH << " nu a putut fi deschis!\n";
            return;
        }

        std::ofstream out(OUTPATH + std::to_string(j));
        if (!out.is_open()) {
            std::cout << "Fisierul " << OUTPATH << " nu a putut fi deschis!\n";
            return;
        }

        auto g = citire3(in);

        // printGraph3(g);

        auto distances = A_Star(g);

        for (int i = 1; i <= g->size; ++i) {
            if (distances[i] == INF) {
                out << "-1 ";
            } else {
                out << distances[i] << " ";
            }
        }

        in.close();
        out.close();
    }
}
