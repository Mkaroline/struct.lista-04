#include <stdio.h> //biblioteca para as funcoes principal printf, scanf,int main , return;
#include <stdlib.h>//biblioteca para malloc , free
typedef struct ingresso
{                      // typedef renomear a estrutura
    int preco;         // declaracao da variavel preco na estrutura ingresso
    char local[100];   // declaracao da variavel local na estrutura ingresso
    char atracao[100]; // declaracao da variavel atracao na estrutura ingresso
} ingresso;

void preecher(ingresso *i)
{ // funcao para prencher os dados de acordo com que o usuario vai informar

    printf("digite o preco do ingresso:\n"); //solicitar ao 
    scanf("%d", &i->preco);                   
    printf("digite o local:\n");
    scanf(" %[^\n]", i->local);    //
    printf("digite a atracao:\n"); // 
    scanf(" %[^\n]", i->atracao);
}

void emprime(ingresso *i)
{ // resultado do que o usuario informou

    printf("preco:%d\n", i->preco);     // nome do usuario
    printf("local:%s\n", i->local);     // 
    printf("atracao:%s\n", i->atracao); // 
}

void alterar_preco(ingresso *i, float valor)
{ // prototipo da funcao onde o valor sera alterado

    i->preco = valor;
}

void imprime_menor_maior_preco(int tam, ingresso *v)
{ // prototipo da funcao que serve para mostra qual eh o maior e o menor preco do ingresso
    int i, j, maior = 0, menor = 0;
    maior = v[0].preco;
    menor = v[0].preco;
    for (i = 0; i < tam; i++)
    { // se o v[i].preco for maior que a variavel maior entao maior vai receber v[i].preco
        if (v[i].preco > maior)
        {
            maior = v[i].preco;
        }
        else if (v[i].preco < menor)
        { // se o v[i].preco for menor que a variavel menor entao menor vai receber v[i].preco
            menor = v[i].preco;
        }
    }
    printf("O maior numero: %d, o menor: %d\n", maior, menor);
}

    void preecherv(int tam, ingresso *v)
    { // funcao para prencher os dados de acordo com que o usuario vai  informar
        int i;
        for (i = 0; i < tam; i++)
        {

            printf("digite o preco do ingresso:\n"); // solicitar ao usuario o preco do ingresso
            scanf("%d", &v[i].preco);// ler e guarda na variavel preco onde o v[i] acessa a variavel preco de struct 
            printf("digite o local:\n"); // solicitar ao usuario o local
            scanf(" %[^\n]", v[i].local); // ler e guarda na variavel  local onde o v[i] acessa a variavel local de struct 
            printf("digite a atracao:\n"); // solicitar ao usuario a atracao 
            scanf(" %[^\n]", v[i].atracao);//// ler e guarda na variavel atracao onde o v[i] acessa a variavel atracao de struct 
        }

        
    }

    int main(void)
    {  // funcao principal
        int tam, n1, escolha; // declaracao das variaveis inteira
        float valor;  // declaracao das variaveis reais
        ingresso i;//declarando a variavel [i] do tipo ingresso
        ingresso *vetor;//declarando o ponteiro de vetor

        printf("Para digitar varios eventos e achar o menor preco entre ele digite 1 \n");
        printf("Para digitar um evento e alterar o preco dele digite 2 \n");
        printf("Escolha: \n");
        scanf("%d", &escolha);
        if (escolha == 1)
        {

            printf("digite a quantidade de evento que vao ser inseridos\n"); // solicitar ao usuario para inserir a quantidade de evento
            scanf("%d", &tam); // guarda o valor na variavel tam

            vetor = (ingresso*) malloc (tam * sizeof(ingresso)); // alocacao dinamica do vetor v
            
            preecherv(tam, vetor);
            imprime_menor_maior_preco(tam, vetor);

        }else if (escolha == 2)
        {

            preecher(&i); // chamando a funcao preecher
            emprime(&i);//chamando a funcao emprime

            printf("Para alterar o preco do evento digite 1. \n");//caso o usuario deseja alterar o valor do preco do ingresso
            scanf("%d", &n1);//gurda o valor na variavel n
            if (n1 == 1)// verificando a resposta do usuario
            {
                printf("digite o novo valor: ");
                scanf("%f", &valor);

                alterar_preco(&i, valor);//

                printf("\n");

                emprime(&i);//chamada da funcao
            }
        }
        
        free(vetor);

     return 0;   
    }
