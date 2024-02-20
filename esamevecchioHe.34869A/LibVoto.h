#include <iostream>
#include <iomanip>
using namespace std;

#ifndef LIB_VOTO
#define LIB_VOTO

struct voto{
    int cod;    //codice esame
    int cre;    //numero crediti esame
    int matr;   //matricola studente
    int val;    //voto conseguito

};

void stampavoto(voto dati);

#endif