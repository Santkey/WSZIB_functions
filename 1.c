#include <stdio.h>
#include <stdlib.h>

void silnia();

int main(int argc, char *argv[])
{
    /*
        Zadanie 1
        Napisz program zawierający funkcję, która obliczy n!. Program należy uruchomić dla 10
        zestawów danych.
        Uwaga!
        Program pobiera dane z pliku. Jeśli plik znajduje się w tym samym katalogu co plik exe wystarczy że jako parametr
        podczas uruchamiania podamy nazwę pliku. W przeciwnym wypadku musimy jako parametr podać pełną ścieżkę do pliku.
        Liczby do liczenia silni powinny być oddzielone spacjami bądź enterami.
    */
    FILE *plik;
    int i,n,wynik;
    if(argc==2){
        if((plik=fopen(argv[1],"r"))!=NULL){
            for(i=0;i<20;i++){
                if(fscanf(plik,"%d",&n)!=-1){
                    silnia(n);
                }else{
                    printf("Za malo argumentow w pliku %s",argv[1]);
                    break;
                }
            }
        }else{
            printf("Wystapil blad przy otwieraniu pliku: \"%s\"\n",argv[1]);
        }
    }else{
        printf("Podano bledne argumenty przy otwieraniu pliku.");
    }
    return 0;
}

void silnia(int n){
    int i;
    double wynik=1;
    if(n>=0){
        for(i=1;i<=n;i++){
            wynik=wynik*i;
        }
        printf("%d! = %.0f\n",n,wynik);
    }else{
        printf("Nie mamy silni dla liczb ujemnych, wiec nie ma wyniku dla %d!\n",n);
    }
}