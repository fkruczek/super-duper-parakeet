#include <stdio.h>
int main()
{
    double x,skladnik2,suma=0;
    int n,i,k,skladnik1;
    scanf("%lf%d",&x,&n);
    for(i=1;i<=n;i++)
    {
        if((i%2)==0)skladnik1=-1;
        else skladnik1=1;
        skladnik2=1;
        for(k=0;k<i;k++)
        {
            skladnik2=(x*skladnik2);
        }
        skladnik2=skladnik2/i;
        suma+=(skladnik1*skladnik2);
    }
    printf("SUMA: %lf\n",suma);
    return 0;
}

