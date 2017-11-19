#include <stdio.h>
#include <stdlib.h>

int dodawacz(int);
int main()
{
    int n;
    while(n>=1){
        scanf("%d",&n);
        printf("%d",dodawacz(n));
    }
    getch();
    return 0;
}
int dodawacz(int n)
{
    int k=0,suma=0;
    while(suma<n){
        k++;
        suma+=k;
        printf("k = %d , suma = %d\n",k,suma);
    }
    return --k;
}
