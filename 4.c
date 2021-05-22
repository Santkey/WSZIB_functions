#include <stdio.h>
#include <stdlib.h>

void symbolnewtona();
float silnia();

int main()
{
/*
    Zadanie 4
    Napisz program zawierający funkcję, która oblicza symbol Newtona  . Program powinien
    wykonać obliczenia dla 10 zestawów danych (n i k), wczytywanych z podanego przy
    uruchomieniu pliku (argument programu). Dla każdego zestawu należy wyświetlić liczby i
    wynik dwumianu.
    Program uruchamiamy przez podanie w konsoli: Zadanie_3.exe < dane.txt przy założeniu
    że plik txt znajduje się w tym katalogu co plik exe.
*/
    int rozmiar=10,tablica[rozmiar],i;
    for (i=0;i<10;i+=2){
        scanf("%d",&tablica[i]);
        scanf("%d",&tablica[i+1]);
        symbolnewtona(tablica[i],tablica[i+1]);
    }
    return 0;
}

void symbolnewtona(int n, int k){
    if(0<=k && k<=n){
        float wynik;
        wynik = silnia(n)/(silnia(k)*silnia(n-k));
        printf("Symbol Newtona dla liczb n=%d k=%d wynosi %f\n",n,k,wynik);
    }else{
        printf("\n\nBrak symbolu Newtona dla liczb n=%d k=%d. Nie jest spelniony warunek 0 <= %d <= %d!\n\n",n,k,k,n);
    }

}

float silnia(int n){
    int i;
    float wynik=1;
    if(n>=0){
        for(i=1;i<=n;i++){
            wynik=wynik*i;
        }
        return wynik;
    }else{
        printf("\n\nNie mamy silni dla liczb ujemnych, wiec nie ma wyniku dla %d!\n\n",n);
        return 0;
    }
}