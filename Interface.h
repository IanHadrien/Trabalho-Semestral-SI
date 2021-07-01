#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };


#define TEC_ENTER 13
#define TEC_TAB 9
#define TEC_BACKSPACE 8
#define TEC_ESC 27
#define TEC_DIR 1077
#define TEC_ESQ 1075
#define TEC_BAIXO 1080
#define TEC_CIMA 1072
#define TEC_DEL 1083
#define TEC_END 1079
#define TEC_INSERT 1082
#define TEC_HOME 1071
#define TEC_PAGE_UP 1073
#define TEC_PAGE_DOWN 1081

void textcolor (int iColor);
void textbackground (int iColor);
void tipocursor (int cursor);
void textcoloreback (int letras, int fundo);
void gotoxy(int x, int y);

int MenuHorizontal(char Opcoes[][31], int nOpcoes);

int MenuVerticalCadastro(char OpcoesCadastro[][31]);
int MenuVerticalRotinas(char OpcoesRotinas[][31]);
int MenuVerticalRelatorios(char OpcoesRelatorios[][31]);
int MenuRetorno(char OpcoesRetorno[][31]);

int getTecla();
void Borda(int x, int y, int largura, int altura);

#endif // INTERFACE_H_INCLUDED
