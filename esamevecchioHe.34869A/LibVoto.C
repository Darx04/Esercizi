#include "LibVoto.h"

void stampavoto(voto dati){
    cout << setw(10) <<"codice esame:   " << dati.cod << "    ";
    cout << setw(10) <<"numero crediti esame:   " << dati.cre << "    ";
    cout << setw(10) <<"matricola studente:     " << dati.matr << "    ";
    cout << setw(10) <<"voto conseguito:    "<< dati.val << endl;
    return;
}

