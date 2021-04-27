// Importacoes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"

bool compareWords(tp_pilha *p1, tp_pilha *p2){
    int length1, length2;
    char e1, e2;
    length1 = altura_pilha(p1);
    length2 = altura_pilha(p1);
    if (length1!=length2) return false;
    while (!pilha_vazia(p1)&&!pilha_vazia(p2)){
        pop(p1, &e1);
        pop(p2, &e2);
        if (e1!=e2) return false;
    }
    return true;
}
int main() {
    // Declaracao de variaveis
    char secretWord[512], guess[512];
    int length, i, op;
    bool checker;
    tp_pilha secretWordStack, guessStack;

    while (1) {
        inicializa_pilha(&secretWordStack);
        inicializa_pilha(&guessStack);
        printf("Digite a palavra secreta, digite exit para sair\n");
        gets(secretWord); // Pegar a palavra secreta
        if (strcmp(secretWord, "exit")==0) return 0;

        length = strlen(secretWord);

        for (i = 0; i < length; i++) {
            push(&secretWordStack, secretWord[i]);
        }

        system("cls");

        printf("Digite seu chute\n");
        gets(guess);

        length = strlen(guess);

        for (i = 0; i < length; i++) {
            push(&guessStack, guess[i]);
        }
        checker = compareWords(&secretWordStack, &guessStack);
        checker ? printf("Acertou!\n") : printf("Errou, tente novamente\n");
        system("pause");
        system("cls");
    }

}
