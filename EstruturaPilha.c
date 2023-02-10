// 1 - Vermelho
// 2 - Verde
// 3 - Azul
// 4 - Branco
// 5 - Laranja


#include <stdio.h>
#include <conio.h>

//Constante pra definir tamanho da pilha
#define max 4

// Variáveis globais
int pilhaPratos[max]; // Pilha inicial pratos
int topo = 0;

// Protótipo das funcoes
void exibir();
void empilhar();
void desempilhar();

int main (){
    int op;
    //Menu:
    do{
        printf("\n **Pilha estatica** \n");
        printf("\n 1 - empilhar");
        printf("\n 2 - desempilhar");
        printf("\n 3 - exibir");
        printf("\n 0 - sair \n\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                empilhar();
                break;
            case 2:
                desempilhar();
                break;
            case 3:
                exibir();
                break;
        }; // Fim switch
    }while(op != 0); //Fim laco
    return 0;
    system("PAUSE");
}

void empilhar(){
    int i;
    for(i = 1; i <= pilhaPratos[max]; i++){
        pilhaPratos[topo] = i;
        topo++;
        printf("%d", pilhaPratos[topo]);
    }
}// fim funcao empilhar


void desempilhar(){
     if(topo == 0){
        printf("\n Pilha vazia");
     } else {
        printf("\n Desempilhada o valor: %d", pilhaPratos[topo - 1]);
        topo--;
     }// Fim else
     getch();
}// Fim desempilha

void exibir(){
    int i;
    for(i = topo - 1; i >= 0; i--){
        printf("\n Posicao %d = %d", i, pilhaPratos[i]);
        getch();
    }
}





