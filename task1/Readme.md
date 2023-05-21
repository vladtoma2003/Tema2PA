# Detectarea Ciclurilor în Graf

Acest cod rezolvă problema detectării ciclurilor într-un graf orientat. Citim datele de intrare din fișierul "date.in" și afișăm rezultatul în fișierul "date.out".

## Descrierea Problemei

Având un graf orientat arbitrar (care poate conține cicluri), obiectivul este de a determina dacă graful conține sau nu cicluri. Fișierul de intrare "date.in" are următorul format:
- N: Numărul de noduri din graf
- M: Numărul de muchii din graf
- M linii, fiecare conținând o pereche de noduri reprezentând o muchie în graf

Codul verifică dacă graful conține cicluri și scrie rezultatul în fișierul de ieșire "date.out". Dacă graful conține un ciclu, se afișează "are ciclu"; în caz contrar, se afișează "nu are ciclu".

## Reprezentarea Grafului

Graful este reprezentat folosind o structură de date numită `Graph`. Fiecare nod din graf este reprezentat printr-o structură numită `node`, care conține următoarele informații:
- `value`: Valoarea nodului
- `color`: Culoarea nodului în timpul parcurgerii (0 - alb, 1 - gri, 2 - negru)
- `parent`: Nodul părinte în timpul parcurgerii
- `neighbours`: Un vector de întregi care reprezintă nodurile vecine

## Funcții

### `Graph *citire_noCost(std::ifstream &in)`

Această funcție citește datele de intrare din fișier și construiește graful în consecință. Returnează un pointer către obiectul `Graph` creat.

### `void printGraph1(Graph *g)`

Această funcție afișează numărul de noduri și vecinii fiecărui nod din graf. Este utilizată în scopuri de depanare.

### `int explore(Graph *g, node *u)`

Această funcție recursivă explorează graful. Dacă un nod are culoarea 1 (gri), înseamnă că a fost vizitat și returnează 1, indicând prezența unui ciclu. Dacă un nod are culoarea 0 (alb), funcția este apelată recursiv pe vecinii săi.

### `int hasCycle(Graph *g)`

Această funcție apelează funcția `explore` pe toate nodurile din graf și returnează 1 dacă este detectat un ciclu și 0 în caz contrar.

### `void problema1()`

Această funcție citește datele de intrare, apelează funcțiile necesare și scrie rezultatul în fișierul de ieșire.

## Utilizare

1. Introduceți datele de intrare în fișierul "date.in" în formatul specificat.
2. Rulați codul.
3. Rezultatul va fi scris în fișierul "date.out".