#include <stdio.h>
#include <stdlib.h>
/*napisac funkcje znajdujaca wspolne elementy dwoch tablic*/
int *tworz_tablice(int *n);
int main()
{
    int i,ile_elementow1=0, ile_elementow2=0;
    int *tablica1=NULL, *tablica2=NULL;
    tablica1=tworz_tablice(&ile_elementow1);
    tablica2=tworz_tablice(&ile_elementow2);
    printf("\n TABLICE:\n");
    for(i=0;i<ile_elementow1 || i<ile_elementow2;i++)
    {
        printf("%d:",i+1);
        if(i<ile_elementow1) printf(" %d ",*(tablica1+i));
        else printf("-");
        if(i<ile_elementow2) printf(" %d ",*(tablica2+i));
        else printf("-");
        printf("\n");
    }
    return 0;
}
int *tworz_tablice(int *n)
{
    int i=0;
    int *tablica=NULL;
    printf("UWAGA! WCZYTAJ TABLICE...\n");
    while(1)
    {
        tablica=(int*)realloc(tablica,(i+1)*sizeof(int));
        scanf("%d",tablica+i);
        if(*(tablica+i)==0) break;
        i++;
    }
    *n=i;
    return tablica;
}
