#include "libpart.h"
//1

int caricapart(char nomefile[], Arraypart& rTupla){
   int conta = 0;
   part appo;
   ifstream filein;
   bool status = true;

   rTupla.size = 0;
   rTupla.used = 0;
   rTupla.raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }

   status = leggipart(filein,appo);

   while(status == true){
      conta++;
      status = leggipart(filein,appo);
   }

   filein.clear();
   filein.seekg(0, ios::beg);

   rTupla.raw = new part[conta];
   if(rTupla.raw == NULL){
      return -2;
   }
   rTupla.size = conta;

   for( ; rTupla.used < conta; rTupla.used++){
      leggipart(filein, rTupla.raw[rTupla.used]);
   }
   filein.close();
   return 0;
}

bool leggipart(ifstream& file, part& rpart){
   part appo;
   file >> appo.x >> appo.y >> appo.c >> appo.m;
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      rpart=appo;
      return true;
   }
} 

void stampa(part rpart){
   cout << endl << setw(12)<< "Ascissa particella: " << setw(12) << rpart.x;
   cout << endl << setw(12) << "ordinata particella: " << setw(12) << rpart.y;
   cout << endl << setw(12)<< "Carica particella: " << setw(12) << rpart.c;
   cout << endl << setw(12) << "massa particella: " << setw(12) << rpart.m;
   cout << endl;
}

void stampa(part rpart, ofstream& fileout){
   fileout << endl << setw(12)<< "Ascissa particella: " << setw(12) << rpart.x;
   fileout << endl << setw(12) << "ordinata particella: " << setw(12) << rpart.y;
   fileout << endl << setw(12)<< "Carica particella: " << setw(12) << rpart.c;
   fileout << endl << setw(12) << "massa particella: " << setw(12) << rpart.m;
   fileout << endl;
}

void printarray(Arraypart tPart, int inizio, int fine, ofstream& fileout){
    for (int i=inizio;i<fine;i++){
            cout <<endl << "la "<< i+1 << " particella:" << endl;
            fileout <<endl << "la "<< i+1 << " particella:" << endl;
            stampa(tPart.raw[i]);
            stampa(tPart.raw[i], fileout);
        }
}


float sommamass(part p[], int dim){
    float somma=0;
    for (int i=0;i<dim; i++){
        somma=somma+p[i].m;
    }
    return somma;
}

float caricamedia(part p[], int dim, int somma){
    float caricamed=0;
    float sommacar=0;
    for (int i=0;i<dim; i++){
        sommacar=sommacar+p[i].c;
    }
    caricamed=sommacar/somma;
    return caricamed;
}