#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "arquivos.h"



int abreArq(int argc, char **argv, char *nIn, char *nOut){
    int op;

    /*testa se os arquivos foram colocados, caso não mostra mensagem e sai do programa*/
    if(argc < 5){
        ERRO();
    }

    while((op = getopt(argc, argv, "i:o:")) != -1){//lê as entratas apenas até o -o
        switch (op) {
            case 'i':
                strcpy(nIn, optarg);//copia nome do arquivo de entrada para nIn
                break;
            case 'o':
                strcpy(nOut, optarg);//copia nome do arquivo de saida para nOut
                break;
            default:
                fprintf(stderr, "Entrada errada: `%c'\n", optopt);//se não foi informado -i ou -o, mostra mensagem de erro e sai
                return -1; 
                break;
        }
    }
    return EXIT_SUCCESS;
}


void ERRO(){
    fprintf(stderr, "ENTRADA INVÁLIDA!\nUse -i para arquivo de entrada e -o para o arquivo com o resultado\n\n");
    exit(-1);
}


void leitura(char *nIn) {
    FILE *arq_Entrada = fopen(nIn, "r");

    fscanf(arq_Entrada, "%d %f %f\n", &NPontos, &A, &B);//lê primeira linha e salva nas variáveis globais NPontos, A e B
    if((NPontos >1000000) || A >= B || B >10000 || A < 0) {//testa se os valores estão dentro do limite
        printf("Entrada inválida, tente outro arquivo\n");
        exit(0);
    }

    pontos = (Ponto *)malloc(NPontos * sizeof(Ponto));

    for(int i = 0; i < NPontos; i++)//roda as n linhas informadas no começo do arquivo 
        fscanf(arq_Entrada, "%f %f\n", &(pontos[i].x), &(pontos[i]).y);//lê os valores do arquivo e passa para as coordenadas do ponto

    fclose(arq_Entrada);
}
