#include <stdio.h>
int main()
{
    unsigned long liczba,badana,nowa;
    scanf("%lu",&liczba);
    badana=liczba;
    nowa=0;
    while(badana!=0){
      nowa=10*nowa+(badana%10);
      badana=badana/10;
    }
    if(liczba==nowa) printf("Liczba %lu jest palindromem",liczba);
    else printf("Liczba %lu nie jest palindromem",liczba);
    return 0;
}
