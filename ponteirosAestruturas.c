#include <stdio.h>

int main(void){
    struct horario {
        int hora;
        int minuto;
        int segundo;
    };

    struct horario agora, *depois;
    depois = &agora;
    depois->hora = 20;
    depois->minuto = 22;
    depois->segundo = 60;

    int somatorio = 100;

    struct horario antes;

    antes.hora = somatorio + depois->segundo;
    antes.minuto = agora.hora + depois->minuto;
    antes.segundo = depois->minuto + depois->segundo;

    printf("%i:%i:%i", antes.hora, antes.minuto, antes.segundo);

    getchar();
    return 0;
}
