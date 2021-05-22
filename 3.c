#include <stdio.h>
#include <stdlib.h>

void menu();
void poleprostokata();
void polekola();
void poletrojkata();

int main()
{
/*
    Zadanie 3
    Napisz program, który umożliwi wariantowe i wielokrotne wykonywanie następujących
    kilku funkcji: obliczanie pola prostokąta, obliczanie pola koła, obliczanie pola trójkąta.
    Program powinien kończyć działanie po naciśnięciu ‘K’ (należy uwzględnić to w menu w
    programie).
*/
    menu();
    return 0;
}

void menu(){
    char wybor[1];
    printf("Co chcesz policzyc:\n  1 Pole prostokata\n  2 Pole kola\n  3 Pole trojkata\n  K Koniec programu\nPodaj swoj wybor: ");
    scanf("%s",wybor);
    switch (wybor[0]){
    case '1':
        system("cls");
        poleprostokata();
        break;
    case '2':
        system("cls");
        polekola();
        break;
    case '3':
        system("cls");
        poletrojkata();
        break;
    case 'K':
        system("cls");
        break;
    default:
        system("cls");
        printf("Podales zly parametr. Wprowadz 1 2 3 lub K\n");
        menu();
        break;
    }

}

void poleprostokata(){
    float a,b;
    printf("Liczymy pole prostokata. Podaj dlugosci bokow proftokata. W przypadku liczb niecalkowitych czesci dziesietne oddziel kropka.\n");
    printf("Podaj pierwszy bok prostokata: ");
    scanf("%f",&a);
    printf("Podaj drugi bok prostokata: ");
    scanf("%f",&b);
    system("cls");
    printf("Pole prostokata o bokach %f i %f wynosi %f\n\n",a,b,a*b);
    menu();
}

void polekola(){
    float pi=3.141592,r;
    printf("Liczymy pole kola. Podaj promien kola. W przypadku liczb niecalkowitych czesci dziesietne oddziel kropka.\n");
    printf("Podaj promien kola: ");
    scanf("%f",&r);
    system("cls");
    printf("Pole kola o promieniu %f wunosi %f\n\n",r,pi*(r*r));
    menu();

}

void poletrojkata(){
    float a,h;
    printf("Liczymy pole trojkata. Podaj dlugosc podstawy i wysokosc trojkata. W przypadku liczb niecalkowitych czesci dziesietne oddziel kropka.\n");
    printf("Podaj dlugosc podstawy trojkata: ");
    scanf("%f",&a);
    printf("Podaj wysokosc trojkata: ");
    scanf("%f",&h);
    system("cls");
    printf("Pole trojkata o ppodstawie %f i wysokosci %f wynosi %f\n\n",a,h,a*h/2);
    menu();
}