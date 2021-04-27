// Importacoes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"
void stringToStack(tp_pilha *p, int length, char *str) {
    int i;
    for (i = 0; i < length; i++) {
        push(p, str[i]);
    }

}
bool compareWords(tp_pilha p1, tp_pilha p2){
    int length1, length2;
    char e1, e2;
    length1 = altura_pilha(&p1);
    length2 = altura_pilha(&p2);
    if (length1!=length2) return false;
    while (!pilha_vazia(&p1)&&!pilha_vazia(&p2)){
        pop(&p1, &e1);
        pop(&p2, &e2);
        if (e1!=e2) return false;
    }
    return true;
}
int main() {
    // Declaracao de variaveis
    char secretWord[64], guess[64];
    int length, op, guesses, i;
    bool checker;
    tp_pilha secretWordStack, guessStack;
    while (1){
        printf("Digite 1 para jogar, 0 para sair\n");
        scanf("%d", &op);
        if(op==0) return 0;
        printf("Digite o numero de tentativas\n");
        scanf("%d", &guesses);

        printf("Digite a palavra secreta, digite exit para sair\n");
        scanf("%s", secretWord); // Pegar a palavra secreta
        length = strlen(secretWord);
        inicializa_pilha(&secretWordStack);
        stringToStack(&secretWordStack, length, secretWord);

        for(i=0; i<guesses; i++) {

            inicializa_pilha(&guessStack);

            system("cls");

            printf("Digite seu chute\n");
            scanf("%s", guess);

            length = strlen(guess);
            stringToStack(&guessStack, length, guess);

            checker = compareWords(secretWordStack, guessStack);
            if (checker==true){
                printf("Parabens, vc acertou!\n");
                system("pause");
                system("cls");
                break;
            } else {
                printf("Perdeu\n");
            }
            system("pause");
            system("cls");
        }
    }
}
