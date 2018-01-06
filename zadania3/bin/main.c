#include <stdio.h>
#include <stdlib.h>
#define FILENAME "studenci.bin"
struct student{
    char nazwisko[30], imie[20];
    int numer;
    double oceny[5];
    double srednia;
};

void dodaj(void);
void drukuj_plik(void);
void drukuj(struct student);
struct student srednia(struct student s);
double maksimum(void); // funkcja zwraza najwieksza srednia
struct student *najlepsi(int *n); // zwraca wskaznik do tablicy struktur (echhhhhhhhhhhh)
double minimum(void); // funkcja zwraca minimalna srednia
int usun(void); //usuwanie studentów z najniższ srednia
void popraw (void); // znaleźć studenta o podanych danych i poprawia jego dane

int main()
{
    int i, il_najlepszych=0;
    struct student *najlepsi_studenci=NULL;
    char wybor;
    do{
        system("cls");
        printf("MENU:\n1. Dodaj\n2. Drukuj\n3. Wyswietl najlepszych\n4. Usun najgorszych\n5. Popraw\n");
        wybor=getchar();
        switch (wybor){
            case '1':
                dodaj();
                break;

            case '2':
                drukuj_plik();
                break;

            case '3':
                printf("\nNazwiska osob, ktore maja maksymalna srednia wynoszaca %lf to: \n", maksimum());
                najlepsi_studenci=najlepsi(&il_najlepszych);
                for (i=0; i<il_najlepszych; i++)
                    printf("%s\n",(*(najlepsi_studenci+i)).nazwisko);
                break;

            case '4':
                printf("Usunieto %d studentow\n",usun());
                break;
            case '5':
                popraw();
                break;
        }
    }while(wybor!='q');
    return 0;
}
void dodaj(void)
{
    struct student nowy;
    FILE *studenci;
    int i;
    studenci = fopen(FILENAME, "ab");
    if(studenci==NULL) printf("Nie mozna otworzyc pliku");
    else {
        fflush(stdin);
        printf("Podaj imie: ");
        scanf("%20[^\n]c", &nowy.imie);
        fflush(stdin);
        printf("Podaj nazwisko: ");
        scanf("%30[^\n]c", &nowy.nazwisko);
        fflush(stdin);
        printf("Podaj indeks: ");
        scanf("%d", &nowy.numer);
        printf("Podaj 5 ocen: ");
        for(i=0; i<5; i++){
            scanf("%lf", &nowy.oceny[i]);
        }
        nowy=srednia(nowy);
        fwrite(&nowy, sizeof(struct student), 1, studenci);
        fclose(studenci);
    }
}
void drukuj_plik()
{
    struct student s;
    FILE *studenci;
    studenci = fopen(FILENAME, "rb");
    rewind(studenci);
    while(fread(&s, sizeof(struct student), 1, studenci)==1)
    {
        drukuj(s);
        printf("\n");
    }
    fclose(studenci);
    getch();
}
void drukuj(struct student s)
{
    int i;
    printf("Imie: %s\n", s.imie);
    printf("Nazwisko: %s\n", s.nazwisko);
    printf("Indeks: %d\n", s.numer);
    printf("Oceny: ");
    for (i=0; i<5; i++)
    {
        printf("%lf ", s.oceny[i]);
    }
    printf("\nSrednia: %lf\n", s.srednia);
}
struct student srednia(struct student s)
{
    double suma=0;
    int i;
    for(i=0; i<5; i++)
        suma+=s.oceny[i];
    s.srednia=suma/5;
    return s;
}
double maksimum(void)
{
    FILE *studenci;
    struct student s;
    double maks_srednia=0;
    studenci=fopen(FILENAME,"rb");
    while(fread(&s, sizeof(struct student), 1, studenci)==1)
    {
        if(s.srednia>maks_srednia) maks_srednia=s.srednia;
    }
    fclose(studenci);
    return maks_srednia;
}
struct student *najlepsi(int *n)
{
    FILE *studenci;
    struct student s;
    struct student *najlepsi_studenci=NULL;
    double max=maksimum();
    studenci=fopen(FILENAME,"rb");
    while(fread(&s, sizeof(struct student), 1, studenci)==1)
    {
        if(s.srednia==max)
        {
            (*n)++;
            najlepsi_studenci=(struct student*)realloc(najlepsi_studenci, (*n)*sizeof(struct student));
            *(najlepsi_studenci+(*n)-1)=s;
        }
    }
    fclose(studenci);
    return najlepsi_studenci;
}
double minimum(void)
{
    FILE *studenci;
    struct student s;
    double minimalna=10;
    studenci=fopen(FILENAME,"rb");

    while(fread(&s, sizeof(struct student), 1, studenci)==1)
    {
        if(s.srednia<minimalna) minimalna=s.srednia;
    }
    fclose(studenci);
    return minimalna;
}

int usun(void)
{
    FILE *studenci, *nowy;
    double minimalna=minimum();
    struct student s;
    int usunietych=0;
    studenci=fopen(FILENAME, "rb");
    nowy=fopen("nowy.bin", "wb");
    while(fread(&s, sizeof(struct student),1, studenci)){
        if(s.srednia==minimalna){
            printf("Usunieto studenta o imieniu %s\n",s.nazwisko);
            usunietych++;
          }
        else{
            fwrite(&s, sizeof(struct student), 1, nowy);
        }
    }
    fclose(studenci);
    fclose(nowy);
    remove(FILENAME);
    rename("nowy.bin", FILENAME);
    return usunietych;
}

void popraw(void)
{
    struct student s, pusta;
    int indeks,i;
    FILE *studenci;
    studenci = fopen(FILENAME, "rb+");
    printf("Podaj indeks studenta ktorego chcesz edytowac: ");
    scanf("%d", &indeks);
    while(fread(&s, sizeof(struct student), 1, studenci)==1)
    {
        if(s.numer==indeks){
            printf("\nZnaleziono studenta o indeksie %d\n", indeks);
            s=pusta;
            printf("\nPodaj imie: ");
            fflush(stdin);
            scanf("%20[^\n]c", &s.imie);
            printf("\nPodaj nazwisko: ");
            fflush(stdin);
            scanf("%30[^\n]c", &s.nazwisko);
            fflush(stdin);
            printf("\nPodaj indeks: ");
            scanf("%d", &s.numer);
            printf("Podaj 5 ocen: ");
            for(i=0; i<5; i++){
                scanf("%lf", &s.oceny[i]);
            }
            s=srednia(s);
            fseek(studenci, -sizeof(struct student), SEEK_CUR);
            fwrite(&s, sizeof(struct student), 1, studenci);
            break;
        }
    }
    fclose(studenci);
}
