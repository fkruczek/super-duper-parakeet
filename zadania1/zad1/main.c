#include <stdio.h>
#include <stdlib.h>
int main()
{
    int bokA,bokB,bokC;
    double pole;
    do
    {
        {
            printf("Podaj 3 dlugosci bokow trojkata\n");
            scanf("%d %d %d",&bokA,&bokB,&bokC);
            if(bokA>0 && bokB>0 && bokC>0)
            {
                if(bokA>=bokB && bokA>=bokC)
                {
                    if((bokA*bokA)==((bokB*bokB)+(bokC*bokC)))
                       {
                           pole=(bokB*bokC)/(double)2;
                       }
                    else pole=0;
                }
                else if(bokB>=bokA && bokB>=bokC)
                {
                    if((bokB*bokB)==((bokA*bokA)+(bokC*bokC)))
                       {
                           pole=(bokA*bokC)/(double)2;
                       }
                    else pole=0;
                }
                else if(bokC>=bokB && bokC>=bokA)
                {
                    if((bokC*bokC)==((bokB*bokB)+(bokA*bokA)))
                       {
                           pole=(bokA*bokB)/(double)2;
                       }
                    else pole=0;
                }
            }
            else pole=0;
        }
    } while(pole==0);
    printf("Pole trojkata o bokach %d %d %d wynosi: %lf",bokA,bokB,bokC,pole);
    getch();
    return 0;
}

