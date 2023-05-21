# Calcularea Distanțelor Minime într-un Graf Orientat

Acest cod rezolvă problema calculării distanțelor minime într-un graf orientat ponderat. Citim datele de intrare din fișierul "date.in" și afișăm rezultatul în fișierul "date.out".

## Descrierea Problemei

Având un graf orientat ponderat, cu un număr de noduri și muchii, precum și o sursă dată, obiectivul este de a calcula distanțele minime de la sursă la toate celelalte noduri. Fișierul de intrare "date.in" are următorul format:
- N: Numărul de noduri din graf
- M: Numărul de muchii din graf
- S: Nodul sursă
- M linii, fiecare conținând o triplă de forma (nod_sursă, nod_destinație, cost), reprezentând o muchie în graf și costul asociat

Codul calculează distanțele minime de la sursă la toate celelalte noduri utilizând algoritmul Bellman-Ford și scrie rezultatul în fișierul de ieșire "date.out". Dacă nu există o cale de la sursă la un anumit nod, distanța corespunzătoare acelui nod va fi -1.

## Reprezentarea Grafului

Graful este reprezentat folosind o structură de date numită `Graph`. Fiecare nod din graf este reprezentat printr-o structură numită `node`, care conține următoarele informații:
- `value`: Valoarea nodului
- `color`: Culoarea nodului în timpul parcurgerii (0 - alb, 1 - gri, 2 - negru)
- `parent`: Nodul părinte în timpul parcurgerii
- `neighbours`: Un vector de structuri `vecin`, care conține informații despre vecinii nodului (nodul vecin și costul asociat)

Structura `vecin` conține următoarele informații:
- `neighbour`: Nodul vecin
- `cost`: Costul asociat muchiei către nodul vecin

## Funcții

### `Graph* citire(std::ifstream& in)`

Această funcție citește datele de intrare din fișier și construiește graful în consecință. Returnează un pointer către obiectul `Graph` creat.

### `void printGraph(Graph *g)`

Această funcție afișează graful. Este utilizată în scopuri de depanare.

### `void explore(Graph *g, int u, std::vector<int> *order)`

Această funcție explorează graful utilizând o parcurgere în adâncime (DFS). Adaugă nodurile în ordinea în care sunt terminate de DFS și verifică dacă există cicluri în graf.

### `std::vector<int> topSort(Graph *g)`

Această funcție realizează sortarea topologică a nodurilor grafului și returnează ordinea în care acestea trebuie parcurse pentru a calcula distanțele minime.

### `std::vector<int> getDistance(Graph *g)`

Această funcție calculează distanțele minime de la sursă la toate celelalte noduri utilizând sortarea topologică și algoritmul Bellman-Ford. Returnează un vector care conține distanța minimă către fiecare nod.

### `void problema2()`

Această funcție este punctul de intrare în program. Deschide fișierul de intrare, apelează funcția `citire` pentru a construi graful, calculează distanțele minime utilizând funcția `getDistance` și scrie rezultatul în fișierul de ieșire.

## Utilizare

1. Introduceți datele de intrare în fișierul "date.in" în formatul specificat.
2. Rulați codul.
3. Rezultatul, adică distanțele minime de la sursă la toate celelalte noduri, va fi scris în fișierul "date.out".

Puteți include acest fișier `README.md` împreună cu codul dvs. pentru a oferi o descriere a funcționalității programului și modul în care acesta poate fi utilizat.