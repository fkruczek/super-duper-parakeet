#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Napisać funkcje 'zlacz', która będzie łączyć 2 wczytane łańcuchy po jednym elemencie naprzemiennie.
W mainie zadeklarować wskaźniki *x1, *x2 oraz zmienne d1, d2 (długość 1 i 2 łańcucha).
Wczytać długość obu łańcuchów, zarezerwować pamięć, wczytać elementy, wywołać funkcje, zwolnic pamięć.
Korzystać tylko z notacji wskaźnikowej.*/
char *pomieszaj_wyraz(char *,char *); //char * mozna zastapic int bez *
int main()
{
    char *x1,*x2;
    int d1,d2;


    printf("Dlugosc 1 lancucha: ");
    scanf("%d",&d1);
    fflush(stdin);
    x1=(char*)malloc((d1+1)*sizeof(*x1));

    printf("\nWczytaj lancuch 1: ");
    fgets(x1,(d1+1)*sizeof(*x1), stdin);
    fflush(stdin);

    printf("\nDlugosc 2 lancucha: ");
    scanf("%d",&d2);
    fflush(stdin);
    x2=(char*)malloc((d2+1)*sizeof(*x2));

    printf("\nWczytaj lancuch 2: ");
    fgets(x2,(d2+1)*sizeof(*x2), stdin);
    fflush(stdin);

    printf("\nLancuch 1: %s\n",x1);
    printf("Lancuch 2: %s\n",x2);

    //printf("adres x1: %d\n",x1);
   // printf("adres x2: %d\n",x2);

    printf("Pomieszany wyraz: %s\n", pomieszaj_wyraz(x1,x2)); //funkcja wysyla adresy lancuchow

    free(pomieszaj_wyraz(x1,x2));
    free(x1);
    free(x2);

    system("pause");
    return 0;
}

char *pomieszaj_wyraz(char *napis1,char *napis2) //"char *" mozna zastapic int bez *
{
    char *nowy_napis;
    int i=0,j=0,k=0;
    int a=strlen(napis1),b=strlen(napis2);
    nowy_napis=(char*)malloc((a+b)*sizeof(*nowy_napis));
    for(;i<a+b;)
    {
        if(*(napis1+j)!='\0')
        {
            *(nowy_napis+i)=*(napis1+k);
            j++; i++;
        }
        if(*(napis2+k)!='\0')
        {
            *(nowy_napis+i)=*(napis2+k);
            k++; i++;
        }
    }
    *(nowy_napis+i)='\0';
    //printf("adres nowy_napis: %d\n",nowy_napis);
    return nowy_napis;
}
