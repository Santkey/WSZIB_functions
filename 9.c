#include <stdio.h>
#include <stdlib.h>

int *pierwsze(int n);

int czypierwsza(int n);

int main()
{
/*
    Zadanie 9
    Napisz program zawierający funkcję, która rozpoznaje czy liczba(parametr funkcji) jest
    pierwsza (zwraca 1 jeżeli jest i 0 jeżeli nie) oraz tworzy tablicę, którą wypełnia 10-cioma
    kolejnymi liczbami pierwszymi, nie mniejszymi od liczby podanej n (liczba n wczytywana z
    klawiatury w programie głównym). W programie głównym wyświetlić na monitorze
    utworzoną tablicę 10-elementową.
*/
    int n;
    printf("Program sprawdzajacy czy podana liczba jest liczba pierwsza i zwracajacy tablice 10 kolejnych liczb pierwszych.\n");
    while(1){
        printf("Podaj liczbe calkowita wieksza od 1 do sprawdzenia: ");
        scanf("%d",&n);
        if(n>1)
            break;
    }
    int *wynik = pierwsze(n);
    printf("Funkcja dla liczby %d zwrocila %d (1 - liczba pierwsza, 0 - liczba nie pierwsza)\n",n,wynik[0]);
    int *tab = wynik[1];
    printf("10 kolejnych liczb pierwszych to: ");
    for(n=0;n<10;n++){
        if(n!=9)
            printf("%d,",tab[n]);
        else
            printf("%d}",tab[n]);
    }
    return 0;
}

int *pierwsze(int n){
    static int tab[10];
    static int wynik[2];
    int i=0,liczba=n;
    wynik[0] = czypierwsza(n);
    while(i<10){
        liczba++;
        if(czypierwsza(liczba)){
            tab[i]=liczba;
            i++;
        }
    }
    wynik[1]=tab;
    return wynik;
}

int czypierwsza(int n){
    int doile,wynik=1;
    doile = (n/2)+1;
    for(int i=2;i<doile;i++){
        if(n%i==0){
            wynik = 0;
            break;
        }
    }
    return wynik;
}