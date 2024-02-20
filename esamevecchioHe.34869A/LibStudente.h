#ifndef LIB_STUDENTE
#define LIB_STUDENTE
#include <iostream>
using namespace std;
#include <iomanip>

struct studente{
    int matr;   //matricola studente
    int cre;    //numero crediti conseguiti
    float wm;   //media pesata
    int nfails; //numero esami falliti
    bool is_out;//true: espulso
};

void stampastudenti(studente dati);

#endif