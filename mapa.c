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
struct cadastro projeto[4];
int escolha, codigototal;




// cadastrar projeto
int cadastrarprojeto(){     
    int cadnovamente;
    setlocale(LC_ALL, "Portuguese");
    printf("----------------------------------------------------------------\n");
    printf("                    Cadastrar projeto: \n");
    projeto[codigototal+1].codigo = codigototal + 1;
    printf("O codigo do projeto eh: %d\n", codigototal + 1);
    printf("Informe o titulo do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].titulo);
    printf("Informe o status do projeto: 1 - A FAZER | 2 - EM ANDAMENTO | 3 - CONCLUIDO\n");
    fflush(stdin);
    scanf(" %d", &projeto[codigototal+1].status);
    printf("Informe o ano do projeto: \n");
    fflush(stdin);
    scanf("%d", &projeto[codigototal+1].ano);
    printf("Qual o gerente do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].gerente);
    printf("Informe a descricao do projeto: \n");
    fflush(stdin);
    gets(projeto[codigototal+1].descricao);

    codigototal = codigototal + 1;

    printf("Deseja cadastrar outro projeto: 1 - SIM | 2 - NAO | 3 - VISUALIZAR PROJETO \n");
    fflush(stdin);
    scanf("%d", &cadnovamente);

    switch (cadnovamente){
    case 1:
        cadastrarprojeto();
        break;
    
    case 2:
        printf("Retornando ao menu");
        break;

    case 3: 
        printf("----------------------------------------------------------------\n");
        printf("    Ultimo projeto cadastrado\n");
        printf("Codigo: %d\n", projeto[codigototal].codigo);
        printf("Titulo: %s\n", projeto[codigototal].titulo);
        printf("Gerente: %s\n", projeto[codigototal].gerente);
        printf("status: %d\n", projeto[codigototal].status);
        printf("Ano: %d\n", projeto[codigototal].ano);
        printf("Descricao: %s\n", projeto[codigototal].descricao);
        break;
    }
}     

// busca por codigo

void buscacodigo(){
    int codigobusca, j, i, exibirnovamente, achou;
    system("cls");
    printf("----------------------------------------------------------------\n");
    printf("                       Busca por codigo\n"); 
    printf("Informe o codigo que deseja: ");
    fflush(stdin);
    scanf("%d", &codigobusca);
    achou = 0;
    j = codigobusca;

    while((achou == 0) && (j <= codigototal)){
        if(codigobusca == projeto[j].codigo){
            printf("Codigo: %d\n", projeto[j].codigo);
            printf("Titulo: %s\n", projeto[j].titulo);
            printf("Gerente: %s\n", projeto[j].gerente);
            printf("status: %d\n", projeto[j].status);
            printf("Ano: %d\n", projeto[j].ano);
            printf("Descricao: %s\n", projeto[j].descricao);
            achou = 1;
        }
        j++;
    }
        if(achou == 0){
            printf("Codigo %d nao foi encontrado!\n", codigobusca);
            printf("Tente outro codigo: \n");
        }

    printf("----------------------------------------------------------------\n");
    printf("Deseja fazer uma nova busca:  1 - SIM | 2 - NAO\n");
    fflush(stdin);
    scanf("%d", &exibirnovamente);

    switch (exibirnovamente){
    case 1:
        buscacodigo();
        break;
    default:
        for(i = 0; i < 60; i++){
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
        }
        break;
    }
}

// listar todos projetos

void listarprojetos(){
    int i;

    system("cls");
    printf("\nProjetos: ");
    printf("\n-----------------------------------------------");
    for (i = 0; i <= codigototal; i++){
        printf("\nCodigo: %d", projeto[i].codigo);
        printf("\nTitulo: %s", projeto[i].titulo);
        printf("\nGerente: %s", projeto[i].gerente);
        printf("\nstatus: %d", projeto[i].status);
        printf("\nAno: %d", projeto[i].ano);
        printf("\nDescricao: %s", projeto[i].descricao);
        printf("\n-----------------------------------------------\n");
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
        codigototal = 10;
    case 1:
        system("cls");
        printf("Listando projetos A FAZER...\n");
        for(i = 0; i <= codigototal; i= i + 1){
        if((projeto[i].status != 2,3) && (projeto[i].status == 1)){
        printf("----------------------------------------------------------------\n");
        printf("Codigo: %d\n", projeto[i].codigo);
        printf("Titulo: %s\n", projeto[i].titulo);
        printf("Gerente: %s\n", projeto[i].gerente);
        printf("status: %d\n", projeto[i].status);
        printf("Ano: %d\n", projeto[i].ano);
        printf("Descricao: %s\n", projeto[i].descricao);
            }
    }
        printf("Deseja visualizar outros projetos: 1 - SIM | 2 - NAO\n");
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
        for(i = 0; i <= codigototal; i= i + 1){
        if((projeto[i].status != 1,3) && (projeto[i].status == 2)){
        printf("----------------------------------------------------------------\n");
        printf("Codigo: %d\n", projeto[i].codigo);
        printf("Titulo: %s\n", projeto[i].titulo);
        printf("Gerente: %s\n", projeto[i].gerente);
        printf("status: %d\n", projeto[i].status);
        printf("Ano: %d\n", projeto[i].ano);
        printf("Descricao: %s\n", projeto[i].descricao);
            }
    }
        printf("Deseja visualizar outros projetos: 1 - SIM | 2 - NAO\n");
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
        for(i = 0; i <= codigototal; i= i + 1){
        if((projeto[i].status != 1,2) && (projeto[i].status == 3)){
        printf("----------------------------------------------------------------\n");
        printf("Codigo: %d\n", projeto[i].codigo);
        printf("Titulo: %s\n", projeto[i].titulo);
        printf("Gerente: %s\n", projeto[i].gerente);
        printf("status: %d\n", projeto[i].status);
        printf("Ano: %d\n", projeto[i].ano);
        printf("Descricao: %s\n", projeto[i].descricao);
            }
    }
        printf("Deseja visualizar outros projetos: 1 - SIM | 2 - NAO\n");
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


// ordenar por ano 

void ordenarano(){
    printf("\n");
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
        printf("\n 2 - Buscar por codigo");
        printf("\n 3 - Listar projetos cadastrados");
        printf("\n 4 - Listar projetos por status");
        printf("\n 5 - Ordenar por ano");

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
            listarprojetos();
            break;

        case 4:
            listarstatus();
            break;
        case 5:
            ordenarano();
            break;
        default:
            break;
        }

    } while (escolha != 5);
    return 0;
}
