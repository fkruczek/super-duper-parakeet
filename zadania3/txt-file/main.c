#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "sample_text.txt"
#define LINE_LENGHT 100
void write_text(void);
void read_text(void);
void delete_file(void);
int main()
{
    write_text();
    read_text();
    delete_file();
    return 0;
}

void write_text()
{
    FILE *plik = fopen(FILENAME, "w");
    char line[LINE_LENGHT];
    printf("Wpisuj tekst (maksymalna dlugosc lini: %d). By zakonczyc wyslij pusta linie.\n", LINE_LENGHT);
    if (plik!=0){
        do{
            fflush(stdin);
            fgets(line, sizeof(line), stdin);
            if(strcmp(line,"\n")==0)break;
            fprintf(plik, "%s", line);
        }
        while(1);
    }
    else printf("ERROR ERROR");
    fclose(plik);
}
void read_text(void)
{
    FILE *plik = fopen(FILENAME, "r");
    char line[LINE_LENGHT];

    if(plik!=0){
        printf("Tresc pliku %s:\n", FILENAME);
        while(fgets(line, sizeof(line), plik)!=0)
            printf("%s", line);
        fclose(plik);
    }
    else printf("Plik o nazwie %s nie moze zostac otwarty", FILENAME);
}

void delete_file()
{
    if (remove(FILENAME)==0) printf("\nPlik %s usuniety", FILENAME);
    else printf("\nPlik %s nie usuniety", FILENAME);
}



