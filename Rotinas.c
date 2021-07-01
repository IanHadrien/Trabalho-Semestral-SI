#include "Rotinas.h"
#include "Interface.h"

void ListaServicos(){
    textcoloreback(WHITE, BLUE);

    Borda(1, 5, 116, 23);
    textcoloreback(BLUE, WHITE);
    Borda(4, 6, 110, 2);
    textcoloreback(WHITE, BLUE);
    Borda(4, 9, 110, 16);

    textcoloreback(BLUE, WHITE);
    gotoxy(7, 7);
    printf("Codigo");
    gotoxy(25 ,7);
    printf("Descri%c%co", 135, 198);
    gotoxy(80 ,7);
    printf("Pre%co", 135);
    gotoxy(107, 7);
    printf("Tempo");
    textcoloreback(WHITE, BLUE);

    //Codigo
    gotoxy(7, 10); printf("100");
    gotoxy(7, 12); printf("200");
    gotoxy(7, 14); printf("400");
    gotoxy(7, 16); printf("500");
    gotoxy(7, 18); printf("700");
    gotoxy(7, 20); printf("110");
    gotoxy(7, 22); printf("112");
    gotoxy(7, 24); printf("113");

    //Descrição
    gotoxy(25, 10); printf("Formata%c%co de Sistema", 135, 198);
    gotoxy(25, 12); printf("Desistala%c%co de Software", 135, 198);
    gotoxy(25, 14); printf("Atauliza%c%co de Sistemas", 135, 198);
    gotoxy(25, 16); printf("Remo%c%co de Excesso de Poeira", 135, 198);
    gotoxy(25, 18); printf("Organiza%c%co de Cabos Internos", 135, 198);
    gotoxy(25, 20); printf("Troca de Pe%cas Defeituosas", 135);
    gotoxy(25, 22); printf("Limpeza de Arquivos Temporarios");
    gotoxy(25, 24); printf("N%co Sei Meu Problema", 198);

    //Preço
    gotoxy(77, 10); printf("R$ 100,00");
    gotoxy(77, 12); printf("R$ 200,00");
    gotoxy(77, 14); printf("R$ 140,00");
    gotoxy(77, 16); printf("R$ 250,00");
    gotoxy(77, 18); printf("R$ 120,00");
    gotoxy(77, 20); printf("R$ 500,00");
    gotoxy(77, 22); printf("R$ 112,00");
    gotoxy(77, 24); printf("R$ $$$$$$");

    //Tempo
    gotoxy(107, 10); printf("2 Horas");
    gotoxy(107, 12); printf("3 Horas");
    gotoxy(107, 14); printf("2 Horas");
    gotoxy(107, 16); printf("2 Dias");
    gotoxy(107, 18); printf("1 Dia");
    gotoxy(107, 20); printf("3 Dias");
    gotoxy(107, 22); printf("1 Hora");
    gotoxy(107, 24); printf(".......");

}

void ListaPecas(){
    textcoloreback(WHITE, BLUE);

    Borda(1, 5, 116, 23);
    textcoloreback(BLUE, WHITE);
    Borda(4, 6, 110, 2);
    textcoloreback(WHITE, BLUE);
    Borda(4, 9, 110, 16);

    textcoloreback(BLUE, WHITE);
    gotoxy(7, 7);
    printf("Nome");
    gotoxy(30 ,7);
    printf("Marca");
    gotoxy(70 ,7);
    printf("Pre%co", 135);
    gotoxy(86, 7);
    printf("Modelo");
    gotoxy(107, 7);
    printf("Codigo");
    textcoloreback(WHITE, BLUE);

}

int MenuRetornoRotinas(char OpcoesRetornoRotina[][31]){
    tipocursor(0);
    int i, Tecla, nOpcoes = 1, N=0;
    gotoxy(108, 27);
    textcoloreback(WHITE, BLUE);
    printf("%-7s", " ");
    gotoxy(108, 27);
    for(i = 0; i < nOpcoes; i++){
        printf("%-7s ", OpcoesRetornoRotina[i]);
    }
    while(1){
        textcoloreback(BLUE, WHITE);
        gotoxy(108, 27); //Coluna, Linha
        printf("%-7s", OpcoesRetornoRotina[N]);

        Tecla = getTecla(); // Faz a seta andar

        textcoloreback(BLUE, WHITE);
        gotoxy(108, 27);
        printf("%-7s", OpcoesRetornoRotina[N]);

        if(Tecla == TEC_ENTER) break;

    }

    tipocursor(0);
    return 44;
}


