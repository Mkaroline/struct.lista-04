#include <stdio.h>//biblioteca para funcao principal
#include <stdlib.h>//biblioteca para as funcoes
#include <math.h>//biblioteca para as operacoes matematicas


typedef struct retangulo{//typedef renomear a estrutura para retangulo
    float b;//declaracao das variaveis b e alt de tipo real
    float alt;
} Ret;

typedef struct circulo{// renomear a estrutura para circulo
    float R;//declaracao da variavel raio do tipo real
} Circ;

Ret * ret_circunscrito(Circ *c, float h){ //prototipo da funcao
	
    Ret *r= malloc(sizeof(Ret));//alocacao dinamica do vertor r
    
    r->b = 2 * sqrt(pow(c->R, 2) - pow(h, 2));// formula para encontar o valor da base
    
    r->alt = h;//estrutura receber altura que receber h
    return r; // retorna r
}

Circ * circ_interno(Ret *r){ //prototipo da funcao

    Circ *c = malloc(sizeof(Circ));//alocacao dinamica do vetor r 
    
    c -> R = sqrt(pow(r ->b, 2) + pow(r->alt, 2)) / 2;//a estrutura acessa a variavel raio que recebe a formula do raio
    return c;// retorna c
}


int main(void){//funcao principal
	
    Circ *c = malloc(sizeof(Circ));
    c -> R = 5;//a estrutura acessa a variavel raio que recebe o valor 5
    
    Ret *r = ret_circunscrito(c, 3);//chamada da funcao 
    
    //imprimindo os resultado do valor da base e da altura
    
	printf("O valor da base eh: %f ", r->b); 
    printf("A altura eh: %f ", r->alt);
    
    free(c);//liberar c 
    free(r);//liberar r 
    return 0;
}

