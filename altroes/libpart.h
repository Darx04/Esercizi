#ifndef LIB_PART
#define LIB_PART
#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>

struct part{
    float x; //Ascissa particella
    float y;//ordinata particella
    int c; // Carica particella
    float m; // massa particella
};

struct Arraypart{
    int size;
    int used;
    part * raw;
};

int caricapart(char nomefile[], Arraypart& rTupla);
bool leggipart(ifstream& file, part& rpart);
void stampa(part rpart);
void stampa(part rpart, ofstream& fileout);
void printarray(Arraypart tPart, int inizio, int fine, ofstream& fileout);
float sommamass(part p[], int dim);
float caricamedia(part p[], int dim, int somma);



#endif