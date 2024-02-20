#include "LibTuplaVoto.h"

int caricavoto(char nomefile[], ArrayVoto& rTupla){
   int conta = 0;
   voto appo;
   ifstream filein;
   bool status = true;

   rTupla.size = 0;
   rTupla.used = 0;
   rTupla.raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }

   status = leggiVoto(filein,appo);

   while(status == true){
      conta++;
      status = leggiVoto(filein,appo);
   }

   filein.clear();
   filein.seekg(0, ios::beg);

   rTupla.raw = new voto[conta];
   if(rTupla.raw == NULL){
      return -2;
   }
   rTupla.size = conta;

   for( ; rTupla.used < conta; rTupla.used++){
      leggiVoto(filein, rTupla.raw[rTupla.used]);
   }
   filein.close();
   return 0;
}

bool leggiVoto(ifstream& file, voto& rVoti){
   voto appo;
   file >> appo.cod >> appo.cre >> appo.matr >> appo.val;
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      rVoti=appo;
      return true;
   }
} 

float contaSuff(ArrayVoto voti){
    float conta=0;
    for (int i=0;i<voti.used;i++){
        if (voti.raw[i].val>17){
            conta++;
        }
    }
    return conta;
}