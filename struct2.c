# include  <stdio.h>//biblioteca para funcao principal
# include  <stdlib.h>//biblioteca para operacoes matematica 
# include  <string.h>//biblioteca
# define  MAX  5

typedef  struct aluno{//declaracao da estrutura tipo aluno
     int matricula ;//declaracaoes das variaveis 
    char nome[ 81 ];
    char turma;
    float nota[ 3 ];
     float media ;
} Aluno;

void  inicializa (Aluno **alunos, int n){//funcao que inicializa a variavel aluno e colocar o valor  null em todas as posicoes
	int i;
	for (i= 0 ; i<n; i++){
		alunos[i] = NULL ;
}

void  matricula ( int n, Aluno** alunos){// laco de repeticao para preencher os dados dos usuario
     int i = 0 ;
    if (i<n){
                alunos[i] = (Aluno*) malloc (n* sizeof (Aluno));
                if (alunos[i]== NULL ){
                        printf ( " Memoria cheia \n " );
                        exit ( 1 );
                }
                else {
                    printf ( " Insira a matrícula: \n Insira a turma: \n Insira o nome: \n " );
                    scanf ( "  %d  " , &alunos[i]-> matricula );
                    scanf ( "  %c " , &alunos[i]-> turma );
                    scanf ( " %80[^ \n ] " , alunos[i]-> nome );
                    alunos[i]-> nota [ 0 ]= 0 ;
                    alunos[i]-> nota [ 1 ]= 0 ;
                    alunos[i]-> nota [ 2 ]= 0 ;
                    alunos[i]-> media = 0 ;
                    i++;
                }
            }

    else
    {
      printf ( " Não há vagas " );
    }

}

void  lanca_notas ( int n, Aluno** alunos){//laco de repeticao ler as notas e calcular as media
    int i;
    for (i= 0 ;i<n;i++){
            if (alunos[i]!= NULL ){
                printf ( " Aluno %d " , i+ 1 );
                    printf ( " \n Digite como nota: \n " );
                    scanf ( " %f  %f  %f " , &alunos[i]-> nota [ 0 ], &alunos[i]-> nota [ 1 ], &alunos[i]-> nota [ 2 ]);
                    alunos[i]-> media =(alunos[i]-> nota [ 0 ] + alunos[i]-> nota [ 1 ] + alunos[i]-> nota [ 2 ])/ 3 ;
                    printf ( " Media: %.2f  \n " , alunos[i]-> media );
               }
    }
}

void  imprime_tudo ( int n, Aluno** alunos){//laco de repeticao para imprimir os valores inserido pelo o usuario
    int i;
    for (i= 0 ; i<n; i++){
            if (alunos[i]!= NULL ){
                printf ( " \n Matrícula:   %d  \n " , alunos[i]-> matricula );
                printf ( " Nome: %s  \n " , alunos[i]-> nome );
                printf ( " Turma: %c  \n " , alunos[i]-> turma );
                printf ( " Mídia: %f  \n " , alunos[i]-> media );
                }

    }
}

void  imprime_turma ( int n, Aluno** alunos, char turma){//laco de repeticao imprimir dados da turma
    int i;
    for (i= 0 ;i<n;i++){
        if (alunos[i]!= NULL && alunos[i]-> turma ==turma){
            printf ( " \n Matrícula:   %d  \n " , alunos[i]-> matricula );
            printf ( " Nome: %s  \n " , alunos[i]-> nome );
            printf ( " Turma: %c  \n " , alunos[i]-> turma );
        }
    }
}

void  imprime_turma_aprovados ( int n, Aluno**alunos, char turma){//laco de repeticao para imprimir os alunos aprovados
    int i;
    for (i= 0 ;i<n;i++){
        if (alunos[i]!= NULL && alunos[i]-> turma ==turma){
           if (alunos[i]-> media >= 7 ){
                printf ( " \n Matrícula:   %d  \n " , alunos[i]-> matricula );
                printf ( " Nome: % s  \n " , alunos[i]-> nome );
                printf ( " Media: %f  \n , APROVADO \n " , alunos[i]-> media );
           }
        }
    }
}
int main ( void ){
    Aluno *alunos[MAX]; // Vetor de ponteiros de struct
    inicializa (alunos,MAX);//chamada da funcao 
    matricula (MAX,alunos);//chamada da funcao 
    lanca_notas (MAX, alunos);//chamada da funcao 
    imprime_tudo (MAX,alunos);//chamada da funcao 
    imprime_turma (MAX, alunos, ' a ' );//chamada da funcao 
    imprime_turma_aprovados (MAX,alunos, ' a ' );//chamada da funcao 

return 0 ;
}