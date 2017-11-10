#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b;
    float wynik;
    char znak;
    do
    {
        system("cls");
        printf("Menu: \n [+] - dodawanie\n [-] - odejmowanie\n [*] - mnozenie\n [/] - dzielenie\n ['%'] - dzielenie bez reszty\n [.] - wyjscie\n");
        znak = getch();
        printf("%c\n",znak);
        if(znak=='.') {printf("Koniec programu. STOP "); system("pause"); continue;}
        if(znak=='+' || znak=='-' || znak=='/' || znak=='*' || znak=='%' )
        {
            printf("Podaj a: ");
            scanf("%d",&a);
            printf("Podaj b: ");
            scanf("%d",&b);
            switch(znak)
            {
            case '+': wynik=a+b; break;
            case '-': wynik=a-b; break;
            case '*': wynik=a*b; break;
            case '/': {if(b==0){printf("\nNie mozna dzielic przez 0.");break;}wynik=a/(double)b; break;}
            case '%': wynik=a%b; break;
            }
            printf("\n%d %c %d = %lf\n",a,znak,b,wynik);
            system("pause");
        }
    }while(znak!='.');
    return 0;
}
