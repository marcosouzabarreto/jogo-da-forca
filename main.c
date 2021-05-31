#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listase.h"
#include "utils.h"

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

    while (i < strlen(palavra)){
        e = palavra[i];
        insere_listase_no_fim(l, e);
        i++;
    }
}

void pegaPalavra(char *palavra) {
    fflush(stdin); //Fflush aqui para corrigir o erro do gets

    gotoxy(4, 6);
    gets(palavra);

    fflush(stdin); // Limpando o buffer
}

int comparaListas(tp_listase *l1, tp_listase *l2){
    tp_listase *atu;
    tp_listase *atu2;
    atu = l1;
    atu2 = l2;

    while ((atu != NULL)&&(atu2 != NULL)) {
        if (atu -> info != atu2 -> info) return 0;

        atu = atu->prox;
        atu2 = atu2->prox;
    }

    if (((atu == NULL)&&(atu2 != NULL)||(atu2==NULL)&&(atu!=NULL))) return 0;

    return 1;
}

void desenhaBalaoBoasVindas(){
    gotoxy(80, 1); printf("  ____________________________");
    gotoxy(80, 2); printf(" /                            \\");
    gotoxy(80, 3); printf("/                              \\");
    gotoxy(80, 4); printf("\\                              /");
    gotoxy(80, 5); printf(" \\____________________________/");

    gotoxy(83, 3); printf(CYN "Bem vindo ao Jogo da Forca!" RESET);
}
void desenhaCabecaErrada(){
    gotoxy(60, 1);        printf(RED"       ......." RESET);
    gotoxy(60, 2);        printf(RED"     ...     ..." RESET);
    gotoxy(60, 3);        printf(RED"    ... X   X ..." RESET);
    gotoxy(60, 4);        printf(RED"    ...       ..." RESET);
    gotoxy(60, 5);        printf(RED"     ... XxxX ..." RESET);
    gotoxy(60, 6);        printf(RED"      ...   ..." RESET);
    gotoxy(60, 7);        printf(RED"        ...." RESET);
}
void desenhaCabeca(){
    gotoxy(60, 1);        printf("       ......." );
    gotoxy(60, 2);        printf("     ...     ..." );
    gotoxy(60, 3);        printf("    ... O   O ..." );
    gotoxy(60, 4);        printf("    ...       ...");
    gotoxy(60, 5);        printf("     ...\\___/...");
    gotoxy(60, 6);        printf("      ...   ...");
    gotoxy(60, 7);        printf("        ....");
}
void desenhaCorpo(){
    gotoxy(60, 8);        printf(BLU"        ...."RESET);
    gotoxy(60, 9);        printf(BLU"        ...."RESET);
    gotoxy(60, 10);       printf(BLU"        ...."RESET);
    gotoxy(60, 11);       printf(BLU"        ...."RESET);
    gotoxy(60, 12);       printf(BLU"        ...."RESET);
    gotoxy(60, 13);       printf(BLU"        ...."RESET);
}
void desenhaBracoEsquerdo(){
    gotoxy(60, 8); printf("       .");
    gotoxy(60, 9); printf("      ..");
    gotoxy(60, 10);printf("    ...");
    gotoxy(60, 11);printf("   ...");
    gotoxy(60, 12);printf("  ...");
    gotoxy(60, 13);printf(" ...");
}
void desenhaBracoDireito(){
    gotoxy(72, 8); printf(".");
    gotoxy(72, 9); printf("..");
    gotoxy(73, 10);printf("...");
    gotoxy(74, 11);printf("...");
    gotoxy(75, 12);printf("...");
    gotoxy(76, 13);printf("...");
}
void desenhaPernas() {
    gotoxy(60, 14);       printf(YEL"        ...."RESET);
    gotoxy(60, 15);       printf(YEL"       ......"RESET);
    gotoxy(60, 16);       printf(YEL"      ...  ..."RESET);
    gotoxy(60, 17);       printf(YEL"     ...    ..."RESET);
    gotoxy(60, 18);       printf(YEL"    ...      ..."RESET);
    gotoxy(60, 19);       printf(YEL"   ...        ..."RESET);
    gotoxy(60, 20);       printf(YEL"  ...          ..."RESET);
}


void desenhaPessoaErrada(){
    desenhaCabecaErrada();
    desenhaCorpo();
    desenhaBracoEsquerdo();
    desenhaBracoDireito();
    desenhaPernas();
}

void desenhaParabens() {

    gotoxy(4, 5); printf("  _____                           _                            _   _ ");
    gotoxy(4, 6); printf(" |  __ \\                         | |                          | | | |");
    gotoxy(4, 7); printf(" | |__) |   __ _   _ __    __ _  | |__     ___   _ __    ___  | | | |");
    gotoxy(4, 8); printf(" |  ___/   / _` | | '__|  / _` | | '_ \\   / _ \\ | '_ \\  / __| | | | |");
    gotoxy(4, 9); printf(" | |      | (_| | | |    | (_| | | |_) | |  __/ | | | | \\__ \\ |_| |_|");
    gotoxy(4, 10); printf(" |_|       \\__,_| |_|     \\__,_| |_.__/   \\___| |_| |_| |___/ (_) (_)");

    gotoxy(4, 12);
    system("pause");
    system("cls");

}

void desenhaPerdeu() {
    gotoxy(4, 5); printf("  _____                      _                  _   _ ");
    gotoxy(4, 6); printf(" |  __ \\                    | |                | | | |");
    gotoxy(4, 7); printf(" | |__) |   ___   _ __    __| |   ___   _   _  | | | |");
    gotoxy(4, 8); printf(" |  ___/   / _ \\ | '__|  / _` |  / _ \\ | | | | | | | |");
    gotoxy(4, 9); printf(" | |      |  __/ | |    | (_| | |  __/ | |_| | |_| |_|");
    gotoxy(4, 10); printf(" |_|       \\___| |_|     \\__,_|  \\___|  \\__,_| (_) (_)");

    desenhaPessoaErrada();

    gotoxy(4, 12);
    system("pause");
    system("cls");
}

void desenhaPessoa(){
    desenhaBalaoBoasVindas();
    desenhaCabeca();
    desenhaCorpo();
    desenhaBracoEsquerdo();
    desenhaBracoDireito();
    desenhaPernas();
}

int main() {
    system("color 0");
    while (true){

        desenhaPessoa();
        tp_listase *listaPalavraSecreta = aloca_listase();
        char palavraSecreta[64]; // Declarar palavra secreta
        int iguais;
        int op;
        int tentativasTotais = 6;
        int tentativaAtual = 0;
        int acertou = 0;


        gotoxy(4,2);
        printf(GRN "Digite 1 para jogar " RESET);
        printf("e ");
        printf(RED "0 para sair\n" RESET);

        gotoxy(4, 3);
        scanf("%i", &op);

        if (op==0) {
            return 0;
        } else if (op != 1) {
            printf("\nOpcao invalida\n");
            system("pause");
            system("cls");
            continue;
        }
            gotoxy(4, 5);
            printf("Digite a palavra secreta\n");
            pegaPalavra(palavraSecreta);

            palavraNaLista(palavraSecreta, &listaPalavraSecreta);

            system("cls");

            while (tentativaAtual < tentativasTotais){
                switch (tentativaAtual) {
                    case 1:
                        desenhaCabeca();
                        break;
                    case 2:
                        desenhaCabeca();
                        desenhaCorpo();
                        break;
                    case 3:
                        desenhaCabeca();
                        desenhaCorpo();
                        desenhaBracoDireito();
                        break;
                    case 4:
                        desenhaCabeca();
                        desenhaCorpo();
                        desenhaBracoDireito();
                        desenhaBracoEsquerdo();
                        break;
                    case 5:
                        desenhaCabeca();
                        desenhaCorpo();
                        desenhaBracoDireito();
                        desenhaBracoEsquerdo();
                        desenhaPernas();
                        break;
                }
                tp_listase *listaTentativa = aloca_listase();

                char tentativa[64]; // Declarar tentativa

                gotoxy(4, 3);
                printf("Digite a sua tentativa\n");
                gotoxy(45, 3);
                printf("Tentativa %i de %i", tentativaAtual+1, tentativasTotais);
                pegaPalavra(tentativa);

                palavraNaLista(tentativa, &listaTentativa);

                iguais = comparaListas(listaTentativa, listaPalavraSecreta);

                if (iguais==1) {
                    acertou = 1;
                    break;
                } else {
                    gotoxy(4, 7);
                    printf("Palavra incorreta\n");
                    gotoxy(4, 8);

                    system("pause");
                    system("cls");
                }

                tentativaAtual++;
                destroi_listase(&listaTentativa);
            }
        if (acertou == 0){
            desenhaPerdeu();

        } else {
            system("cls");
            desenhaParabens();
        }
    }

}