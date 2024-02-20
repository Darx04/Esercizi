#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "LibVoto.h"
#include "LibTuplaVoto.h"
#include "LibStudente.h"
#include "LibTuplaStudente.h"
#include "libAggiorna.h"


int main(){
    ArrayVoto voti;
    int errore;
    int i=0;
    //1
    errore=caricavoto("votiGF.dat", voti);

    cout << setw(10) << "il numero di voti e':  " << voti.used << endl<< endl;

    float vot_suff=contaSuff(voti);
    float vot_insuff=voti.used-vot_suff;

    cout << setw(10) << "ci sono  " << vot_suff <<"/"<<voti.used  << setw(10)
        << "voti sufficienti, ovvero: " << vot_suff/voti.used << endl;
    cout << setw(10) << "ci sono  " << vot_insuff <<"/"<<voti.used  << setw(10)
        << "voti insufficienti, ovvero: " << vot_insuff/voti.used << endl;

    cout << endl << "I primi 3 voti:" << endl;
    for (i=0;i<3;i++){
        stampavoto(voti.raw[i]);
    }
    
    cout << endl << "Gli ultimi 3 voti:" << endl;
    for (i=voti.used-3;i<voti.used;i++){
        stampavoto(voti.raw[i]);
    }
    

    //2
    ArrayStudente studenti;
    errore=caricaStudente("studenti.dat", studenti);

    cout << setw(10) << "il numero di studenti e':  " << studenti.used << endl<< endl;
    stampafuori(studenti);

    float dentro=contaDentro(studenti);
    float fuori=studenti.used-dentro;

    

    cout << setw(10) << "ci sono  " << dentro <<"/"<<studenti.used  << setw(10)
        << "studenti non espulsi, ovvero: " << dentro/studenti.used << endl;
    cout << setw(10) << "ci sono  " << fuori <<"/"<<studenti.used  << setw(10)
        << "studenti espulsi, ovvero: " << fuori/studenti.used << endl;

   

    //3
    
    errore=elimina_espulsi(studenti);
    
    sel_sort(studenti.raw, studenti.used);
    errore=creafile("studentitprimaGF.dat",studenti);
    cout << endl << "I primi 3 studenti:" << endl;
    for (i=0;i<3;i++){
        stampastudenti(studenti.raw[i]);
    }

    cout << endl << "Gli ultimi 3 studenti:" << endl;
    for (i=studenti.used-3;i<studenti.used;i++){
        stampastudenti(studenti.raw[i]);
    }

     cout << studenti.used << endl;

//4
    aggiorna(studenti,voti);
    errore=elimina_espulsi(studenti);
    errore=creafile("studentiGF.dat",studenti);
    delete [] voti.raw;
    delete [] studenti.raw;
    voti.raw=NULL;
    studenti.raw=NULL;

}