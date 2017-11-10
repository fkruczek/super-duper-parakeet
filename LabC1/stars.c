#include <stdio.h>

int main()
{
    int i,k,n,j=1;
    scanf("%d", &n);
    for(i=n;i>0;i--)
    {
        for(k=i;k>0;k--)
        {
            printf(" ");
        }
        for(k=0;k<((2*j)-1);k++)
        {
            printf("*");
        }
        j++;
        printf("\n");
    }
    getch();
    return 0;
}
