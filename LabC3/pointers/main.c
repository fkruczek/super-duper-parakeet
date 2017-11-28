#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i,j=0,numbersAmount=0,charsAmount=-1;
    fgets(str,sizeof str, stdin);
    for(i=0; *(str+i)!='\0'; i++)
    {
        switch(*(str+i)){
        case 65 ... 90: //letters A ... Z
        case 97 ... 122: //letters a ... z
            str[j]=*(str+i);
            j++;
            break;
        case 48 ... 57: //number
            numbersAmount++;
            break;
        default: //other char
            charsAmount++;
            break;
        }
    }
    str[j]='\0';

    printf("\n New string: %s",str);
    printf("\n Deleted other characters: %d", charsAmount);
    printf("\n Deleted numbers: %d", numbersAmount);
    getch();
    return 0;
}
