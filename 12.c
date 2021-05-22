#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int najwiekszaujemna(int *tab, int ile);

int main(int argc, char *argv[])
{
/*
    Zadanie 12
    Napisz program zawierający funkcję, która znajduje (pierwszą) największą liczbę ujemną
    w 50 elementowej tablicy liczb całkowitych. Elementy tablicy powinny być wygenerowane
    losowo w programie głównym(oraz wyświetlone na monitorze), a następnie zapisane we
    wskazanym przy uruchomieniu pliku (argument programu) razem z wynikiem zwróconym
    przez funkcję.
*/
    if(argc==2){
        int ile=50,tablicaliczblosowych[ile],i,najwieksza;
        FILE *plik;
        srand(time(NULL));
        for(i=0;i<ile;i++){
            tablicaliczblosowych[i]=(rand()%201)-100;
        }
        if((plik=fopen(argv[1],"w"))==NULL){
            printf("Blad otwierania pliku w trybie zapisu!\n");
            exit(1);
        }
        printf("tablica[] = {");
        fprintf(plik,"tablica[] = {");
        for(i=0;i<ile;i++){
            if(i!=ile-1){
                printf("%d,",tablicaliczblosowych[i]);
                fprintf(plik,"%d,",tablicaliczblosowych[i]);
            }else{
                printf("%d}\n",tablicaliczblosowych[i]);
                fprintf(plik,"%d}\n",tablicaliczblosowych[i]);
            }
        }
        najwieksza = najwiekszaujemna(tablicaliczblosowych,ile);
        printf("Najwieksza ujemna z tablicy to: %d",najwieksza);
        fprintf(plik,"najwieksza ujemna z tablicy to: %d",najwieksza);
        fclose(plik);
    }else{
        printf("Podano bledne argumenty przy otwieraniu pliku.");
    }
    return 0;
}

int najwiekszaujemna(int *tab, int ile){
    int najwieksza=0;
    for(int i=0;i<ile;i++){
        if(tab[i]<0 && (tab[i]>najwieksza || najwieksza==0))
            najwieksza=tab[i];
    }
    return najwieksza;
}
