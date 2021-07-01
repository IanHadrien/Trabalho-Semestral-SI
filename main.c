#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "Interface.h"

#include "Clientes.h"
#include "Pecas.h"

#include "Rotinas.h"
#include "Relatorios.h"
#include "EntradaDados.h"

void DesenharPrincipal(){
    textcoloreback(WHITE, BLUE);
    system("cls");
    gotoxy(45, 0);
    textcoloreback(WHITE, LIGHT_GREEN);
    printf("Manuten%c%co de Computadores", 135, 198);

    textcoloreback(WHITE, BLUE);
}

void DesenharLogo(){
    textcoloreback(WHITE, BLUE);
    printf("\n\n\n\n\n\n\n");
    printf("                               ___                      "); printf("  MMMM             MMMM          CCCCCCCCCCCCCCC\n");
    printf("                              /   \\                    "); printf("   MMMMM           MMMMM        CCCCCCCCCCCCCCCCC\n");
    printf("                              |00 /                     "); printf("  MMMMMM         MMMMMM       CCCCCCCCC\n");
    printf("                             __\\=/__                   "); printf("   MMMMMMM       MMMMMMM      CCCCCCCCC\n");
    printf("         _____           #  /   _   \\                  "); printf("   MMMM MMM     MMM MMMM     CCCCCCCC \n");
    printf("        /   <>\\          \\\\//| /*\\ |\\\\            "); printf("        MMMM  MMM  MMM   MMMM     CCCCCC  \n");
    printf("      _|_______|_         \\/  \\___/  ||               "); printf("    MMMM    MMMMM    MMMM     CCCCCC   \n");
    printf("     | |  ===  | |           |\\   /| ||                "); printf("   MMMM     MMM     MMMM     CCCCCC  \n");
    printf("     |_|   0   |_|           \\__ __/ #                 "); printf("   MMMM      M      MMMM     CCCCCC   \n");
    printf("      ||   0   ||            |  |  |                    "); printf("  MMMM             MMMM     CCCCCC    \n");
    printf("      ||___*___||            |  |  |                    "); printf("  MMMM             MMMM     CCCCCCC    \n");
    printf("     |~ \\_____/ ~|           [ ]|[ ]                   "); printf("   MMMM             MMMM      CCCCCCCCC    \n");
    printf("     /=\\  /=\\  /=\\           |  |  |                 "); printf("     MMMM             MMMM       CCCCCCCCC      \n");
    printf(" ____[_]__[_]__[_]__________/_]___[_\\_______________   "); printf("   MMMM             MMMM        CCCCCCCCCCCCCCCCCC     \n");
    printf("                                                        "); printf("  MMMM             MMMM          CCCCCCCCCCCCCCCC\n");

    textcoloreback(WHITE, BLUE);
}

int main(){

    CadastroCliente Cliente;
    CadastroPeca Peca;

    int Escolha = 0, EscolhaCadastro, EscolhaRot, EscolhaRel;
    int Retorno, Codigo;

    char OpcoesPrincipal[][31] = {" Cadastros", "Rotinas", "Relatorios", "Sair"};
    char OpcoesCadastro[][31] = {"Clientes", "Peças"};
    char OpcoesRotinas[][31] = {"Serviços", "Preços"};
    char OpcoesRelatorios[][31] = {"Pendentes", "Saidas"};

    char OpcoesRetorno[][31] = {"Novo Cliente", "Voltar"};
    char OpcoesRetorno2[][31] = {"Nova Peça", "Voltar"};
    char OpcoesRetornoRelatorios[][31] = {"Alterar", "Voltar"};
    char OpcoesRetornoRotina[][31] = {"Voltar"};

    // Repetição para voltar no Menu

    AbrirCliente();
    AbrirPecas();

    while(Escolha != 3){
        DesenharPrincipal();
        DesenharLogo();
        Escolha = MenuHorizontal(OpcoesPrincipal, 4);

        // Inicio dos Cadastros
        Retorno = 0;
        if(Escolha == 0){
            textcoloreback(WHITE ,BLUE);
            Borda(0, 2, 10, 3);
            EscolhaCadastro = MenuVerticalCadastro(OpcoesCadastro);
            if(EscolhaCadastro == 3){
                while(Retorno != 44){
                    textcoloreback(WHITE, BLUE);

                    Cliente = DigitarCliente();

                    Codigo = CondicoesSalvar(Cliente);
                    if(Codigo == 1){
                        SalvarClientes(Cliente);
                    }

                    Retorno = MenuRetorno(OpcoesRetorno);
                }
            }else{
                while(Retorno != 44){
                    textcoloreback(WHITE, BLUE);

                    Peca = DigitarPeca();

                    Codigo = CondicoesSalvarPeca(Peca);
                    if(Codigo == 1){
                        SalvarPeca(Peca);
                    }

                    Retorno = MenuRetorno(OpcoesRetorno2);
                }
            }
        }
        // Fim dos Cadastros

        // Inicio Rotinas
        if(Escolha == 1){
            textcoloreback(WHITE, BLUE);
            Borda(15, 2, 10, 3);
            EscolhaRot = MenuVerticalRotinas(OpcoesRotinas);

            if(EscolhaRot == 3){
                while(Retorno != 44){
                    ListaServicos();
                    Retorno = MenuRetornoRotinas(OpcoesRetornoRotina);
                }
            }else{
                while(Retorno != 44){
                    ListaPecas();
                    ImprimirPeca();
                    Retorno = MenuRetornoRotinas(OpcoesRetornoRotina);
                }
            }

        }
        // Fim Rotinas

        // Inicio Relatorios
        if(Escolha == 2){
            textcoloreback(WHITE, BLUE);
            Borda(31, 2, 10, 3);
            EscolhaRel = MenuVerticalRelatorios(OpcoesRelatorios);

            if(EscolhaRel == 3){
                while(Retorno != 98){
                    RelatoriosPendentes();
                    ImprimirCliente();
                    Retorno = MenuRelatorios(OpcoesRetornoRelatorios);
                    if(Retorno == 88){
                        Alterar();
                    }
                }
            }else{
                while(Retorno != 44){
                    RelatoriosSaidas();
                    ImprimirPecaSaida();
                    Retorno = MenuRetornoRotinas(OpcoesRetornoRotina);
                }
            }

        }
        // Fim Relatorios

    }

    FecharArquivos();
    FecharArquivosClientes();
    return 0;
}
