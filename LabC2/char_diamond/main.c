#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,j,k=0;
    char znak;
    scanf("%d",&n);
    znak = getch();
    for(i=0;i<(12-n/2);i++)
    {
        printf("\n");
    }
    for(i=++n/2;i>0;i--)
    {
        for(j=i+40;j>0;j--)
        {
            printf(" ");
        }
        for(j=0;j<=2*k;j++)
        {
            printf("%c",znak);
        }
        printf("\n");
        znak++; k++;
    }
        znak--;
    for(i=0;i<n/2;i++)
    {
        znak--;k--;
        for(j=0;j<=i+41;j++)
        {
            printf(" ");
        }
        for(j=(2*k)-1;j>0;j--)
        {
            printf("%c",znak);
        }
        printf("\n");
    }
    return 0;
}
