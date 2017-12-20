#include <stdio.h>
#include <stdlib.h>
/*parzyste zapisuje podwojnie X D */
int *czytaj1(int *n);
int *modyfikuj_tablice(int *tablica, int dlugosc, int *dlugosc2);
int main()
{
    int dlugosc=0, dlugosc2=0, i;
    int *tablica, *nowa_tablica;
    tablica=czytaj1(&dlugosc);
    nowa_tablica=modyfikuj_tablice(tablica, dlugosc, &dlugosc2);
    printf("Tablica: \n");
    for(i=0; i<dlugosc; i++)
    {
        printf("%d\n",*(tablica+i));
    }
    printf("Nowa Tablica: \n");
    for(i=0; i<dlugosc2; i++)
    {
        printf("%d\n",*(nowa_tablica+i));
    }
    return 0;
}
int *czytaj1(int *n)
{
    int *tablica=NULL;
    int liczba;
    while(scanf("%d", &liczba), liczba!=0)
    {
        (*n)++;
        tablica=(int*)realloc(tablica, (*n)*sizeof(int));
        *(tablica+(*n)-1)=liczba;
    }
    return tablica;
}
int *modyfikuj_tablice(int *tablica, int dlugosc, int *dlugosc2)
{
    int *nowa_tablica=NULL;
    int i,k=1;

    for(i=0; i<dlugosc; i++)
    {
        if(*(tablica+i)%2!=0)
        {
            nowa_tablica=(int*)realloc(nowa_tablica, k*(sizeof(int)));
            *(nowa_tablica+k-1)=*(tablica+i);
            k++;
        }
        else
        {
            nowa_tablica=(int*)realloc(nowa_tablica,(k+1)*(sizeof(int)));
            *(nowa_tablica+k-1)=*(nowa_tablica+k)=*(tablica+i);
            k++;k++;
        }
    }
    *dlugosc2=k-1;
    return nowa_tablica;
}
