#include "Relatorios.h"
#include "Interface.h"

void RelatoriosSaidas(){
    textcoloreback(WHITE, BLUE);

    Borda(1, 5, 116, 23);
    textcoloreback(BLUE, WHITE);
    Borda(4, 6, 110, 2);
    textcoloreback(WHITE, BLUE);
    Borda(4, 9, 110, 16);

    textcoloreback(BLUE, WHITE);
    gotoxy(7, 7);
    printf("Cliente");
    gotoxy(56 ,7);
    printf("Pe%ca Comprada", 135);
    gotoxy(100 ,7);
    printf("Pre%co da Pe%ca", 135, 135);
    textcoloreback(WHITE, BLUE);

}

void RelatoriosPendentes(){
    textcoloreback(WHITE, BLUE);

    Borda(1, 5, 116, 23);
    textcoloreback(BLUE, WHITE);
    Borda(4, 6, 110, 2);
    textcoloreback(WHITE, BLUE);
    Borda(4, 9, 110, 16);

    textcoloreback(BLUE, WHITE);
    gotoxy(7, 7);
    printf("Cliente");
    gotoxy(45 ,7);
    printf("Servi%co Encomendado", 135);
    gotoxy(85 ,7);
    printf("Status");
    gotoxy(107 ,7);
    printf("Codigo");
    textcoloreback(WHITE, BLUE);

}

int MenuRelatorios(char OpcoesRetorno[][31]){
    tipocursor(0);
    int i, OpcaoAtual = 88, Tecla, nOpcoes = 2, N=0;
    gotoxy(88, 27);
    textcoloreback(WHITE, BLUE);
    printf("%9s", " ");
    gotoxy(88, 27);
    for(i = 0; i < nOpcoes; i++){
        printf("%-9s ", OpcoesRetorno[i]);
    }
    while(1){
        textcoloreback(BLUE, WHITE);
        gotoxy(OpcaoAtual, 27); //Coluna, Linha
        printf("%-6s", OpcoesRetorno[N]);

        Tecla = getTecla(); // Faz a seta andar

        textcoloreback(WHITE, BLUE);
        gotoxy(OpcaoAtual, 27);
        printf("%-6s", OpcoesRetorno[N]);

        if(Tecla == TEC_DIR) OpcaoAtual = OpcaoAtual+10, N++;
        if(Tecla == TEC_ESQ) OpcaoAtual = OpcaoAtual-10, N--;
        if(Tecla == TEC_ENTER) break;

        if(OpcaoAtual < 88) OpcaoAtual = 98, N = 1;
        if(OpcaoAtual > 98) OpcaoAtual = 88, N = 0;
    }

    tipocursor(1);
    return OpcaoAtual;
}


