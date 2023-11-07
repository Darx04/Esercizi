#include <iostream>
using namespace std;


void leggi(int v[], int n){
    for (int i=0; i<n; i++){
        cout << "il "<<i+1<< " valore e' " <<v[i] << endl;
    }
}//legge in outpput i valori dell'array

int ordinaI(int v[],int n){
    int comodo;
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (v[i]>v[j]){
                comodo=v[i];
                v[i]=v[j];
                v[j]=comodo;
            }
        }
    }
    return v[n];
}//ordina gli elementi dell'array int

float ordinaF(float v[],int n){
    float comodo;
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (v[i]>v[j]){
                comodo=v[i];
                v[i]=v[j];
                v[j]=comodo;
            }
        }
    }
    return v[n];
}//ordina gli elementi dell'array int


int contapari(int v[], int n){
    int conta=0;
    for (int i=0; i<n; i++){
        if ((v[i]%2)==0){
            conta++;
        }
    }
    return conta;
}//conta i valori pari nell'array
int contadisp(int v[], int n){
    int conta=0;
    for (int i=0; i<n; i++){
        if ((v[i]%2)!=0){
            conta++;
        }
    }
    return conta;
}//conta i valori dispari dell'array



int scambiavet(int v[], int n){
    int i, j;
    cout << "inserire la 2 posizioni da scambiare" <<endl;
    cin >> i >> j;
    if (i<0 and i>n and j<0 and j>n){
        cout << "indici fuori range"<< endl;
    }else{
        int comodo;
        comodo=v[i];
        v[i]=v[j];
        v[j]=comodo;
    }
    return v[n];
}

int deleteEntrySwap(float v[], int size, int used, int where){
    if (where<0 || where>=(used-1)){
        cout << "Eliminazione non possibile: indice fuori range" << endl;
        return used;
    }
    for (int i=where; i<used; i++){
        v[i]=v[i+1];
    }
    for (int i=0; i<used-1; i++){
        cout << i<< "val=" <<v[i]<< " / ";
    }
    return 0;
}//elimina in un vettore float, inserendo la capienza, il numero dei elementi e 
// l'indice dell'elemento da eliminare


