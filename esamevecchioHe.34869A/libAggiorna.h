#ifndef LIB_AGGIORNA
#define LIB_AGGIORNA
#include <iostream>
#include "LibTuplaVoto.h"
#include "LibTuplaStudente.h"
#include <cmath>
using namespace std;
int aggiorna(ArrayStudente & arrStudenti, ArrayVoto arrVoto);
int cercapos(int key, studente v[], int dim);
int nuovamedia(studente & stud, voto dat);


#endif