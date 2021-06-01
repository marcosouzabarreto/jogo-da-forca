#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listase.h"
#include "marco.h"

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

int comparaListas(tp_listase *l1, tp_listase *l2){
    tp_listase *atu;
    tp_listase *atu2;
    atu = l1;
    atu2 = l2;
    /*
     * Enquanto as listas não estiverem vazias
     * compara a info do nó de uma com a info do nó de outra
     * se forem diferentes, retorna 0, senao, continua
     *
     * No fim, quando acabar o while, um if verifica se alguma lista é maior que outra
     * verificando o atu dos 2, se algum dos atus não forem nulos, significa que uma lista é maior
     * do que a outra
     *
     * No fim de tudo, se as pilhas passarem todas as verificacões
     * significa que são iguais, assim retornando 1
     */
    while ((atu != NULL)&&(atu2 != NULL)) {
        if (atu -> info != atu2 -> info) return 0;

        atu = atu->prox;
        atu2 = atu2->prox;
    }
    if (((atu == NULL)&&(atu2 != NULL)||(atu2==NULL)&&(atu!=NULL))) return 0;
    return 1;
} // Comentada!

// Apenas funções de desenho, utilizando o gotoxy
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
    // Inicializar cor
    system("color 0");
    while (true){

        desenhaPessoa();
        //Inicializando lista
        tp_listase *listaPalavraSecreta = aloca_listase();

        //Declaração de variáveis
        char palavraSecreta[64]; // Declarar palavra secreta
        int iguais;
        int op;
        int tentativasTotais = 6;
        int tentativaAtual = 0;
        int acertou = 0;

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
            palavraNaLista(palavraSecreta, &listaPalavraSecreta);

            //Limpando a tela
            system("cls");

            //Enquanto a tentativa atual for menor que tentativa total, executa o loop
            while (tentativaAtual < tentativasTotais){

                //Switch para desenhar o boneco de acordo com a tentativa
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
                    default:
                        break;
                }

                // Alocando lista de tentativa
                tp_listase *listaTentativa = aloca_listase();

                char tentativa[64]; // Declarar string da tentativa

                //Pede a tentativa, pega a tentativa e desenha qual a tentativa atual
                gotoxy(4, 3);
                printf("Digite a sua tentativa\n");
                gotoxy(45, 3);
                printf("Tentativa %i de %i", tentativaAtual+1, tentativasTotais);
                pegaPalavra(tentativa);

                //Poe a palavra na lista para comparar
                palavraNaLista(tentativa, &listaTentativa);

                //Compara as listas, se iguais == 1, são iguais, senao, são falsas
                iguais = comparaListas(listaTentativa, listaPalavraSecreta);

                if (iguais==1) {
                    //Se forem iguais, põe a variável acertei como 1, ela será usada depois
                    acertou = 1;
                    //Sai do loop de tentativas, pois se a pessoa acertou ela não precisa mais adivinhar a palavra
                    break;
                } else {
                    //Se não forem iguais, printa "Palavra incorreta"
                    gotoxy(4, 7);
                    printf("Palavra incorreta\n");
                    gotoxy(4, 8);

                    system("pause");
                    system("cls");
                }

                /* Aumenta 1 no contador de tentativa atual e destroi a lista da tentativa
                 * para poder se criar uma nova
                 */
                tentativaAtual++;
                destroi_listase(&listaTentativa);
            }
        if (acertou == 0){
            //Se a pessoa não acertou até o fim das tentativas, desenha perdeu
            desenhaPerdeu();

        } else {
            //Se ela acertou, a variável acertou vai ser != 0, assim entrando nesse else
            //Que limpa a tela e desenha os parabéns
            system("cls");
            desenhaParabens();
        }
    }

} // Comentada!