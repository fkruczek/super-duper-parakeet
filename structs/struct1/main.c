#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct gracz{
    char nick_gracza[50];
    int punkty;
};
int main()
{
    int i,k,liczba_graczy,trafienie;
    int wygral=0;
    struct gracz *gracze;
    printf("Podaj liczbe graczy: ");
    scanf("%d",&liczba_graczy);
    gracze = (struct gracz *)malloc(liczba_graczy*sizeof(struct gracz));
    for(i=0;i<liczba_graczy;i++)
    {
        printf("Gracz nr. %d\n",i+1);
        printf("Podaj nick: ");
        fflush(stdin);
        fgets(gracze[i].nick_gracza, 50*sizeof(char), stdin);
        fflush(stdin);
        gracze[i].punkty=301;
    }
    while(wygral==0)
    {
        printf("\nTABELA WYNIKOW\n");
        for(i=0;i<liczba_graczy;i++)
        {
            printf("Gracz nr. %d: %s - %d\n",i+1,gracze[i].nick_gracza,gracze[i].punkty);
        }
        printf("\n");
        for(i=0;i<liczba_graczy;i++)
        {
            printf("KOLEJ GRACZA %s",gracze[i].nick_gracza);
            for(k=0;k<3;k++)
            {
                printf("%d/3 rzut: ",k+1);
                scanf("%d",&trafienie);
                gracze[i].punkty-=trafienie;
                if(gracze[i].punkty<0)gracze[i].punkty*=-1;
                if(gracze[i].punkty==0)
                {
                    printf("\n WYGRYWA: %s\n",gracze[i].nick_gracza);
                    wygral=1;
                    break;
                }
            }
        }
    }
    system("pause");
    return 0;
}
