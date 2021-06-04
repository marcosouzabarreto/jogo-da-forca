#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include "listase.h"
#include "marco.h"
#include "desenhaboneco.h"

//Definicao de cores
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void palavraNaLista(char *palavra, tp_listase **l){
    int i = 0;
    char e;
    /*
     * Enquanto o i for menor que o tamanho da palavra
     * Eu insiro a letra da posicao [i] da string na lista
    */
    while (i < strlen(palavra)){
        e = palavra[i];
        insere_listase_no_fim(l, e);
        i++;
    }
} // Comentada!

void pegaPalavra(char *palavra) {
    /*
     * Apenas uma função para pegar uma palavra
     */
    gotoxy(4, 6);

    fflush(stdin); //Fflush aqui para corrigir o erro do gets
    gets(palavra);
    fflush(stdin); // Limpando o buffer
} // Comentada!

void pegaLetra(char *palavra) {
    /*
     * Apenas uma função para pegar uma letra
     */
    gotoxy(4, 6);
    fflush(stdin);
    *palavra = getchar();
    fflush(stdin);
} // Comentada!

int comparaListas(char e, tp_listase *l, int *qDeLetras){
    tp_listase *atu;
    atu = l;
    int pos = 1;
    while ((atu != NULL)&&(atu -> info != e)) {
        atu = atu->prox;
        pos++;
    }

    if (atu == NULL) return 0;
    return pos;
}

// Apenas funções de desenho, utilizando o gotoxy


int main() {
    // Inicializar cor
    system("color 0");
    while (true){

        desenhaPessoa();
        //Inicializando lista
        tp_listase *listaPalavraSecreta = aloca_listase();

        //Declaração de variáveis

        char palavraSecreta[64]; // Declarar palavra secreta
        char tentativa;
        int posDosAcertos[64];

        int i;
        for (i=0; i<63;i++) {
            posDosAcertos[i]=0;
        }

        int iguais;
        int letrasAcertadas = 0;
        int letrasTotais;
        int op;
        int tentativasTotais = 6;
        int tentativaAtual = 0;
        int ganhou= 0;
        int j;
        int qDeLetras=0;

        //Escrevendo a frase "Digite 1 para jogar e 0 para sair, utilizando as cores verde e vermelho"
        gotoxy(4,2);
        printf(GRN "Digite 1 para jogar " RESET);
        printf("e ");
        printf(RED "0 para sair\n" RESET);

        gotoxy(4, 3);
        //Escaneando a opção
        scanf("%i", &op);

        //Se opção for 0, sai do aplicativo usando com o código de retorno 0
        if (op==0) {
            return 0;
        } else if (op != 1) { //Se opção for diferente de 1, escreve "Opção inválida e volta ao menu"
            printf("\nOpcao invalida\n");
            system("pause");
            system("cls");
            continue;
        }
            //Pedindo a palavra secreta
            gotoxy(4, 5);
            printf("Digite a palavra secreta\n");

            //Pegando palavra e botando na lista
            pegaPalavra(palavraSecreta);
            letrasTotais = strlen(palavraSecreta);
            palavraNaLista(palavraSecreta, &listaPalavraSecreta);

            //Limpando a tela
            system("cls");

            //Enquanto a tentativa atual for menor que tentativa total, executa o loop
            while (tentativaAtual < tentativasTotais){

                gotoxy(35,4);
                printf("Tentativa %i de %i", tentativaAtual, tentativasTotais);

                for (j=2;j<strlen(palavraSecreta)+2;j++){

                    if (posDosAcertos[j]==1){
                        gotoxy(8+2*j,8);
                        printf("%c", tentativa);
                        posDosAcertos[j]=2;

                    } else if (posDosAcertos[j]!=2){
                        gotoxy(8+2*j,8);
                        printf("_");
                    }
                }
                gotoxy(4, 5);
                printf("Digite a sua tentativa");

                gotoxy(4, 6);
                pegaLetra(&tentativa);
                gotoxy(4, 6);
                printf(" ");
                iguais = comparaListas(tentativa, listaPalavraSecreta, &qDeLetras);


                if ((iguais!=0)&&(posDosAcertos[iguais])==0){
                    letrasAcertadas++;
                    posDosAcertos[iguais]=1;
                    if (letrasAcertadas == letrasTotais){
                        system("cls");
                        desenhaParabens();
                        ganhou=1;
                        break;
                    }
                }  else {
                    tentativaAtual++;
                }

            }
        if (ganhou==0){
            system("cls");
            desenhaPerdeu();
        }

    }

} // Comentada!
