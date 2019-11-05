#include <stdio.h>

char palabra[20];
char vocales[5];
char consonantes[22];
int top,i;

void push();
void pop();
void display();
void reves();
void contarV();
void contarC();

int main(){

    top = -1;

    push();


}

void push(){

    i = 0;
    if(top > 20){
        printf("La pila esta overflow\n");
    }else{
        printf("Escribe una palabra\n");
        scanf("%s\n",&palabra);
        fflush(stdin);

        do{
            printf("%c\n",palabra[i]);
            i++;
        }while(palabra[i] != '\0');
    }
    printf("Letras en la palabra %d\n",i );

}

void pop(){
    top = i - 1;


}
