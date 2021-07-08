#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Struct para os projetos
struct cadastro{
    char titulo[30];
    char descricao[50];
    char gerente[30];
    int ano, codigo, status;
};

// Variaveis
struct cadastro projeto[2];
int escolha, codigototal;




// cadastrar projeto
int cadastrarprojeto(){     
    int novoprojeto;
    printf("----------------------------------------------------------------\n");
    printf("                    Cadastrar projeto: \n");
    projeto[codigototal+1].codigo = codigototal +1;
    printf("O codigo do projeto eh: %d\n", codigototal +1);
    printf("Informe o titulo do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].titulo);
    printf("Informe o status do projeto: \n");
    scanf("%d", &projeto[codigototal+1].status);
    printf("Informe o ano do projeto: \n");
    scanf("%d", &projeto[codigototal+1].ano);
    printf("Qual o gerente do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].gerente);
    printf("Informe a descricao do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].descricao);

    codigototal = codigototal + 1;

}     

// listar todos projetos

void listarprojetos(){
    int i;
    printf("----------------------------------------------------------------\n");
    printf("Projetos: ");
    for (i = 0; i <= codigototal; i++){
        printf("\nCodigo: %d", projeto[i].codigo);
        printf("\nTitulo: %s", projeto[i].titulo);
        printf("\nGerente: %s", projeto[i].gerente);
        printf("\nstatus: %d", projeto[i].status);
        printf("\nAno: %d", projeto[i].ano);
        printf("\nDescricao: %s", projeto[i].descricao);
    }
}




// CORPO PROGRAMA 
int main(){  
    setlocale(LC_ALL, "Portuguese");
    codigototal = 0;
    do {
        printf("\n---------------------------------------------");
        printf("\n          Hub de Projetos - JURAZEK");
        printf("\n---------------------------------------------");
        printf("\n                   MENU");
        printf("\n 1 - Cadastrar um novo projeto ");
        printf("\n 2 - Listar projetos cadastrados");

        printf("\n");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            cadastrarprojeto();
            break;
        
        case 2:
            listarprojetos();
            break;

        case 3:

            break;
        default:
            break;
        }

    } while (escolha != 5);
    return 0;
}
