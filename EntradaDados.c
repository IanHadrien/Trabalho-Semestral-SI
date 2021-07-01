#include "Interface.h"

int EntradaInserindo = 1;

int EntradaDados(int x, int y, int Tamanho, char Texto[]){
    int Tecla, Pos;
    char aux[10000];
    gotoxy(x, y);
    textcoloreback(BLUE, WHITE);
    printf("%*s", Tamanho, " ");
    gotoxy(x, y);
    printf("%s", Texto);
    Pos = strlen(Texto);
    gotoxy(67, 0);
    do{
        gotoxy(Pos + x, y);
        Tecla = getTecla();
        if(Tecla == TEC_ENTER) break;
        if(Tecla == TEC_ESQ) Pos--;
        if(Tecla == TEC_DIR) Pos++;
        if(Tecla == TEC_CIMA) break;
        if(Tecla == TEC_BAIXO) break;
        if(Tecla == TEC_ESC) break;
        if(Tecla == TEC_INSERT){
            if(EntradaInserindo == 1) EntradaInserindo = 0;
            else EntradaInserindo = 1;
            gotoxy(67, 0);
        }
        if(Tecla == TEC_BACKSPACE && Pos > 0){
            Pos--;
            strcpy(&Texto[Pos], &Texto[Pos+1]);
            printf("\x08%s ", &Texto[Pos]);

        }
        if(Tecla == TEC_DEL && Pos >= 0 && Texto[Pos] != 0){
            strcpy(&Texto[Pos], &Texto[Pos+1]);
            printf("%s ", &Texto[Pos]);

        }
        if(Tecla >= ' ' && Tecla < 127){
            if(Pos < Tamanho){
                if(EntradaInserindo){
                    // Inserir
                    if(strlen(Texto) < Tamanho){
                        if(Texto[Pos] == 0) Texto[Pos+1] = 0;
                        strcpy(aux, Texto);
                        strcpy(&Texto[Pos+1], &aux[Pos]);
                        Texto[Pos++] = Tecla;
                        printf("%s", &Texto[Pos-1]);
                    }
                }
                else{
                    // Sobrescreve
                    if(Texto[Pos] == 0) Texto[Pos+1] = 0;
                    Texto[Pos++] = Tecla;
                    printf("%c", Tecla);
                }
            }
        }
        if(Pos < 0) Pos = 0;
        if(Pos > Tamanho) Pos = Tamanho;
        if(Pos > 0 && Texto[Pos-1] == 0) Pos--;
    } while(1);

    return Tecla;
}


int EntradaDadosNumeros(int x, int y, int Tamanho, char Texto[]){
    int Tecla, Pos;
    char aux[10000];
    gotoxy(x, y);
    textcoloreback(BLUE, WHITE);
    printf("%*s", Tamanho, " ");
    gotoxy(x, y);
    printf("%s", Texto);
    Pos = strlen(Texto);
    gotoxy(67, 0);
    do{
        gotoxy(Pos + x, y);
        Tecla = getTecla();
        if(Tecla == TEC_ENTER) break;
        if(Tecla == TEC_ESQ) Pos--;
        if(Tecla == TEC_DIR) Pos++;
        if(Tecla == TEC_CIMA) break;
        if(Tecla == TEC_BAIXO) break;
        if(Tecla == TEC_ESC) break;
        if(Tecla == TEC_INSERT){
            if(EntradaInserindo == 1) EntradaInserindo = 0;
            else EntradaInserindo = 1;
            gotoxy(67, 0);
        }
        if(Tecla == TEC_BACKSPACE && Pos > 0){
            Pos--;
            strcpy(&Texto[Pos], &Texto[Pos+1]);
            printf("\x08%s ", &Texto[Pos]);

        }
        if(Tecla == TEC_DEL && Pos >= 0 && Texto[Pos] != 0){
            strcpy(&Texto[Pos], &Texto[Pos+1]);
            printf("%s ", &Texto[Pos]);

        }
        if(Tecla >= ' ' && Tecla < 58){
            if(Pos < Tamanho){
                if(EntradaInserindo){
                    // Inserir
                    if(strlen(Texto) < Tamanho){
                        if(Texto[Pos] == 0) Texto[Pos+1] = 0;
                        strcpy(aux, Texto);
                        strcpy(&Texto[Pos+1], &aux[Pos]);
                        Texto[Pos++] = Tecla;
                        printf("%s", &Texto[Pos-1]);
                    }
                }
                else{
                    // Sobrescreve
                    if(Texto[Pos] == 0) Texto[Pos+1] = 0;
                    Texto[Pos++] = Tecla;
                    printf("%c", Tecla);
                }
            }
        }
        if(Pos < 0) Pos = 0;
        if(Pos > Tamanho) Pos = Tamanho;
        if(Pos > 0 && Texto[Pos-1] == 0) Pos--;
    } while(1);

    return Tecla;
}


int EntradaDadosLetras(int x, int y, int Tamanho, char Texto[]){
    int Tecla, Pos;
    char aux[10000];
    gotoxy(x, y);
    textcoloreback(BLUE, WHITE);
    printf("%*s", Tamanho, " ");
    gotoxy(x, y);
    printf("%s", Texto);
    Pos = strlen(Texto);
    gotoxy(67, 0);
    do{
        gotoxy(Pos + x, y);
        Tecla = getTecla();
        if(Tecla == TEC_ENTER) break;
        if(Tecla == TEC_ESQ) Pos--;
        if(Tecla == TEC_DIR) Pos++;
        if(Tecla == TEC_CIMA) break;
        if(Tecla == TEC_BAIXO) break;
        if(Tecla == TEC_ESC) break;
        if(Tecla == TEC_INSERT){
            if(EntradaInserindo == 1) EntradaInserindo = 0;
            else EntradaInserindo = 1;
            gotoxy(67, 0);
        }
        if(Tecla == TEC_BACKSPACE && Pos > 0){
            Pos--;
            strcpy(&Texto[Pos], &Texto[Pos+1]);
            printf("\x08%s ", &Texto[Pos]);

        }
        if(Tecla == TEC_DEL && Pos >= 0 && Texto[Pos] != 0){
            strcpy(&Texto[Pos], &Texto[Pos+1]);
            printf("%s ", &Texto[Pos]);

        }
        if(Tecla >= ' ' && Tecla > 64 || Tecla == 32){
            if(Pos < Tamanho){
                if(EntradaInserindo){
                    // Inserir
                    if(strlen(Texto) < Tamanho){
                        if(Texto[Pos] == 0) Texto[Pos+1] = 0;
                        strcpy(aux, Texto);
                        strcpy(&Texto[Pos+1], &aux[Pos]);
                        Texto[Pos++] = Tecla;
                        printf("%s", &Texto[Pos-1]);
                    }
                }
                else{
                    // Sobrescreve
                    if(Texto[Pos] == 0) Texto[Pos+1] = 0;
                    Texto[Pos++] = Tecla;
                    printf("%c", Tecla);
                }
            }
        }
        if(Pos < 0) Pos = 0;
        if(Pos > Tamanho) Pos = Tamanho;
        if(Pos > 0 && Texto[Pos-1] == 0) Pos--;
    } while(1);

    return Tecla;
}

