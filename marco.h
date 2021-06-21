/*

 * Apenas uma biblioteca que criei para mim contendo
 algumas funcoes que eu mais uso

 * Criada por: Marco Aurelio Souza Barreto

 */

#ifndef MAIN_C_MARCO_H
#define MAIN_C_MARCO_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

//Função de setar a posicao no console padrão
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Função de pegar um numero aleatorio com base no minimo e maximo
int sorteio ( int min, int max ) {
    srand(time(NULL));
    return rand() % (max + 1 - min) + min ;
}
//Vamo lá q essa é meio grande de explicar
void pega_palavra_aleatoria_de_arquivo(FILE *file, char *local, char *palavra){

    //Declarar variaveis
    char linha[100];

    char *result;

    //Abrir o arquivo com base no local que recebi como parâmetro
    file = fopen(local, "rt");
    //Se não conseguiu abrir, printa isso
    if (file==NULL) {
        system("cls");
        printf("Deu ruim pra abrir a parada parceiro");
        return;
    }

    //Var para contar o n de palavras no arq
    int nDePalavras = 0;

    //Enquando não End of File, continua a ler linhas
    while (!feof(file)){
        result = fgets(linha, 100, file);
        if (result){
            nDePalavras++;
        }

    }

    //Voltar o arquivo ao inicio
    rewind(file);

    //Declara e pega o lugar da palavra escolhida, usando a funcao de sorteio
    int palavraEscolhida;
    palavraEscolhida = sorteio(0, nDePalavras);

    //Vai lendo até chegar no lugar onde está a palavra escolhida
    for (int i = 0; i < palavraEscolhida; ++i) {
        fscanf(file, "%s", palavra);
    }

}



#endif
