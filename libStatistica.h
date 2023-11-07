#include <iostream>
#include <cmath>
using namespace std;

float medianaI(int v[], int n){
    float med;
    if (n%2==0){
        med=v[n/2]=v[(n/2)+1];

    }else{
        med=v[n+1]/2;
    }
    return med;
}// restituisce la mediana di un' array int

float medianaF(float v[], int n){
    float med;
    if (n%2==0){
        med=v[n/2]=v[(n/2)+1];

    }else{
        med=v[n+1]/2;
    }
    return med;
}// restituisce la mediana di un' array float


float leggiValido(float minimo, float massimo){
    float val;
    cout<< "inserire il valore: "<< endl;
    cin >> val;
    
    while (val<minimo || val>massimo){
        cout<< "hai sbagliato, reinserire il valore: "<< endl;
        cin >> val;
    }
    return val;
}//restituisce un valore compreso tra due estremi massimo e minimo

float mediaI(int lista[], int n){
    int somma=0, i;
    for (i=0; i<n ;i++){
        somma=somma+lista[i];
    }
    return (somma/n);
}// restituisce la media dei elementi di un array int

float mediaF(float lista[], int n){
    int somma=0, i;
    for (i=0; i<n ;i++){
        somma=somma+lista[i];
    }
    return (somma/n);
}// restituisce la media dei elementi di un array float

float devstdI(int lista[], float med, int n){
    float scarto=0;
    for (int i=0; i<n;i++){
        scarto=scarto+pow((med-lista[i]),2);
    }
    float devstd =sqrt(scarto/(n-1));
    return devstd;
}// restituisce la deviazione standard di un array int

float devstdF(float lista[], float med, int n){
    float scarto=0;
    for (int i=0; i<n;i++){
        scarto=scarto+pow((med-lista[i]),2);
    }
    float devstd =sqrt(scarto/(n-1));
    return devstd;
}// restituisce la deviazione standard di un array float

int mcd(int minimo, int massimo){
    int resto;
     while (minimo!=0){
        resto=massimo%minimo;
        massimo=minimo;
        minimo=resto;
    }
    return(massimo);
}//ritorna il mcd di due elementi

int minimoI(int v[], int n){
    int min;
    min=v[0];
    for (int i=1; i<n; i++){
        if (min>v[i]){
            min=v[i];
        }
    }
    return min;
}// Ritorna il valore minimo dell'array int

float minimoF(float v[], int n){
    float min;
    min=v[0];
    for (int i=1; i<n; i++){
        if (min>v[i]){
            min=v[i];
        }
    }
    return min;
}// Ritorna il valore minimo dell'array float

int massimoI(int v[], int n){
    int max;
    max=v[0];
    for (int i=1; i<n; i++){
        if (max<v[i]){
            max=v[i];
        }
    }
    return max;
}// Ritorna il valore minimo dell'array float

float massimoF(float v[], int n){
    float max;
    max=v[0];
    for (int i=1; i<n; i++){
        if (max>v[i]){
            max=v[i];
        }
    }
    return max;
}// Ritorna il valore minimo dell'array float