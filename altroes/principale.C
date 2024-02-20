#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "libbuche.h"
#include "libpart.h"

int main(){

    int i=0;
    int errore=0;

    ofstream fileout;
    fileout.open("risultati.dat");
    if (fileout.fail()){
      return -1;
    }
     
    //1
   cout << endl << setw(12) << "1" << endl;
   fileout << endl << setw(12) << "1" << endl;
    Arraybuca tBuche;
    caricabuca("buche.dat", tBuche);
    for (i=0;i<tBuche.size;i++){
        cout <<endl << "il "<< i+1 << " cerchio:" << endl;
        fileout <<endl << "il "<< i+1 << " cerchio:" << endl;
        stampa(tBuche.raw[i]);
        stampa(tBuche.raw[i],fileout);
    }
    
    //2
    cout << endl << setw(12) << "2" << endl;
   fileout << endl << setw(12) << "2" << endl;

    Arraypart tPart;
    caricapart("particelle.dat",tPart);

    cout << "le prime 3 particelle: " << endl;
    printarray(tPart,0,3,fileout);

    cout << "le ultime 3 particelle: " << endl;
    printarray(tPart,tPart.size-3,tPart.size,fileout);
    

    //3
    cout << endl << setw(12) << "3" << endl;
   fileout << endl << setw(12) << "3" << endl;

    carica_nel_cerchio(tBuche, tPart);
    for (i=0;i<tBuche.size;i++){
        if(tBuche.raw[i].lab=='A'){
            cout << tBuche.raw[i].n_part<< endl;
            for (int j=0; j< tBuche.raw[i].n_part;j++){
                cout <<endl << "la "<< j+1 << " particella:" << endl;
                fileout <<endl << "la "<< j+1 << " particella:" << endl;
                stampa(tBuche.raw[i].v_part[j]);
                stampa(tBuche.raw[i].v_part[j],fileout);
            }
        }
    }

    //4
    cout << endl << setw(12) << "4" << endl;
   fileout << endl << setw(12) << "4" << endl;

    Bubblecerchio(tBuche);
    for (i=0;i<tBuche.size;i++){
        stampaspec(tBuche.raw[i]);
        stampaspec(tBuche.raw[i], fileout);
    }

    //5
    cout <<endl <<  setw(12) << "5" << endl;
   fileout << endl << setw(12) << "5" << endl;

    float somma=0;
    for (i=0;i<tBuche.size;i++){
        somma=sommamass(tBuche.raw[i].v_part, tBuche.raw[i].n_part);
        cout << endl << "il cerchio " << tBuche.raw[i].lab << "   ha:" << endl;
        cout << "somma delle masse: " << somma << endl;
        cout << "carica media: " << caricamedia(tBuche.raw[i].v_part, tBuche.raw[i].n_part, somma)<< endl;

        fileout << endl<< "il cerchio " << tBuche.raw[i].lab << "   ha:" << endl;
        fileout << "somma delle masse: " << somma << endl;
        fileout << "carica media: " << caricamedia(tBuche.raw[i].v_part, tBuche.raw[i].n_part, somma)<< endl;
    }


    for (int i=0;i<tBuche.size;i++){
        delete [] tBuche.raw[i].v_part;
        tBuche.raw[i].v_part=NULL;
    }
     fileout.close();
    return 0;
}

