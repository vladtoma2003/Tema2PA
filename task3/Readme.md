# Calcularea Distanțelor Minime într-un Graf Orientat Ponderat - Optimizare Bellman-Ford

Acest cod rezolvă problema calculării distanțelor minime într-un graf orientat ponderat. Citim datele de intrare din fișierul "date.in" și afișăm rezultatul în fișierul "date.out". Algoritmul utilizat este o optimizare a algoritmului Bellman-Ford.

## Descrierea Problemei

Având un graf orientat ponderat, cu un număr de noduri și muchii, precum și o sursă dată, obiectivul este de a calcula distanțele minime de la sursă la toate celelalte noduri. Fișierul de intrare "date.in" are următorul format:
- N: Numărul de noduri din graf
- M: Numărul de muchii din graf
- S: Nodul sursă
- M linii, fiecare conținând o triplă de forma (nod_sursă, nod_destinație, cost), reprezentând o muchie în graf și costul asociat

Codul calculează distanțele minime de la sursă la toate celelalte noduri utilizând o optimizare a algoritmului Bellman-Ford. Dacă nu există o cale de la sursă la un anumit nod, distanța corespunzătoare acelui nod va fi -1.

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

### `Graph* citire3(std::ifstream& in)`

Această funcție citește datele de intrare din fișier și construiește graful în consecință. Returnează un pointer către obiectul `Graph` creat.

### `void printGraph3(Graph *g)`

Această funcție afișează graful. Este utilizată în scopuri de depanare.

### `std::vector<int> optimizedBellman(Graph* graph)`

Această funcție aplică algoritmul Bellman-Ford pentru a calcula distanțele minime de la sursă la toate celelalte noduri. Deosebirea față de algoritmul clasic constă într-o optimizare care oprește algoritmul în cazul în care nu mai există modificări de distanțe într-o iterație.

### `void problema3()`

Această funcție este punctul de intrare în program. Deschide fișierul de intrare și fișierul de ieșire, apelează funcția `citire3` pentru a construi graful, calculează distanțele minime utilizând funcția `optimizedBellman` și scrie rezultatul în fișierul de ieșire.

## Utilizare

1. Introduceți datele de intrare în fișierul "date.in" în formatul specificat.
2. Rulați codul.
3. Rezultatul, adică distanțele minime de la sursă la toate celelalte noduri, va fi scris în fișierul "date.out".

Puteți include acest fișier `README.md` împreună cu codul dvs. pentru a oferi o descriere a funcționalității programului și modul în care acesta poate fi utilizat.



