#include <stdio.h>
#include <stdlib.h>

float srednia();

int main()
{
    /*
        Zadanie 2
        Napisz program, który zawiera funkcję obliczającą średnią arytmetyczną liczb
        zmiennoprzecinkowych z podanej tablicy (parametr funkcji). W programie należy wykonać
        funkcję kilkakrotnie dla różnych tablic.
    */
    int ile1,ile2,ile3;
    float tablica1[]={2.42,12.2423,223.234,7634.234,434.234,22.563,23.75,2.764,9.346,8,243};
    float tablica2[]={4.73,23.545,134.7,2.773,2.6742,345.2256,22.7,32.263,2.452};
    float tablica3[]={234.4234,1.451,223.622,1145.1234,23.562,2.52};
    ile1 = sizeof tablica1 / sizeof *tablica1;
    ile2 = sizeof tablica2 / sizeof *tablica2;
    ile3 = sizeof tablica3 / sizeof *tablica3;
    printf("Srednia tablicy 1 wynosi: %f\n",srednia(&tablica1,ile1));
    printf("Srednia tablicy 2 wynosi: %f\n",srednia(&tablica2,ile2));
    printf("Srednia tablicy 3 wynosi: %f\n",srednia(&tablica3,ile3));
    return 0;
}

float srednia(float *tablica,int ile){
    int i;
    float suma=0;
    for(i=0;i<ile;i++){
        suma += tablica[i];
    }
    suma = suma/ile;
    return suma;
}