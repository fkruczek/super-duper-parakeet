#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    double a,b,c;
    char znak;
    do{
        printf("Podaj 3 liczby: ");
        scanf("%lf %lf %lf",&a,&b,&c);
        if(a>0 && b>0 && c>0){
            if(a>=b && a>=c){
                if((b+c)>a) printf("To moze byc trojkat");
                else printf("To nie moze byc trojkat");
            }
            else if(b>=a && b>=c){
                if((a+c)>b) printf("To moze byc trojkat");
                else printf("To nie moze byc trojkat");
            }
            else if(c>=b && c>=a){
                if((b+a)>c) printf("To moze byc trojkat");
                else printf("To nie moze byc trojkat");
            }
        }
        else printf("To nie moze byc trojkat");
        printf("\nJeszcze raz? [T]\n");
        znak = getch();
    }while(znak == 'T' || znak == 't');
}
