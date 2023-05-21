# Execuția unui Task Specific

Acest cod permite executarea unui task specific, în funcție de argumentul de linie de comandă. Taskurile disponibile sunt reprezentate de codul 1, 2 și 3.

## Utilizare

1. Compilați codul sursă utilizând un compilator C++.
2. Rulați fișierul executabil generat, specificând argumentul de linie de comandă corespunzător taskului dorit.

## Structura Codului

- `problema1.hpp`: Fișierul conținând codul pentru problema 1.
- `problema2.hpp`: Fișierul conținând codul pentru problema 2.
- `problema3.hpp`: Fișierul conținând codul pentru problema 3.

## Funcționarea Programului

1. În funcția `main`, se utilizează argumentul de linie de comandă `argv[1]` pentru a determina taskul specific care trebuie executat.
2. În funcție de valoarea argumentului `argv[1]`, se apelează funcția corespunzătoare pentru fiecare task:
    - `problema1()` pentru taskul 1.
    - `problema2()` pentru taskul 2.
    - `problema3()` pentru taskul 3.
3. Dacă argumentul `argv[1]` nu corespunde niciunui task disponibil, se afișează un mesaj de eroare.

## Utilizare în linia de comandă

Pentru a executa un anumit task, utilizați următoarea comandă în linia de comandă, specificând numărul taskului dorit:

```shell
./executabil <numar_task>
```
De asemnea se poate folosi Makefile-ul pentru a compila si rula tema.
Comenzile pentru makefile sunt:
```shell
make -- compilare
make problema1 -- rulare problema 1
make problema2 -- rulare problema 2
make problema3 -- rulare problema 3
```
Datele de intrare trebuie sa fie in fisierul date.in, iar datele de iesire vor fi in fisierul date.out.