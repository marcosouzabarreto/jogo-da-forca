#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listase.h"
#include "marco.h"
#include "desenhaboneco.h"

//Definicao de cores
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define CYN   "\x1B[36m"

#define RESET "\x1B[0m"

void palavraNaLista(char *palavra, tp_listase **l) {
    int i = 0;
    char e;
    /*
     * Enquanto o i for menor que o tamanho da palavra
     * Eu insiro a letra da posicao [i] da string na lista
    */
    while (i < strlen(palavra)) {
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

int verificaLetrasRepetidas(char e, tp_listase *l) {
    /* Essa função serve apenas para quando tiver letras repetidas na mesma palavra
     * essa função contará quantas letras repetidas tem
     */
    int qDeLetras = 0;
    tp_listase *atu;
    atu = l;

    while ((atu != NULL)) {
        if (atu->info == e) qDeLetras++;
        atu = atu->prox;
    }
    return qDeLetras;
}

int comparaListas(char e, tp_listase *l) {
    /*
     * Essa função recebe o caractere e a lista, percorrendo a lista ele vê se acha o caractere lá,
     * se não achar, retorna 0, se achar, retorna a posição do acerto
     */
    tp_listase *atu;
    atu = l;
    int pos = 1;

    while ((atu != NULL) && (atu->info != e)) {
        atu = atu->prox;
        pos++;
    }

    if (atu->info == e) atu->info = NULL;
    // Quando ele acha, ele transforma aquele info em NULL, para da proxima vez q essa funcao
    // for chamada, ele não parar nesse caractere
    if (atu == NULL) return 0;
    return pos;

} // Comentada!


void printaCoisasNaTela(int j, char *palavraSecreta, int *posDosAcertos,
                        char tentativa) {
//A função serve para imprimir na tela o tanto de caracteres como _,
//e se algum caractere já foi encontrado, ele bota o caractere no lugar do _

    for (j = 2; j < strlen(palavraSecreta) + 2; j++) {

        if (posDosAcertos[j] == 1) {
            gotoxy(8 + 2 * j, 8);
            printf("%c", tentativa);
            posDosAcertos[j] = 2;

        } else if (posDosAcertos[j] != 2) {
            gotoxy(8 + 2 * j, 8);
            printf("_");
        }
    }
} // Comentado!

int escolhe_tema(char *palavraSecreta) {
    /*
     * Função que escolhe o tema das palavras randômicas
     * essa função pega_palavra_aleatoria_de_arquivo está na biblioteca marco.h
     * Já tá tudo comentado lá tambem
     */
    int op;
    int foi = 0;

    //Criando as var FILE e as inicializando
    FILE *arqEsportes;
    arqEsportes = fopen("res\\esportes.txt", "rt");

    FILE *arqComidas;
    arqComidas = fopen("res\\comidas.txt", "rt");

    FILE *arqPaises;
    arqPaises = fopen("res\\paises.txt", "rt");

    FILE *arqAnimais;
    arqAnimais = fopen("res\\animais.txt", "rt");

    gotoxy(4, 7);
    printf("Digite 1 para a categoria ESPORTES\n");

    gotoxy(4, 8);
    printf("Digite 2 para a categoria COMIDAS\n");

    gotoxy(4, 9);
    printf("Digite 3 para a categoria PAISES\n");

    gotoxy(4, 10);
    printf("Digite 4 para a categoria ANIMAIS\n");

    gotoxy(4, 12);
    printf("**Nenhuma dessas palavras vai considerar a acentuacao**");

    gotoxy(4, 14);
    scanf("%i", &op);


    //Dependendo da opção escolhida pelo usuário, ele chama a função com args diferentes
    switch (op) {
        case 1:
            pega_palavra_aleatoria_de_arquivo(arqEsportes, "res\\esportes.txt", palavraSecreta);
            foi = 1;
            break;
        case 2:
            pega_palavra_aleatoria_de_arquivo(arqComidas, "res\\comidas.txt", palavraSecreta);
            foi = 1;
            break;
        case 3:
            pega_palavra_aleatoria_de_arquivo(arqPaises, "res\\paises.txt", palavraSecreta);
            foi = 1;
            break;
        case 4:
            pega_palavra_aleatoria_de_arquivo(arqAnimais, "res\\animais.txt", palavraSecreta);
            foi = 1;
            break;

        default:
            system("cls");
            printf("Alternativa Invalida\n\n");
            system("pause");
            system("cls");

    }
    //Retorna esse foi para ver se alguma opção válida foi selecionada
    return foi;
} // Comentada!

int main() {
    // Inicializar cor
    system("color 0");


    while (true) {

        desenhaPessoa();
        //Inicializando lista
        tp_listase *listaPalavraSecreta = aloca_listase();

        //Declaração de variáveis

        char palavraSecreta[64];
        char tentativa;
        int posDosAcertos[64];

        //Inicialização do vetor posDosAcertos
        for (int i = 0; i < 63; i++) {
            posDosAcertos[i] = 0;
        }

        //Declaração de todas as variáveis
        //N lembro do que metade delas fazem, isso q dá comentar depois
        int iguais;
        int letrasAcertadas = 0;
        int letrasTotais;
        int op;
        int tentativasTotais = 6;
        int tentativaAtual = 0;
        int ganhou = 0;
        int j = 0;
        int qDeLetras;
        int rodadaAcertada = 0;
        int palavraAleatoria = 0;
        int foi;


        //Escrevendo a frase "Digite 1 para jogar e 0 para sair, utilizando as cores verde e vermelho"
        gotoxy(4, 2);
        printf(GRN "Digite 1 para jogar 1x1" RESET);
        gotoxy(4, 3);
        printf(YEL "Digite 2 para escolher palavra aleatoria" RESET);
        gotoxy(4, 4);
        printf("e ");
        printf(RED "0 para sair" RESET);

        gotoxy(4, 5);
        //Escaneando a opção
        scanf("%i", &op);

        //Se opção for 0, sai do aplicativo usando com o código de retorno 0
        if (op == 0) {
            return 0;
        } else if (op != 1 && op != 2) {

            //Se opção for diferente de 1, 2 e 0, escreve "Opção inválida e volta ao menu"

            printf("\nOpção inválida\n");
            system("pause");
            system("cls");
            continue;
        } else if (op == 2) {
            //Escolher tema da palavra randomica
            foi = escolhe_tema(palavraSecreta);
            if (foi == 0) continue;

            //Avisando pro programa q a palavra secreta já foi pega
            palavraAleatoria = 1;
        }
        if (palavraAleatoria == 0) {
            //Se a palavra secreta não foi pega ainda, o programa pega agora
            gotoxy(4, 5);
            printf("Digite a palavra secreta\n");
            //Pegando palavra e botando na lista
            pegaPalavra(palavraSecreta);

        }

        letrasTotais = strlen(palavraSecreta);

        //Botando a palavra na lista
        palavraNaLista(palavraSecreta, &listaPalavraSecreta);


        //Limpando a tela
        system("cls");

        //Enquanto a tentativa atual for menor que tentativa total, executa o loop
        while (tentativaAtual <= tentativasTotais) {

            //Switch para desenhar o boneco com base na tentativa atual
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
                    desenhaBracoEsquerdo();
                    break;
                case 4:
                    desenhaCabeca();
                    desenhaCorpo();
                    desenhaBracoEsquerdo();
                    desenhaBracoDireito();
                    break;
                case 5:
                    desenhaCabeca();
                    desenhaCorpo();
                    desenhaBracoEsquerdo();
                    desenhaBracoDireito();
                    desenhaPernas();
                    break;
                case 6:
                    desenhaCabeca();
                    desenhaCorpo();
                    desenhaBracoEsquerdo();
                    desenhaBracoDireito();
                    desenhaPernas();
                    desenhaMeAjuda();
                    break;
                default:
                    break;
            }

            //Printando a tentativa na tela
            gotoxy(35, 4);
            printf("Tentativa %i de %i", tentativaAtual, tentativasTotais);

            //Printando coisas na tela kkkkk
            printaCoisasNaTela(j, palavraSecreta, posDosAcertos, tentativa);

            // Pegando tentativa
            gotoxy(4, 5);
            printf("Digite a sua tentativa");

            gotoxy(4, 6);
            pegaLetra(&tentativa);

            //Limpando parte do console onde o usuario digitou a tentativa
            gotoxy(4, 6);
            printf("                ");

            //Verificando letras repetidas, expliquei na função verificaLetrasRepetidas
            qDeLetras = verificaLetrasRepetidas(tentativa, listaPalavraSecreta);
            int k = 0;

            //Enquanto ainda tiver letras repetidas, ele executa a funcao
            //De comparar listas denovo
            //Como na funcao eu seto o info do nó como NULL, ele não pega a
            //Mesma letra 2 vezes
            while (k < qDeLetras) {
                rodadaAcertada = 1;
                iguais = comparaListas(tentativa, listaPalavraSecreta);

                //Fazendo a posDosAcertos na posicao q ele achou a letra na palavra
                //ser 1 faz com que o usuário não possa repetir a mesma letra várias
                //vezes
                if ((iguais != 0) && (posDosAcertos[iguais]) == 0) {
                    letrasAcertadas++;
                    posDosAcertos[iguais] = 1;
                }
                k++;
                //Printando coisas na tela
                printaCoisasNaTela(j, palavraSecreta, posDosAcertos, tentativa);
            }

            //Printando mais coisas na tela
            printaCoisasNaTela(j, palavraSecreta, posDosAcertos, tentativa);
            gotoxy(35, 4);
            printf("Tentativa %i de %i", tentativaAtual, tentativasTotais);

            //Se ele não acertou a letra, aumenta 1 na tentativa
            if (rodadaAcertada == 0) tentativaAtual++;

            //Se acertou todas as letras, ganhou
            if (letrasAcertadas == letrasTotais) {

                system("cls");
                desenhaParabens(palavraSecreta);
                ganhou = 1;
                break;

            }
            //Reseta a var rodada acertada como 0
            rodadaAcertada = 0;

        }
        //Se não ganhou, desenha o perdeu
        if (ganhou == 0) {

            system("cls");
            desenhaPerdeu(palavraSecreta);

        }

    }


} // Comentada!