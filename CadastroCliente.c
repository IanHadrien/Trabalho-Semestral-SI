/*#include "CadastroCliente.h"
#include "Interface.h"

CadastroPeca Pecas[100];
int Qtdepecas = 0;

CadastroCliente Clientes[100];
int Qtdeclientes = 0;

void DigitarCliente(){
    char Nome[101], CPF[51], Contato[51];
    int Codigo;

    Borda(1, 5, 116, 23);

    gotoxy(10, 8);
    printf("   Nome do CLiente: ");
    gotoxy(10, 12);
    printf("    CPF do Cliente: ");
    gotoxy(10, 16);
    printf(" E-mail de Contado: ");
    gotoxy(10, 20);
    printf("Codigo do servi%co: ", 135);

    textcoloreback(BLUE, YELLOW);
    strcpy(Contato, "");
    gotoxy(30, 8); printf("%*s", 20, " ");
    gotoxy(30, 8); printf("%d", Nome);
    gotoxy(30, 12); printf("%*s", 20, " ");
    gotoxy(30, 12); printf("%s", CPF);
    gotoxy(30, 16); printf("%*s", 20, " ");
    gotoxy(30, 16); printf("%s", Contato);
    gotoxy(30, 20); printf("%*s", 10, " ");
    gotoxy(30, 20); printf("%d", Codigo=0);
    textcoloreback(YELLOW, BLUE);

}

CadastroPeca DigitarPeca(){
    CadastroPeca P;

    gotoxy(8, 8);
    printf("Nome da Pe%ca:", 135);
    Borda(28, 7, 30, 2);
    gotoxy(8, 12);
    printf("Marca da Pe%ca:", 135);
    Borda(28, 11, 30, 2);
    gotoxy(8, 16);
    printf("Modelo da Pe%ca:", 135);
    Borda(28, 15, 30, 2);
    gotoxy(8, 20);
    printf("Pre%co da Pe%ca:", 135, 135);
    Borda(28, 19, 30, 2);

    gotoxy(29, 8);
    scanf(" %50[^\n]", P.NomePecas);
    gotoxy(29, 12);
    scanf(" %50[^\n]", P.Marca);
    gotoxy(29, 16);
    scanf(" %50[^\n]", P.Modelo);
    gotoxy(29, 20);
    scanf("%d", &P.Preco);

    gotoxy(8, 24);
    printf("Pe%ca Adicionada!", 135);

    return P;
}


void SalvarPeca(CadastroPeca P){
    Pecas[Qtdepecas++] = P;
}

void ImprimirPeca(){
    int i, L=11;
    for(i = 0; i < Qtdepecas; i++){
        gotoxy(7, L);
        printf("%s", Pecas[i].NomePecas);
        gotoxy(30, L);
        printf("%s", Pecas[i].Marca);
        gotoxy(68, L);
        printf("R$ %.2lf", Pecas[i].Preco);
        gotoxy(86, L);
        printf("%s", Pecas[i].Modelo);
        gotoxy(107, L);
        printf("%d", Pecas[i].CodigoPeca);
        L += 1;
    }
}

void ImprimirPecaSaida(){
    int i, j, L=11;

    for(j = 0; j < Qtdeclientes; j++){
        for(i = 0; i < Qtdeclientes; i++){
            if(Clientes[j].Codigo == Pecas[i].CodigoPeca){
                gotoxy(5, L);
                printf("%s", Clientes[j].Nome);
                gotoxy(40, L);
                printf("%s", Pecas[i].NomePecas);
                gotoxy(75, L);
                printf("R$ %.2lf", Pecas[i].Preco);
                L += 1;
            }
        }
    }

}

void SalvarClientes(CadastroCliente C){
    Clientes[Qtdeclientes++] = C;
}

void ImprimirCliente(){
    int i, L=11;
    for(i = 0; i < Qtdeclientes; i++){

        if(Clientes[i].Codigo==100 || Clientes[i].Codigo==200 || Clientes[i].Codigo==400 || Clientes[i].Codigo==500 || Clientes[i].Codigo==700 || Clientes[i].Codigo==110 || Clientes[i].Codigo==112 || Clientes[i].Codigo==113){

                if(strcmp(Clientes[i].Pendente, "Pendente") == 0){
                    gotoxy(7, L);
                    printf("%s", Clientes[i].Nome);
                    gotoxy(85, L);
                    printf("%s", Clientes[i].Pendente);

                    gotoxy(45, L);
                    if(Clientes[i].Codigo == 100){
                        printf("Formata%c%co de Sistema", 135, 198);
                    }else if(Clientes[i].Codigo == 200){
                        printf("Desistala%c%co de Software", 135, 198);
                    }else if(Clientes[i].Codigo == 400){
                        printf("Atauliza%c%co de Sistemas", 135, 198);
                    }else if(Clientes[i].Codigo == 500){
                        printf("Remo%c%co de Excesso de Poeira", 135, 198);
                    }else if(Clientes[i].Codigo == 700){
                        printf("Organiza%c%co de Cabos Internos", 135, 198);
                    }else if(Clientes[i].Codigo == 110){
                        printf("Troca de Pe%cas Defeituosas", 135);
                    }else if(Clientes[i].Codigo == 112){
                        printf("Limpeza de Arquivos Temporarios");
                    }else if(Clientes[i].Codigo == 113){
                        printf("N%co Sei Meu Problema", 198);
                    }

                    gotoxy(107, L);
                    printf("%d", Clientes[i].Codigo);
                    L += 1;

            }
        }

    }
}


void Alterar(){
    char NomeDigitado[51];
    int i;

    for(i = 0; i < Qtdeclientes; i++){
        Borda(58, 14, 20, 2);
        gotoxy(40, 15);
        printf("Nome do Cliente: ");
        gotoxy(59, 15);
        scanf(" %50[^\n]", NomeDigitado);

        Borda(58, 19, 20, 2);
        if(strcmp(Clientes[i].Nome, NomeDigitado) == 0){
            gotoxy(40, 20);
            printf("Novo Status: ");
            gotoxy(59, 20);
            scanf(" %50[^\n]", Clientes[i].Pendente);
        }

    }

}


//gotoxy(0, 1); //Coluna, Linha
*/

