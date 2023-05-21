#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#define INPATH "date.in"
#define OUTPATH "date.out"

/*
 * WHIE - 0
 * GRAY - 1
 * BLACK - 2
 */
typedef struct node {
    int value;
    int color;
    int parent;
    std::vector<int> neighbours;
}node;

/*
 * E - vecini
 * size - nr de noduri
 */
typedef struct graph {
    std::vector<node*> V;
    int size;
}Graph;

/* 
 * In functia asta se citesc datele date din fisierul "date.in"
 * si se construieste graful astfel:
 * Graful este format din:
 * -> un vector de noduri
 * -> nr de noduri.
 * Fiecare nod are:
 * -> un vector de vecini
 * -> o culoare
 * -> un parinte
 * -> o valoare
 *
 */
Graph *citire_noCost(std::ifstream &in) {
    auto g = new Graph;

    in >> g->size;
    int m;
    in >> m;

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

        g->V[v[0]]->neighbours.push_back(v[1]);
    }

    return g;
}

/*
 * Functie care afiseaza nr de noduri si vecinii fiecarui nod.
 * Functia asta a fost folosita la debugging.
 */
void printGraph1(Graph *g) {
    std::cout << "no. of nodes:" << g->size << std::endl;
    for(int i = 1; i < g->V.size(); ++i) {
        std::cout << g->V[i]->value << ":";
        for(auto j: g->V[i]->neighbours) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

/*
 * Functie recursiva care exploreaza graful.
 * Daca un nod are culoarea 1(gri), atunci inseamna ca a fost vizitat
 * si se intoarce 1, adica graful are ciclu. Daca un nod are culoarea 0
 * (alb), atunci se apeleaza recursiv functia pe vecinii lui.
 */
int explore(Graph *g, node *u) {
    u->color = 1;
    for(auto v : u->neighbours) {
        if(g->V[v]->color == 0) {
            g->V[v]->parent = u->value;
            if(explore(g, g->V[v]) == 1) {
                return 1; // ciclu
            }
        } else if(g->V[v]->color == 1) {
            return 1; // ciclu
        }
    }
    u->color = 2;
    return 0; // nu ciclu
}

/*
 * Se cheama explore pe toate nodurile din graf
 */
int hasCycle(Graph *g) {
    // nodurile sunt deja initializate
    for (int i = 1; i < g->V.size(); ++i) {
        auto u = g->V[i];
        if (u->color == 0) {
            if (explore(g, u) == 1) {
                return 1; // ciclu
            }
        }
    }
    return 0;
}

/*
 * Aici se citesc datele, si se apeleaza functiile.
 */
void problema1() {
    std::ifstream in(INPATH);
    if (!in.is_open()) {
        std::cout << "Could not open file!" << std::endl;
        return;
    }

    auto g = citire_noCost(in);
//    printGraph1(g);

    std::ofstream out(OUTPATH);
    if (!out.is_open()) {
        std::cout << "Could not open file!" << std::endl;
        return;
    }

    if (hasCycle(g)) {
        out << "are ciclu";
    } else {
        out << "nu are ciclu";
    }

    in.close();
    out.close();
}
