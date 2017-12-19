#include <stdio.h>
#include <stdlib.h>
/*napisac funkcje znajdujaca wspolne elementy dwoch tablic*/
int *tworz_tablice(int *n);
int *znajdz_wspolne(int *tablica1, int *tablica2,int ile_elementow1,int ile_elementow2, int *elementow_wspolnych);
int main()
{
    int i,ile_elementow1=0, ile_elementow2=0;
    int *tablica1=NULL, *tablica2=NULL, *tablica3=NULL;
    int elementow_wspolnych = 0;
    tablica1=tworz_tablice(&ile_elementow1);
    tablica2=tworz_tablice(&ile_elementow2);
    tablica3=znajdz_wspolne(tablica1, tablica2, ile_elementow1, ile_elementow2, &elementow_wspolnych);
    printf("\n TABLICE:\n");
    for(i=0;i<ile_elementow1 || i<ile_elementow2;i++)
    {
        printf("%d:",i+1);
        if(i<ile_elementow1) printf(" %d ",*(tablica1+i));
        else printf(" X");
        if(i<ile_elementow2) printf(" %d ",*(tablica2+i));
        else printf(" X");
        printf("\n");
    }

    printf("TABLICA WSPOLNYCH:\n");
    for(i=0;i<elementow_wspolnych;i++)
    {
        printf("%d: %d\n",i+1,*(tablica3+i));
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

int *znajdz_wspolne(int *tablica1, int *tablica2,int ile_elementow1,int ile_elementow2, int *elementow_wspolnych)
{
    int *tablica_wspolnych=NULL;
    int dalej = 0;
    int i, j;
    for (i = 0; i < ile_elementow1; i++) {
        dalej = 0;
        for (j = 0; j < *elementow_wspolnych; j++) {
            if (tablica1[i] == tablica_wspolnych[j]) {
                dalej = 1;
                break;
            }
        }
        if (dalej == 0) {
            for (j = 0; j < ile_elementow2; j++) {
                if (tablica1[i] == tablica2[j]) {
                    (*elementow_wspolnych)++;
                    tablica_wspolnych = (int*)realloc(tablica_wspolnych, (*elementow_wspolnych)*sizeof(int));
                    *(tablica_wspolnych+(*elementow_wspolnych-1)) = tablica1[i];
                    break;
                }
            }
        }
    }
    return tablica_wspolnych;
}

