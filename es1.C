#include <iostream>
#include <fstream>
using namespace std;
#define NN 150
//#include <"libArray.h">
//#include <"libStatistica.h">
//#include <"C:\Users\DAari\Desktop\Unimi\InformaticaLab_2023_24\esercizi\libArray.C\libArray.h">
//#include <"C:\Users\DAari\Desktop\Unimi\InformaticaLab_2023_24\esercizi\libStatistica.C\libStatistica.h">



int main(){
    float v[NN], mediana, mediana, devstd;
    int i=0, j=0;

    ifstream infile;
    file_in.open("sfere.dat");
    if (infile.fail()){
        cout << "il file ha avuto un errore '/n'";
        return -1;
    }
    infile >> v[i];
    while (!(infile.eof())){
        i++;
        infile >> v[i];
    }
    infile.close();
    v[NN]=ordinaF(v, NN);
    mediana=medianF(v,NN);
    media=mediaF(v,NN);
    devstd=devstdF(v,NN);
    for (j=0; j<3; j++){
        cout << "il " << j+1 << "valore e'" << v[j]<< endl;
    }
    for (j=i-4; j<i; j++){
        cout << "il " << j+1 << "valore e'" << v[j]<< endl;
    }
    cout << "la mediana e'" << mediana << endl << "la media e'"<< media <<endl
    << "la deviazione standard e' " << devstd<< endl << "il valore minimo e' "<<
    v[0] << endl << "il valore massimo e' "<< v[i-1]<< endl;

    return 0;
}