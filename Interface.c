#include <locale.h>
#include "Interface.h"

void textcolor (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

void textbackground (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

void tipocursor (int cursor)
{
    HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CURSOR;

    BOOL result;

    CURSOR.dwSize = 1;
    if(cursor == 0)
        CURSOR.bVisible = FALSE;
    else
        CURSOR.bVisible = TRUE;
    result=SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

void textcoloreback (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (fundo << 4));
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int MenuRetorno(char OpcoesRetorno[][31]){
    setlocale(LC_ALL, "Portuguese");
    tipocursor(0);
    int i, OpcaoAtual = 29, Tecla, nOpcoes = 2, N=0;
    gotoxy(29, 24);
    textcoloreback(WHITE, BLUE);
    printf("%14s", " ");
    gotoxy(29, 24);
    for(i = 0; i < nOpcoes; i++){
        printf("%-14s ", OpcoesRetorno[i]);
    }
    while(1){
        textcoloreback(BLUE, WHITE);
        gotoxy(OpcaoAtual, 24); //Coluna, Linha
        printf("%s", OpcoesRetorno[N]);

        Tecla = getTecla(); // Faz a seta andar

        textcoloreback(WHITE, BLUE);
        gotoxy(OpcaoAtual, 24);
        printf("%-14s", OpcoesRetorno[N]);

        if(Tecla == TEC_DIR) OpcaoAtual = OpcaoAtual+15, N++;
        if(Tecla == TEC_ESQ) OpcaoAtual = OpcaoAtual-15, N--;
        if(Tecla == TEC_ENTER) break;

        if(OpcaoAtual < 15) OpcaoAtual = 44, N = 1;
        if(OpcaoAtual > 44) OpcaoAtual = 29, N = 0;
    }

    tipocursor(1);
    setlocale(LC_ALL, "C");
    return OpcaoAtual;
}

int MenuHorizontal(char Opcoes[][31], int nOpcoes){
    tipocursor(0);
    int i, OpcaoAtual = 0, Tecla;
    gotoxy(0, 1);
    textcoloreback(BLUE, WHITE);
    printf("%120s", " ");
    gotoxy(0, 1);
    for(i = 0; i < nOpcoes; i++){
        printf("%-15s ", Opcoes[i]);
    }
    while(1){
        textcoloreback(WHITE, LIGHT_GREEN);
        gotoxy(OpcaoAtual * 16, 1); //Coluna, Linha
        printf("%s", Opcoes[OpcaoAtual]);

        Tecla = getTecla(); // Faz a seta andar

        textcoloreback(BLUE, WHITE);
        gotoxy(OpcaoAtual * 16, 1);
        printf("%-15s", Opcoes[OpcaoAtual]);


        if(Tecla == TEC_DIR) OpcaoAtual++;
        if(Tecla == TEC_ESQ) OpcaoAtual--;
        if(Tecla == TEC_ENTER) break;
        if(Tecla == TEC_ESC){
            OpcaoAtual = -1;
            break;
        }


        if(OpcaoAtual < 0) OpcaoAtual = nOpcoes - 1;
        if(OpcaoAtual >= nOpcoes) OpcaoAtual = 0;
    }


    textcoloreback(WHITE, BLUE);
    tipocursor(1);

    return OpcaoAtual;
}

int MenuVerticalCadastro(char OpcoesCadastro[][31]){
    setlocale(LC_ALL, "Portuguese");
    tipocursor(0);
    int i, X=3, Tecla, OpcaoAtual=3, nOpcao=0;

    for(i = 0; i < 2; i++){
        gotoxy(1 , X);
        textcoloreback(WHITE, BLUE);
        printf("%-10s\n", OpcoesCadastro[i]);
        X++;
    }

    while(1){
        textcoloreback(BLUE, WHITE);
        gotoxy(1, OpcaoAtual);      //Coluna, Linha
        printf("%s", OpcoesCadastro[nOpcao]);

        Tecla = getTecla();         // Faz a seta andar

        textcoloreback(WHITE, BLUE);
        gotoxy(1, OpcaoAtual);
        printf("%-10s", OpcoesCadastro[nOpcao]);

        if(Tecla == TEC_CIMA) OpcaoAtual--, nOpcao--;
        if(Tecla == TEC_BAIXO) OpcaoAtual++, nOpcao++;
        if(Tecla == TEC_ENTER) break;

        if(OpcaoAtual < 3) OpcaoAtual = 4, nOpcao = 1;
        if(OpcaoAtual > 4) OpcaoAtual = 3, nOpcao = 0;
    }

    tipocursor(1);
    setlocale(LC_ALL, "C");
    return OpcaoAtual;
}

int MenuVerticalRotinas(char OpcoesRotinas[][31]){
    setlocale(LC_ALL, "Portuguese");
    tipocursor(0);
    int i, X=3, Tecla, OpcaoAtual=3, nOpcao=0;

    for(i = 0; i < 2; i++){
        gotoxy(16 , X);
        textcoloreback(WHITE, BLUE);
        printf("%-10s\n", OpcoesRotinas[i]);
        X++;
    }

    while(1){
        textcoloreback(BLUE, WHITE);
        gotoxy(16, OpcaoAtual);      //Coluna, Linha
        printf("%s", OpcoesRotinas[nOpcao]);

        Tecla = getTecla();         // Faz a seta andar

        textcoloreback(WHITE, BLUE);
        gotoxy(16, OpcaoAtual);
        printf("%-10s", OpcoesRotinas[nOpcao]);

        if(Tecla == TEC_CIMA) OpcaoAtual--, nOpcao--;
        if(Tecla == TEC_BAIXO) OpcaoAtual++, nOpcao++;
        if(Tecla == TEC_ENTER) break;

        if(OpcaoAtual < 3) OpcaoAtual = 4, nOpcao = 1;
        if(OpcaoAtual > 4) OpcaoAtual = 3, nOpcao = 0;
    }

    tipocursor(1);
    setlocale(LC_ALL, "C");
    return OpcaoAtual;
}

int MenuVerticalRelatorios(char OpcoesRelatorios[][31]){
    tipocursor(0);
    int i, X=3, Tecla, OpcaoAtual=3, nOpcao=0;

    for(i = 0; i < 2; i++){
        gotoxy(32 , X);
        textcoloreback(WHITE, BLUE);
        printf("%-10s\n", OpcoesRelatorios[i]);
        X++;
    }

    while(1){
        textcoloreback(BLUE, WHITE);
        gotoxy(32, OpcaoAtual);      //Coluna, Linha
        printf("%s", OpcoesRelatorios[nOpcao]);

        Tecla = getTecla();         // Faz a seta andar

        textcoloreback(WHITE, BLUE);
        gotoxy(32, OpcaoAtual);
        printf("%-10s", OpcoesRelatorios[nOpcao]);

        if(Tecla == TEC_CIMA) OpcaoAtual--, nOpcao--;
        if(Tecla == TEC_BAIXO) OpcaoAtual++, nOpcao++;
        if(Tecla == TEC_ENTER) break;

        if(OpcaoAtual < 3) OpcaoAtual = 4, nOpcao = 1;
        if(OpcaoAtual > 4) OpcaoAtual = 3, nOpcao = 0;
    }

    tipocursor(1);
    return OpcaoAtual;
}

int getTecla(){
    int ch;
    ch = getch();
    if(ch == 224){
        ch = getch() + 1000;
    }
    return ch;
}

void Borda(int x, int y, int largura, int altura){
    // EsqSup DirSup EsqInf DirInf LHoriz LVertical
    char C[] = "\xda\xbf\xc0\xd9\xc4\xb3";
    int i, j;
    gotoxy(x, y); printf("%c", C[0]);
    for(i = 0; i < largura; i++) printf("%c", C[4]);
    printf("%c", C[1]);
    for(j = 0; j < altura; j++){
        gotoxy(x, y+j+1); printf("%c", C[5]);
        for(i = 0; i < largura; i++) printf(" ");
        printf("%c", C[5]);
    }
    gotoxy(x, y+altura); printf("%c", C[2]);
    for(i = 0; i < largura; i++) printf("%c", C[4]);
    printf("%c", C[3]);
}



