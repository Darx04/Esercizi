#include "LibStudente.h"

void stampastudenti(studente dati){
    cout << setw(10) <<"matricola studente:   " << dati.matr << "    ";
    cout << setw(10) <<"numero crediti conseguiti:   " << dati.cre << "    ";
    cout << setw(10) <<"media pesata:     " << dati.wm << "    ";
    cout << setw(10) <<"numero esami falliti:    "<< dati.nfails << "    ";
    if (dati.is_out==true){
        cout << setw(10) <<"fuori"<<endl;
    }else{
        cout << setw(10) <<"dentro"<<endl;
    }
    return;
}