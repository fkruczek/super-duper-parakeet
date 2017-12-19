#include <stdio.h>
#include <stdlib.h>
int *podaj_podzielniki(int liczba, int *ile);
int main()
{
    int liczba, *podzielniki=NULL, ile_elementow=0, i;
    scanf("%d", &liczba);
    printf("Podzielniki liczby %d to: ", liczba);
    podzielniki=podaj_podzielniki(liczba, &ile_elementow);
    for(i=0; i<ile_elementow; i++)
    {
        printf(" %d",*(podzielniki+i));
    }
    return 0;
}
int *podaj_podzielniki(int liczba, int *ile)
{
    int *podzielniki=NULL;
    int i;
    for(i=0; i<liczba; i++)
    {
        if(liczba%(i+1)==0)
        {
            (*ile)++;
            podzielniki=(int*)realloc(podzielniki,(*ile)*sizeof(int*));
            *(podzielniki+(*ile-1))=i+1;
        }
    }
    return podzielniki;
}
