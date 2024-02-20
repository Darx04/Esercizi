#include "LibTuplaStudente.h"

int caricaStudente(char nomefile[], ArrayStudente& rTupla){
   int conta = 0;
   studente appo; //studente.rawariabili d'appoggio
   ifstream filein;
   bool status = true;

   rTupla.size = 0;
   rTupla.used = 0;
   rTupla.raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }

   status = leggiStudente(filein,appo);

   while(status == true){
      conta++;
      status = leggiStudente(filein,appo);
   }

   filein.clear();
   filein.seekg(0, ios::beg);

   rTupla.raw = new studente [conta];
   if(rTupla.raw == NULL){
      return -2;
   }
   rTupla.size = conta;

   for( ; rTupla.used < conta; rTupla.used++){
      leggiStudente(filein, rTupla.raw[rTupla.used]);
   }
   filein.close();
   return 0;
}

bool leggiStudente(ifstream& file,studente &rStudenti){
   studente appo;
   file >> appo.matr >> appo.cre >> appo.wm >> appo.nfails;
   appo.is_out=false;
   if(file.eof() || file.fail()){
      return false;
   }
   else{
        if (appo.nfails>=5){
            appo.is_out=true;
        }
        rStudenti=appo;
        return true;
   }
} 

float contaDentro(ArrayStudente& studenti){
    float conta=0;
    for (int i=0;i<studenti.used;i++){
        if (studenti.raw[i].is_out==false){
            conta++;
        }
    }
    return conta;
}

void stampafuori(ArrayStudente & studenti){
    cout << "gli studenti espulsi sono: "<< endl;
    for (int i=0;i<studenti.used;i++){
        if (studenti.raw[i].is_out==true){
                cout <<"prova"<< endl;
               stampastudenti(studenti.raw[i]);
            }
    }
}

int elimina_espulsi(ArrayStudente & rStudenti){
    int conta=0;
    for (int i = 0; i < rStudenti.used; i++){
        if (rStudenti.raw[i].is_out==true){
                eliminaShift(rStudenti.raw, i, rStudenti.used);
                conta++;
        }
    }
    rStudenti.used=rStudenti.used-conta;
    return 0;
}

int eliminaShift(studente v[], int pos, int ndati){
   if(pos >=0 and pos < ndati){
      for(int i = pos; i<ndati-1; i++){
         v[i] = v[i+1];
      }
      return ndati-1;
   }
   else{
      cout << endl << "Eliminaswap: posizione fuori range!\n";  
      return -1;
   }
}

void sel_sort(studente v[],int dim){
    int pos;
    for(int i=0; i<dim-1; i++){
        pos = pos_min(v,i,dim-1);
        scambia(&v[i],&v[pos]);
    }

}

void scambia(studente *pa, studente *pb){
    studente appo;
    appo = *pa;
    *pa = *pb;
    *pb = appo;
}

int pos_min(studente v[],int low, int high){
    int min = v[low].matr;
    int pmin = low;

    for(int i = low+1; i<=high; i++){
        if(v[i].matr< min){
            min = v[i].matr;
            pmin = i;
        }
    }
    return pmin;   
}


int creafile(char file[], ArrayStudente tupla){
    ofstream fileout;
    fileout.open(file);
    if (fileout.fail()){
      return -1;
    }
    stampa(tupla, fileout);
    fileout.close();
    return 0;
}

void stampa(ArrayStudente tupla, ofstream& fileout){
    int a;
    for(int i=0; i<tupla.used; i++){
        a=12;
        if(tupla.raw[i].matr>100){
            a=10;
        }else if(tupla.raw[i].matr>10){
            a=11;
        }
            fileout << tupla.raw[i].matr <<
            setw(a) << tupla.raw[i].cre << 
            setw(12) << tupla.raw[i].wm <<
            setw(12) << tupla.raw[i].nfails << endl;
        
    }
}

