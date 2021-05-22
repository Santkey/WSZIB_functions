#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int czypierwsza(int liczba);

int main(int argc, char *argv[])
{
/*
    Zadanie 14
    Napisz program zawierający funkcję, która rozpoznaje czy liczba(parametr funkcji) jest
    pierwsza (zwraca 1 jeżeli jest i 0 jeżeli nie). W programie głównym tworzy tablicę 50
    elementową liczb całkowitych wygenerowaną losowo oraz zapisuje liczby pierwsze z tej
    tablicy do wskazanego przy uruchomieniu pliku (argument programu).
*/
    if(argc==2){
        int ile=50,tablicaliczblosowych[ile],i;
        FILE *plik;
        srand(time(NULL));
        printf("tab[]={");
        for(i=0;i<ile;i++){
            tablicaliczblosowych[i]=rand();
            if(i!=ile-1)
                printf("%d,",tablicaliczblosowych[i]);
            else
                printf("%d}\n",tablicaliczblosowych[i]);
        }
        if((plik=fopen(argv[1],"w"))==NULL){
            printf("Blad otwierania pliku w trybie zapisu!\n");
            exit(1);
        }
        fprintf(plik,"Liczby pierwsze:\n");
        printf("Liczby pierwsze: ");
        for(i=0;i<ile;i++){
            if((czypierwsza(tablicaliczblosowych[i])==1)){
                fprintf(plik,"%d, ",tablicaliczblosowych[i]);
                printf("%d ",tablicaliczblosowych[i]);
            }
        }
        fprintf(plik,"\n");
        fclose(plik);
    }else{
        printf("Podano bledne argumenty przy otwieraniu pliku.");
    }
    return 0;
}

int czypierwsza(int liczba){
    int i;
    if(liczba<2)
        return 0;
    for(i=2;i*i<=liczba;i++)
        if(liczba%i==0)
            return 0;
    return 1;
}