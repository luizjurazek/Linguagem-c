#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>





// Struct para os projetos
struct cadastro{
    char titulo[30];
    char descricao[80];
    char gerente[30];
    char cliente[30];
    float valor;
    int ano, codigo, estimativa, status;
};

// Variaveis
struct cadastro projeto[200];
int escolha, codigototal;


// cadastrar projeto
int cadastrarprojeto(){     
    int cadnovamente;
    system("cls");
    printf("-----------------------------------------------------\n");
    printf("                  Cadastrar projeto: \n");
    projeto[codigototal+1].codigo = codigototal + 1;
    printf("O código do projeto é: %d\n", codigototal + 1);
    printf("Informe o título do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].titulo);
    printf("Informe o status do projeto: 1 - A FAZER | 2 - EM ANDAMENTO | 3 - CONCLUIDO\n");
    fflush(stdin);
    scanf("%d", &projeto[codigototal+1].status);
    printf("Informe o prazo estimado do projeto: (EM MESES)\n");
    fflush(stdin);
    scanf("%d", &projeto[codigototal+1].estimativa);
    printf("Informe o ano do projeto: \n");
    fflush(stdin);
    scanf("%d", &projeto[codigototal+1].ano);
    printf("Qual o gerente do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].gerente);
    printf("Informe o nome do cliente: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].cliente);
    printf("Informe a descrição do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].descricao);
    printf("Informe o valor do projeto: R$");
    scanf("%f", &projeto[codigototal+1].valor);

    codigototal = codigototal + 1;

    printf("Deseja cadastrar outro projeto: 1 - SIM | 2 - NÃO | 3 - VISUALIZAR PROJETO \n");
    fflush(stdin);
    scanf("%d", &cadnovamente);

    switch (cadnovamente){
    case 1:
        cadastrarprojeto();
        break;
    
    case 2:
        printf("Retornando ao menu");
        system("cls");
        break;

    case 3: 
        system("cls");
        printf("-----------------------------------------------------\n");
        printf("    	último projeto cadastrado\n");
        printf("Código: %d\n", projeto[codigototal].codigo);
        printf("Título: %s\n", projeto[codigototal].titulo);
        printf("Gerente: %s\n", projeto[codigototal].gerente);
        printf("Cliente: %s\n", projeto[codigototal].cliente);
        printf("status: %d\n", projeto[codigototal].status);
        printf("Estimativa do prazo: %d meses\n", projeto[codigototal].estimativa);
        printf("Ano: %d\n", projeto[codigototal].ano);
        printf("Descrição: %s\n", projeto[codigototal].descricao);
        printf("Valor: R$ %.2f\n", projeto[codigototal].valor);
        break;
    }
}     

// busca por codigo

void buscacodigo(){
    int codigobusca, j, i, exibirnovamente, achou;
    system("cls");
    printf("-----------------------------------------------------\n");
    printf("                       Busca por código\n"); 
    printf("Informe o código que deseja: ");
    fflush(stdin);
    scanf("%d", &codigobusca);
    achou = 0;
    j = codigobusca;

    while((achou == 0) && (j <= codigototal)){
        if(codigobusca == projeto[j].codigo){
            printf("Código: %d\n", projeto[j].codigo);
            printf("Título: %s\n", projeto[j].titulo);
            printf("Gerente: %s\n", projeto[j].gerente);
            printf("Cliente: %s\n", projeto[j].cliente);
            printf("status: %d\n", projeto[j].status);
            printf("Estimativa do prazo: %d meses\n", projeto[codigototal].estimativa);
            printf("Ano: %d\n", projeto[j].ano);
            printf("Descrição: %s\n", projeto[j].descricao);
            printf("Valor: R$ %.2f\n", projeto[j].valor);
            achou = 1;
        }
        j++;
    }
        if(achou == 0){
            printf("Código %d não foi encontrado!\n", codigobusca);
            printf("Tente outro cÃ³digo: \n");
        }

    printf("-----------------------------------------------------\n");
    printf("Deseja fazer uma nova busca:  1 - SIM | 2 - NÃO\n");
    fflush(stdin);
    scanf("%d", &exibirnovamente);

    switch (exibirnovamente){
    case 1:
        buscacodigo();
        break;
    default:
        printf("Retornando ao menu");
        system("cls");
        break;
    }
}

// busca por nome

void buscanome(){
    char nome[30];
    int j, i, exibirnovamente, achou;
    system("cls");
    printf("Informe o nome do cliente(idêntico ao cadastrado): \n");
    fflush(stdin);
    gets(nome);

    achou = 0;
    j = 0;

    while ((achou == 0) && (j <= codigototal)){
        if(strcmp(projeto[j].cliente,nome)==0){
            printf("-----------------------------------------------------\n");
            printf("Código: %d\n", projeto[j].codigo);
            printf("Título: %s\n", projeto[j].titulo);
            printf("Gerente: %s\n", projeto[j].gerente);
            printf("Cliente: %s\n", projeto[j].cliente);
            printf("status: %d\n", projeto[j].status);
            printf("Estimativa do prazo: %d meses\n", projeto[codigototal].estimativa);
            printf("Ano: %d\n", projeto[j].ano);
            printf("Descrição: %s\n", projeto[j].descricao);
            printf("Valor: R$ %.2f\n", projeto[j].valor);
            achou = 1;
        }
        j++;
    }
    if(achou == 0){
        printf("Cliente não encontrado!\n", nome);
        printf("\n");
    }
    printf("-----------------------------------------------------\n");
    printf("Deseja fazer uma nova busca: 1 - SIM | 2 - NÃO\n");
    fflush(stdin);
    scanf("%d", &exibirnovamente);

    switch (exibirnovamente){
    case 1:
        buscanome();
        break;
    
    default:
        printf("Retornando ao menu");
        system("cls");
        break;
        }
}


// listar todos projetos
void listarprojetos(){
    int i;
    system("cls");
    printf("Listando todos os projetos...\n");
    printf("-----------------------------------------------------\n");
    for (i = 0; i <= codigototal; i++){
        printf("Código: %d\n", projeto[i].codigo);
        printf("Título: %s\n", projeto[i].titulo);
        printf("Gerente: %s\n", projeto[i].gerente);
        printf("Cliente: %s\n", projeto[i].cliente);
        printf("Status: %d\n", projeto[i].status);
        printf("Estimativa do prazo: %d meses \n", projeto[codigototal].estimativa);
        printf("Ano: %d\n", projeto[i].ano);
        printf("Descrição: %s\n", projeto[i].descricao);
        printf("Valor: R$ %.2f\n", projeto[i].valor);
        printf("-----------------------------------------------------\n");
    }
}

// Listar projeto por status

void listarstatus(){
    int escolhastatus, statusnovamente, i;
    system("cls");
    printf("----------------------------------------------------------------\n");
    printf("                      Busca por status\n");
    printf("        1 - A FAZER | 2 - EM ANDAMENTO | 3 - CONCLUIDO\n");
    printf("----------------------------------------------------------------\n");
    fflush(stdin);
    scanf("%d", &escolhastatus);
    i=0;

    switch (escolhastatus){
    case 1:
        system("cls");
        printf("Listando projetos A FAZER...\n");
        printf("\n");
        for(i = 0; i <= codigototal; i= i + 1){
        if((projeto[i].status != 2,3) && (projeto[i].status == 1)){
        printf("-----------------------------------------------------\n");
        printf("Código: %d\n", projeto[i].codigo);
        printf("Título: %s\n", projeto[i].titulo);
        printf("Gerente: %s\n", projeto[i].gerente);
        printf("Cliente: %s\n", projeto[i].cliente);
        printf("status: %d\n", projeto[i].status);
        printf("Estimativa do prazo: %d meses\n", projeto[codigototal].estimativa);
        printf("Ano: %d\n", projeto[i].ano);
        printf("Descrção: %s\n", projeto[i].descricao);
        printf("Valor: R$ %.2f\n", projeto[i].valor);
        printf("\n");
            }
    }
        printf("Deseja visualizar outros projetos: 1 - SIM | 2 - NÃO\n");
        fflush(stdin);
        scanf("%d", &statusnovamente);
        switch (statusnovamente){
        case 1:
            listarstatus();
            break;
        default:
            system("cls");
            break;
        }
        break;

    case 2:
        system("cls");
        printf("Listando projetos EM ANDAMENTO...\n");
        printf("\n");
        for(i = 0; i <= codigototal; i= i + 1){
        if((projeto[i].status != 1,3) && (projeto[i].status == 2)){
        printf("-----------------------------------------------------\n");
        printf("Código: %d\n", projeto[i].codigo);
        printf("Título: %s\n", projeto[i].titulo);
        printf("Gerente: %s\n", projeto[i].gerente);
        printf("Cliente: %s\n", projeto[i].cliente);
        printf("status: %d\n", projeto[i].status);
        printf("Estimativa do prazo: %d meses\n", projeto[codigototal].estimativa);
        printf("Ano: %d\n", projeto[i].ano);
        printf("Descrição: %s\n", projeto[i].descricao);
        printf("Valor: R$ %.2f\n", projeto[i].valor);
            }
    }
        printf("Deseja visualizar outros projetos: 1 - SIM | 2 - NÃO\n");
        fflush(stdin);
        scanf("%d", &statusnovamente);
        switch (statusnovamente){
        case 1:
            listarstatus();
            break;
        default:
            system("cls");
            break;
        }

        break;

    
    case 3:
        system("cls");
        printf("Listando projetos CONCLUIDOS...\n");
        printf("\n");
        for(i = 0; i <= codigototal; i= i + 1){
        if((projeto[i].status != 1,2) && (projeto[i].status == 3)){
        printf("-----------------------------------------------------\n");
        printf("Código: %d\n", projeto[i].codigo);
        printf("Título: %s\n", projeto[i].titulo);
        printf("Gerente: %s\n", projeto[i].gerente);
        printf("Cliente: %s\n", projeto[i].cliente);
        printf("status: %d\n", projeto[i].status);
        printf("Estimativa do prazo: %d meses\n", projeto[codigototal].estimativa);
        printf("Ano: %d\n", projeto[i].ano);
        printf("Descrição: %s\n", projeto[i].descricao);
        printf("Valor: R$ %.2f\n", projeto[i].valor);
            }
    }
        printf("Deseja visualizar outros projetos: 1 - SIM | 2 - NÃO\n");
        fflush(stdin);
        scanf("%d", &statusnovamente);
        switch (statusnovamente){
        case 1:
            listarstatus();
            break;
        default:
            system("cls");
            break;
        }
        break;
    }    
}

 
// CORPO PROGRAMA 
int main(void){  
    setlocale(LC_ALL, "Portuguese");
    codigototal = 0;
    do {
        printf("\n**********************************************");
        printf("\n          Hub de Projetos - JURAZEK");
        printf("\n**********************************************");
        printf("\n                   MENU");
        printf("\n 1 - Cadastrar um novo projeto ");
        printf("\n 2 - Buscar por código");
        printf("\n 3 - Buscar por nome do cliente");
        printf("\n 4 - Listar projetos cadastrados");
        printf("\n 5 - Listar projetos por status");
        printf("\n 6 - Sair");

        printf("\n");
        printf("\n");
        fflush(stdin);
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            cadastrarprojeto();
            break;
        
        case 2:
            buscacodigo();
            break;
        case 3:
            buscanome();
            break;
        
        case 4:
            listarprojetos();
            break;

        case 5:
            listarstatus();
            break;
        default:
            printf("encerrando...");
            break;
        }
    } while (escolha != 6);
    return 0;
}
