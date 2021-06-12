/*
 * Outra biblioteca que criei apenas para desenhar o boneco do jogo da forca, pois o codigo
 * estava ficando baguncado com aquele tanto de funcao de desenho
*/

#ifndef MAIN_C_DESENHABONECO_H
#define MAIN_C_DESENHABONECO_H
#include "marco.h"
#include <stdio.h>
#include <stdlib.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void desenhaMeAjuda(){

        gotoxy(80, 1); printf("  ____________________________");
        gotoxy(80, 2); printf(" /                            \\");
        gotoxy(80, 3); printf("/                              \\");
        gotoxy(80, 4); printf("\\                              /");
        gotoxy(80, 5); printf(" \\____________________________/");
        gotoxy(83, 3); printf(RED "So mais 1 tentativa!!!" RESET);

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
#endif //MAIN_C_DESENHABONECO_H
