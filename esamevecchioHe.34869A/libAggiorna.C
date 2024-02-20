#include "libAggiorna.h"


int aggiorna(ArrayStudente & arrStudenti, ArrayVoto arrVoto){
    int pos=0;
    for (int i=0; i<arrVoto.used; i++){
        pos=cercapos(arrVoto.raw[i].matr , arrStudenti.raw, arrStudenti.used);
        if (arrVoto.raw[i].val<18){
            arrStudenti.raw[pos].nfails++;
            if(arrStudenti.raw[pos].nfails>=5){
                arrStudenti.raw[pos].is_out=true;
            }
        } else{
            arrStudenti.raw[pos].cre=arrStudenti.raw[pos].cre+arrVoto.raw[i].cre;
            nuovamedia(arrStudenti.raw[pos],arrVoto.raw[i]);
        }
    }
    return 0;
}

int cercapos(int key, studente v[], int dim){
    for (int i=0; i<dim; i++){
        if (key==v[i].matr){
            return i;
        }
    }
}

int nuovamedia(studente & stud, voto dat){
    float prima=stud.wm*stud.cre;
    float nuovo=dat.cre*dat.val;
    stud.wm=(prima+nuovo)/(dat.cre+stud.cre);
    return 0;
}