#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 5



// Estrutura da pilha
struct TPilha {
    int pratos[MAXTAM];
    int pratos2[MAXTAM];
    int topo;
};

//Variaveis globais
struct TPilha pilha;
int pilhaCheia = 0;

void criarPilha();
void preencherPilhaAutomatico();
void mostrarPilha();
void inverterPilha();
void mostrarPilhaInversa();

//Preencher pilha manualmente
void criarPilha(){
    int i;
    if(pilhaCheia == MAXTAM){
        system("cls");
        printf("\n\n Pilha cheia, escolha outra opcao para continuar...");
    } else {
        system("cls");
        for(i = 0; i < MAXTAM; i++){
        printf("\nInforme o valor a ser inserido na pilha: ");
        fflush(stdin);
        scanf("%d", &pilha.pratos[i]);
        pilha.topo++;
        pilhaCheia++;
        }
    }
}

//Preencher pilha automaticamente
void preencherPilhaAutomatico(){
    int i;
    int j = 1;
    for(i = 0; i < MAXTAM; i++){
        pilha.pratos[i] = j;
        j++;
        pilha.topo++;
        pilhaCheia++;

    }
    system("cls");
    printf("\nPilha preenchida!\n\n");
}

//Mostra pilha ja criada
void mostrarPilha(){
    int i;
    system("cls");
    printf("Imprimindo pilha: \n\n");
    for(i = 0; i < MAXTAM; i++){
        printf("Elemento na posicao %d: %d\n\n", i, pilha.pratos[i]);
    }
}

//Inverter a pilha criada
void inverterPilha(){
    int j;
    int i = 0;
    int aux;
    system("cls");
    for(j = 4;j >= 0; j--){
        aux = pilha.pratos[j];
        pilha.pratos2[i] = aux;
        printf("Pilha invertida: %d\n\n", pilha.pratos2[i]);
        pilha.topo--;
        pilhaCheia--;
        i++;
    }
    // MOSTRAR TODS OS ITENS DO ARRAY pilha.pratos
}

//Imprimir pilha inversa
void mostrarPilhaInversa(){
    int i;
    system("cls");
    printf("Imprimindo pilha inversa: \n");
    for(i = 0; i < MAXTAM; i++){
        printf("Elemento na posicao %d: %d\n", i, pilha.pratos2[i]);
    }
}

int main(){
    int opcaoMenu = 10;
    printf("\n|-------------------------------------------------------------------|\n");
    printf("|                            ESTRUTURA DE DADOS I                   |\n");
    printf("| Aluno: Luiz Claudio Jurazek de Alvarenga                          |\n");
    printf("| RA: ***********                                                   |\n");
    printf("|-------------------------------------------------------------------|\n\n\n");
    printf("Ordem dos pratos: \n");
    printf("1 - Vermelho\n");
    printf("2 - Verde\n");
    printf("3 - Azul\n");
    printf("4 - Branco\n");
    printf("5 - Laranja\n");

    while(opcaoMenu != 0){
    printf("                               MENU\n\n");
    printf("1 - Preencher pila automaticamente\n");
    printf("2 - Criar a Pilha inserindo os valores manualmente\n");
    printf("3 - Mostrar Pilha\n");
    printf("4 - Inverter Pilha Criado\n");
    printf("5 - Mostrar pilha invertida\n");
    printf("0 - SAIR\n\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcaoMenu);
    fflush(stdin);

        switch(opcaoMenu){
            case 1:
                preencherPilhaAutomatico();
                break;
            case 2:
                criarPilha();
                break;
            case 3:
                mostrarPilha();
                break;
            case 4:
                inverterPilha();
                break;
            case 5:
                mostrarPilhaInversa();
                break;
        }
    }
}
