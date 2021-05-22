#include <stdio.h>
#include <stdlib.h>

int najmniejszadodatnia();

int main(int argc, char *argv[])
{
/*
    Zadanie 5
    Napisz program zawierający funkcję, która znajduje (pierwszą) najmniejszą liczbę
    dodatnią w pierwszych n elementach 30 elementowej tablicy liczb całkowitych. Elementy
    tablicy powinny być wczytywane w programie głównym ze wskazanego przy uruchomieniu
    pliku (argument programu). W programie głównym wyświetlić na monitorze tablicę n-
    elementową oraz wynik funkcji.
    Uwaga!
    Program pobiera dane z pliku. Jeśli plik znajduje się w tym samym katalogu co plik exe wystarczy że jako parametr
    podczas uruchamiania podamy nazwę pliku. W przeciwnym wypadku musimy jako parametr podać pełną ścieżkę do pliku.
    Liczby do uzupelnienia tablicy powinny być oddzielone spacjami bądź enterami.
*/

    FILE *plik;
    int i,wynik;
    int tablica[30];
    if(argc==2){
        if((plik=fopen(argv[1],"r"))!=NULL){
            printf("\n\ntablica[]={");
            for(i=0;i<30;i++){
                if(fscanf(plik,"%d",&tablica[i])!=-1){
                    if(i<29)
                        printf("%d,",tablica[i]);
                    else
                        printf("%d}\n\n",tablica[i]);
                }else{
                    printf("Za malo argumentow w pliku %s",argv[1]);
                    break;
                }
            }
            if(i==30){
                wynik = najmniejszadodatnia(&tablica,30);
                printf("Najmniejsza liczba dodatnia z podanej tablicy to: %d \n",wynik);
            }
        }else{
            printf("Wystapil blad przy otwieraniu pliku: \"%s\"\n",argv[1]);
        }
    }else{
        printf("Podano bledne argumenty przy otwieraniu pliku.");
    }
    return 0;
}

int najmniejszadodatnia(int *tablica,int ile){
    int najmniejsza=0;
    for(int i=0;i<ile;i++){
        if(tablica[i]>0){
            if(tablica[i]<najmniejsza || najmniejsza==0){
                najmniejsza=tablica[i];
            }
        }
    }
    return najmniejsza;
}
