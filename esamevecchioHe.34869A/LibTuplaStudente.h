

#include <iostream>
#include <fstream>
#include "LibStudente.h"
#include <iomanip>

#ifndef LIB_TUPLA_STUDENTE
#define LIB_TUPLA_STUDENTE
using namespace std;

struct ArrayStudente{
    int size;
    int used;
    studente *raw;
};

int caricaStudente(char nomefile[], ArrayStudente& rTupla);
bool leggiStudente(ifstream& file,studente &rStudenti);
float contaDentro(ArrayStudente& studenti);
int elimina_espulsi(ArrayStudente & rStudenti);
int eliminaShift(studente v[], int pos, int ndati);
void stampafuori(ArrayStudente & studenti);
void sel_sort(studente v[],int dim);
void scambia(studente *pa, studente *pb);
int pos_min(studente v[],int low, int high);
int creafile(char file[], ArrayStudente tupla);
void stampa(ArrayStudente tupla, ofstream& fileout);
#endif