#ifndef _H_PONTOS
#define _H_PONTOS

#include <math.h>
#include <stdlib.h>



typedef struct Ponto{
    float x;//coordenada x
    float y;//coordenada y
}Ponto;


Ponto *pontos;
int NPontos, Maior;// Quantidade de pontos recebidos e quantidade do maior conjunto possível
float A, B;//Âncoras



float pegaCoeficiente(float x2, float y2, float x1, float y1);
int compara(const void *a, const void *b);
void sol();
void resolve(int *cauda);
int estaDentro(float ma, float mb, float xa, float ya, float xb, float yb);


#endif