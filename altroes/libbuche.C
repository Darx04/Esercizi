#include "libbuche.h";
//1
int caricabuca(char nomefile[], Arraybuca& rTupla){
   int conta = 0;
   buca appo;
   ifstream filein;
   bool status = true;

   rTupla.size = 0;
   rTupla.used = 0;
   rTupla.raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }

   status = leggibuca(filein,appo);

   while(status == true){
      conta++;
      status = leggibuca(filein,appo);
   }

   filein.clear();
   filein.seekg(0, ios::beg);
   rTupla.raw = new buca[conta];
   if(rTupla.raw == NULL){
      return -2;
   }
   rTupla.size = conta;

   for( ; rTupla.used < conta; rTupla.used++){
      leggibuca(filein, rTupla.raw[rTupla.used]);
   }
   filein.close();
   return 0;
}

bool leggibuca(ifstream& file, buca& rBuca){
   buca appo;
   file >> appo.xc >> appo.yc >> appo.rad >> appo.lab;
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      rBuca=appo;
      rBuca.n_part=0;
      rBuca.v_part=NULL;
      return true;
   }
} 

void stampa(buca rBuca){
   cout << endl << setw(12)<< "Ascissa centro: " << setw(12) << rBuca.xc;
   cout << endl << setw(12) << "ordinata centro: " << setw(12) << rBuca.yc;
   cout << endl << setw(12)<< "raggio: " << setw(12) << rBuca.rad;
   cout << endl << setw(12) << "Etichetta: " << setw(12) << rBuca.lab;
   cout << endl;
}

bool dentrocerchio(buca rBuca, part rPart){  
    float appox=pow(rPart.x-rBuca.xc,2);
    float appoy=pow(rPart.y-rBuca.yc,2);
    if (sqrt(appox+appoy)<=rBuca.rad){
        return true;
    }
    return false;
}

int carica_nel_cerchio(Arraybuca tBuca, Arraypart tPart){
    int conta;
    for (int i=0;i<tBuca.size;i++){
        for(int j=0;j<tPart.size;j++){
            if (dentrocerchio(tBuca.raw[i],tPart.raw[j])){
                tBuca.raw[i].n_part++;
            }
        }
    }

    for (int i=0;i<tBuca.size;i++){
        tBuca.raw[i].v_part= new part[tBuca.raw[i].n_part];
        conta=0;
        for(int j=0;j<tPart.size;j++){
            if (dentrocerchio(tBuca.raw[i],tPart.raw[j])){
                tBuca.raw[i].v_part[conta]=tPart.raw[j];
                conta++;
            }
        }
    }
    return 0;
    
}


void Bubblecerchio(Arraybuca & tBuca){
    for (int i=0;i<tBuca.size-1;i++){
        for (int j=i+1; j<tBuca.size; j++){
            if (tBuca.raw[i].n_part<tBuca.raw[j].n_part){
                scambia(&tBuca.raw[i], & tBuca.raw[j]);
            }
        }
    }

}

void scambia(buca *pa, buca *pb){
    buca appo;
    appo = *pa;
    *pa = *pb;
    *pb = appo;
}

void stampaspec(buca rBuca){
   cout << endl << setw(12) << "Etichetta: " << setw(12) << rBuca.lab;
   cout << endl << setw(12)<< "Numero part in cerchio: " << setw(12) << rBuca.n_part;
   cout << endl;
}


void stampa(buca rBuca, ofstream& fileout){
   fileout << endl << setw(12)<< "Ascissa centro: " << setw(12) << rBuca.xc;
   fileout << endl << setw(12) << "ordinata centro: " << setw(12) << rBuca.yc;
   fileout << endl << setw(12)<< "raggio: " << setw(12) << rBuca.rad;
   fileout << endl << setw(12) << "Etichetta: " << setw(12) << rBuca.lab;
   fileout << endl;
}
void stampaspec(buca rBuca, ofstream& fileout){
   fileout << endl << setw(12) << "Etichetta: " << setw(12) << rBuca.lab;
   fileout << endl << setw(12)<< "Numero part in cerchio: " << setw(12) << rBuca.n_part;
   fileout << endl;
}