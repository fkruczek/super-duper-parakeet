#include <stdio.h>
#include <string.h>

int main()
{
    char jakisNapis[100];
    int i,srodek,dlugosc=0;
    gets(jakisNapis);
    while(jakisNapis[dlugosc]!='\0') dlugosc++;
    srodek=(dlugosc/2);
    for(i=0;i<=srodek;i++)
    {
        dlugosc--;
        if(jakisNapis[i]!=jakisNapis[dlugosc])
        {
            printf("To nie jest palindrom\n");
            break;
        }
    }
    if(i-1==srodek)printf("To jest palindrom\n");
    getch();
    return 0;
}
