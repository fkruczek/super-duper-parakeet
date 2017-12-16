#include <stdio.h>
#include <stdlib.h>
/*
Funkcja wczytuje liczby do momentu podania liczby zakonczonej na 111,
na biezaco realokuje pamiec, zwraca ilosc liczb podzielnych przez 5.
Notacja wskaznikowa.*/
int ile_podzielnych(void);
int main()
{
    printf("Liczb podzielnych przez 5 w tablicy: %d", ile_podzielnych());
    return 0;
}
int ile_podzielnych(void)
{
    int *tablica=NULL,ile_p=0, i=0;
    tablica=(int*)malloc(sizeof(int*));
    while(1)
    {
        fflush(stdin);
        scanf("%d", tablica+i);
        if(*(tablica+i)%5==0) ile_p++;

        if(*(tablica+i)>0) //sprawdzenie czy liczba konczy sie na 111 w zależności od tego czy jest dodatnia czy ujemna
        {
            if((*(tablica+i)-111)%1000==0) break;
        }
        else
        {
            if((*(tablica+i)+111)%1000==0) break;
        }

        i++;
        tablica=(int*)realloc(tablica,i*sizeof(int));
    }
     return ile_p;
}
