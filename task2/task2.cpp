#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define PATH "date.in"

typedef struct graph {
    std::vector<std::vector<int>> E;
    int size;
    int source;
}Graph;

Graph* citire(std::ifstream& in) {
    auto g = new Graph;
    in >> g->size;
    int m;
    in >> m;
    in >> g->source;

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
    for(int i = 0; i < g->size; ++i) {
        for(int j = 0; j < 3; ++j) {
            std::cout << g->E[i][j] << " ";
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

    Graph *g = citire(in);
    printGraph(g);

    return 0;
}

//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//const int INF = 1000000000;
//const int MAXN = 5005;
//
//int n, m, s;
//int a[MAXN][MAXN], dist[MAXN];
//
//void read_input() {
//    ifstream fin("date.in");
//    fin >> n >> m >> s;
//
//    // initializam matricea de adiacenta cu valoarea infinit
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            a[i][j] = INF;
//        }
//    }
//
//    // citim perechile de arce si costurile corespunzatoare
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        fin >> u >> v >> w;
//        a[u][v] = w;
//    }
//
//    fin.close();
//}
//
//void floyd_warshall() {
//    // initializam matricea de distante cu valorile initiale
//    for (int i = 1; i <= n; i++) {
//        dist[i] = a[s][i];
//    }
//    dist[s] = 0;
//
//    // aplicam algoritmul Floyd-Warshall
//    for (int k = 1; k <= n; k++) {
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (dist[i] != INF && dist[i] + a[i][j] < dist[j]) {
//                    dist[j] = dist[i] + a[i][j];
//                }
//            }
//        }
//    }
//}
//
//void write_output() {
//    ofstream fout("date.out");
//    for (int i = 1; i <= n; i++) {
//        fout << dist[i] << " ";
//    }
//    fout.close();
//}
//
//int main() {
//    read_input();
//    floyd_warshall();
//    write_output();
//    return 0;
//}