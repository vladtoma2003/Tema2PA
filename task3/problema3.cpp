#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define INPATH "date.in"
#define OUTPATH "date.out"
#define INF 1000000000
#define MAX_COST 30

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
 * Functia asta este Bellman-Ford cu o optimizare:
 * Daca la o iteratie nu se modifica nimic, atunci nu mai are rost sa se continue
 * deoarece nu mai are ce sa se modifice.
*/
std::vector<int> optimizedBellman(Graph* graph) {
    std::vector<int> distances(graph->size + 1, INF);
    distances[graph->source] = 0;


    for (int i = 1; i < graph->size; ++i) {
        bool changed = false;
        for(int j = 1; j <= graph->size; ++j) {
            for(auto u : graph->V[j]->neighbours) {
                if(distances[j] != INF && distances[u->neighbour] > distances[j] + u->cost) {
                    distances[u->neighbour] = distances[j] + u->cost;
                    changed = true;
                }
            }
        }
        if(!changed) {
            break;
        }
    }

    return distances;
}

void problema3() {
        std::ifstream in(INPATH);
        if (!in.is_open()) {

            std::cout << "Fisierul " << INPATH << " nu a putut fi deschis!\n";
            return;
        }

        std::ofstream out(OUTPATH);
        if (!out.is_open()) {
            std::cout << "Fisierul " << OUTPATH << " nu a putut fi deschis!\n";
            return;
        }

        auto g = citire3(in);

//         printGraph3(g);

        auto distances = optimizedBellman(g);


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

