#include <stdio.h>
#include <stdlib.h>
void buduj_tablice(int iloscElementow, int *tablica);
void czytaj_tablice(int iloscElementow, int *tablica);
int maximum(int iloscElementow, int *tablica);
double srednia(int iloscElementow, int *tablica);
int main()
{
    int iloscElementow;
    int *tablica=NULL;
    char wybor;
    while(1){
        system("CLS");
        printf("MENU:\n");
        printf("1. Tworzenie tablicy\n2. Odczyt tablicy\n3. Maximum\n4. Srednia\n[q]. Wyjscie\n");
        fflush(stdin);
        wybor = getchar();
        switch(wybor){
            case '1':
                    printf("Podaj ilosc elementow tablicy: ");
                do{
                    scanf("%d",&iloscElementow);
                    if(iloscElementow<1) printf("Ilosc elementow musi byc wieksza od 0.\n");
                }while(iloscElementow<1);
                    tablica=(int*)malloc(iloscElementow * sizeof(*tablica));
                    buduj_tablice(iloscElementow, tablica);
                break;
            case '2':
                    czytaj_tablice(iloscElementow, tablica);
                break;
            case '3':
                    printf("Maximum: %d",maximum(iloscElementow,tablica));
                break;
            case '4':
                    printf("Srednia: %lf",srednia(iloscElementow,tablica));
                break;
            case 'q':
                free(tablica);
                return 0;
                break;

        }
        printf("\n");
        system("PAUSE");
    }
    return 0;
}

void buduj_tablice(int iloscElementow, int *tablica)
{
    int i;
    printf("\nPodaj elementy do tablicy:\n");
    for(i=0;i<iloscElementow;i++){
        printf("%d:",i+1);
        scanf("%d",tablica+i);
    }
}

void czytaj_tablice(int iloscElementow, int *tablica)
{
    int i;
    if(tablica == NULL) printf("Tablica pusta!\n");
    else{
        printf("\nTABLICA:");
        for(i=0;i<iloscElementow;i++){
            printf("\n%d: %d",i+1,*(tablica+i));
        }
    }
}
int maximum(int iloscElementow, int *tablica)
{
    int i,max=*tablica;
    for(i=1;i<iloscElementow;i++){
        if(max<*(tablica+i)) max=*(tablica+i);
    }
    return max;
}
double srednia(int iloscElementow, int *tablica)
{
    int i,suma=0;
    for(i=0;i<iloscElementow;i++){
        suma+=*(tablica+i);
    }
    return suma/(double)iloscElementow;
}
