#include <stdio.h>
#include <stdlib.h>

int najmniejszaujemna(int tab[], int ile);

int main(int argc, char *argv[])
{
/*
    Zadanie 6
    Napisz program zawierający funkcję, która znajduje największą liczbę ujemną w
    pierwszych n elementach 30 elementowej tablicy liczb całkowitych. Elementy tablicy
    powinny być wczytywane w programie głównym ze wskazanego przy uruchomieniu pliku
    (argument programu). n – ma być wczytywane z klawiatury w programie głównym. W
    programie głównym wyświetlić na monitorze tablicę n-elementową oraz wynik funkcji.
*/
    FILE *plik;
    int i,ile=30,tab[ile],wynik;
    if(argc==2){
        if((plik=fopen(argv[1],"r"))!=NULL){
            for(i=0;i<ile;i++){
                if(fscanf(plik,"%d",&tab[i])==-1){
                    printf("Za malo argumentow w pliku %s",argv[1]);
                    break;
                }
            }
            if(i==ile)
                printf("Najwieksza ujemna z tablicy to: %d",najmniejszaujemna(tab,ile));
        }else{
            printf("Wystapil blad przy otwieraniu pliku: \"%s\"\n",argv[1]);
        }
    }else{
        printf("Podano bledne argumenty przy otwieraniu pliku.");
    }

    return 0;
}

int najmniejszaujemna(int tab[], int ile){
    int wynik = 0;
    for(int i=0;i<ile;i++){
        if(tab[i]<0&&(tab[i]>wynik || wynik==0))
            wynik = tab[i];
    }
    return wynik;
}