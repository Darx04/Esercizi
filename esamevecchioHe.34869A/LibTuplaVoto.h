#include <fstream>
#include <iostream>

#include "LibVoto.h"

#ifndef LIB_TUPLA_VOTO
#define LIB_TUPLA_VOTO

struct ArrayVoto{
    int size;
    int used;
    voto *raw;
};

int caricavoto(char nomefile[], ArrayVoto& rTupla);


bool leggiVoto(ifstream& file, voto& rVoti);


float contaSuff(ArrayVoto voti);
#endif
