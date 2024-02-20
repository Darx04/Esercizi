#ifndef LIB_BUCHE
#define LIB_BUCHE
#include <iostream>
using namespace std;
#include <iomanip>
#include "libpart.h"
#include <fstream>
#include <cmath>

struct buca{
    float xc; //Ascissa centro
    float yc;//ordinata centro
    float rad; //raggio
    char lab; //Etichetta
    int n_part; // Numero part in cerchio
    part *v_part; // Vettore particelle
};

struct Arraybuca{
    int size;
    int used;
    buca * raw;
};

int caricabuca(char nomefile[], Arraybuca& rTupla);
bool leggibuca(ifstream& file, buca& rBuca);
void stampa(buca rBuca);
bool dentrocerchio(buca rBuca, part rPart);
int carica_nel_cerchio(Arraybuca tBuca, Arraypart tPart);
void Bubblecerchio(Arraybuca & tBuca);
void scambia(buca *pa, buca *pb);
void stampaspec(buca rBuca);
void stampa(buca rBuca, ofstream& fileout);
void stampaspec(buca rBuca, ofstream& fileout);                                                                                                                                                                                                                                                                                                                                                                                                       
#endif