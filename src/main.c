#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "arquivos.h"



int main(int argc, char **argv){
    struct rusage buff;

    char *nIn = (char *)malloc(100*sizeof(char));//string com nome do arquivo de entrada
    char *nOut = (char *)malloc(100*sizeof(char));//string com nome do arquivo de saída
    
    abreArq(argc,argv, nIn,nOut);//funcao que testa se os nomes dos arquivos foram indicados, caso sim abre eles

    leitura(nIn);//funcao que passa as coordenadas dos pontos para a lista pontos
    
    sol();//funcao que encontra o maior numero de pontos dentro das linhas

    FILE *arq_saida = fopen(nOut,"a");
    fprintf(arq_saida, "%d\n",Maior);//escreve maior valor possível no arquivo saída
    fclose(arq_saida);//fecha arquivo


    getrusage(RUSAGE_SELF,&buff);//escreve os dados do programa, incluindo o tempo de execução e a memória usada, pegados pelo getrusage
    printf("Maior = %d\nTempo = %lf segundos\nMemória usada = %ld Kb\n\n\n", Maior, (double) buff.ru_utime.tv_sec + (double) buff.ru_utime.tv_usec / (double) 1000000, buff.ru_maxrss);

    //libera a memória alocada
    free(nIn);
    free(nOut);
    free(pontos);

    return 0;
}
