/*

 * Apenas uma biblioteca que criei para mim contendo
 algumas funcoes que eu mais uso

 * Criada por: Marco Aurelio Souza Barreto

 */

#ifndef MAIN_C_UTILS_H
#define MAIN_C_UTILS_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#endif
