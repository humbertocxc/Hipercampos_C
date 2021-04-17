#include <stdio.h>
#include "pontos.h"



float pegaCoeficiente(float x2, float y2, float x1, float y1){//encontra o coeficiente da reta entre p2 e p1
    float y = y2-y1;
    float x = x2-x1;
    float m = y/x;
    return m;
}


int compara(const void *a, const void *b){//funcao em relação a que o quick sort ordena
    return (((Ponto *)a)->y - ((Ponto *)b)->y); 
}


void sol(){
    qsort(pontos, NPontos, sizeof(Ponto), compara);//ordena os pontos de forma crescente

    //cria vetor que armazena tamanho máximo de pontos ligados abaixo de cada ponto e seta todos como zero
    int *cauda = malloc(sizeof(int) * (NPontos+1));
    for(int i=0; i<NPontos; i++)
        cauda[i] = 1;
    resolve(cauda);//funcao que encontra maior
}


void resolve(int *cauda){
    Maior = 1;//valor global que armazena o número máximo de pontos ligados com interseção nas âncoras
    float ma, mb, zero = 0;
    for(int n=0; n<NPontos; n++){//roda todos os pontos do menor ao maior
        ma = pegaCoeficiente(A, zero, pontos[n].x, pontos[n].y);
        mb = pegaCoeficiente(B, zero, pontos[n].x, pontos[n].y);
        for(int i=n-1; i>=0; i--){//roda os pontos abaixo do ponto n
            if(cauda[i] >= cauda[n]){//só vai para a função de colisão se a cauda de i for maior ou igual à de n
                if(estaDentro(ma, mb, pontos[n].x, pontos[n].y, pontos[i].x, pontos[i].y)){//funcão que testa colisão
                    cauda[n] = cauda[i] + 1;//caso o ponto esteja dentro, a cauda de n passa a ser cauda[i] + 1
                    if(cauda[n] > Maior){
                        Maior = cauda[n];//variável recebe o valor de cauda[n], quando essa passa a ser a maior encontrada
                        break;
                    }
                }
            }
        }
    }
}


int estaDentro(float ma, float mb, float xa, float ya, float xb, float yb){
    float m, zer=0;//float zer é para comparar com os pontos que são float
    if(ma<zer){//testa se o valor de x do ponto a é menor que A
        m = pegaCoeficiente(xb, yb, xa, ya);//pega coeficiente com xa<xb
        if(xa<xb && m<mb && m>ma)//se o coeficiente estiver dentro e xa<xb retorna 1
            return 1;
        return 0;
    }else if(mb>zer){//testa se o valor de x do ponto a é maior que B
        m = pegaCoeficiente(xa, ya, xb, yb);//pega coeficiente com xa>xb
        if(xa>xb && m<mb && m>ma)//se o coeficiente estiver dentro e xa>xb retorna 1
            return 1;
        return 0;
    }else{//se não for um dos 2, ele está entre A e B
        if(xa>xb){//se estiver no meio, testa se o ponto a está antes do ponto b
            m = pegaCoeficiente(xa, ya, xb, yb);//se xa>xb, pega coeficiente com xa>xb
            if(m>ma)//se o coeficiente for maior que ma retorna 1
                return 1;
            return 0;
        }else{
            m = pegaCoeficiente(xb, yb, xa, ya);//se xa<xb, pega coeficiente com ax<xb
            if(m<mb)//se o coeficiente for menor que mb retorna 1
                return 1;
            return 0;
        }
    }
}