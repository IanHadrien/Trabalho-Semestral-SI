#include "Pecas.h"
#include "Clientes.h"
#include "Interface.h"
#include "EntradaDados.h"

FILE *fpPecas;

// Parte das Peças
CadastroPeca DigitarPeca(){
    CadastroPeca Peca;
    char NomePecas[101], Modelo[51], Marca[51], Texto[101], Codigo[10];
    double Preco;

    Borda(1, 5, 116, 23);

    gotoxy(10, 8);
    printf("      Nome da Pe%ca: ", 135);
    gotoxy(10, 11);
    printf("     Marca da Pe%ca: ", 135);
    gotoxy(10, 14);
    printf("    Modelo da Pe%ca: ", 135);
    gotoxy(10, 17);
    printf("    Codigo da Pe%ca: ", 135);
    gotoxy(10, 20);
    printf("    Pre%co da Pe%ca: ", 135, 135);

    textcoloreback(BLUE, WHITE);
    strcpy(Codigo, "");
    gotoxy(30, 8); printf("%*s", 20, " ");
    gotoxy(30, 8); printf("%d", NomePecas);
    gotoxy(30, 11); printf("%*s", 20, " ");
    gotoxy(30, 11); printf("%s", Marca);
    gotoxy(30, 14); printf("%*s", 20, " ");
    gotoxy(30, 14); printf("%s", Modelo);
    gotoxy(30, 17); printf("%*s", 10, " ");
    gotoxy(30, 17); printf("%s", Codigo);
    gotoxy(30, 20); printf("%*s", 10, " ");
    gotoxy(30, 20); printf("%.2lf", Preco);
    textcoloreback(WHITE, BLUE);

    strcpy(Peca.NomePecas, "");
    strcpy(Peca.Marca, "");
    strcpy(Peca.Modelo, "");
    strcpy(Codigo, "");
    strcpy(Texto, "");

    int Tecla, Opcao = 0;
    do{
        if(Opcao == 0){
            Tecla = EntradaDados(30, 8, 20, Peca.NomePecas);  //VAlOR 1
        }
        else if(Opcao == 1)
            Tecla = EntradaDados(30, 11, 20, Peca.Marca);     //VAlOR 2
        else if(Opcao == 2)
            Tecla = EntradaDados(30, 14, 20, Peca.Modelo);   //VAlOR 3
        else if(Opcao == 3){
            Tecla = EntradaDadosNumeros(30, 17, 10, Codigo);
            Peca.CodigoPeca = atoi(Codigo);
        }
        else if(Opcao == 4){
            Tecla = EntradaDadosNumeros(30, 20, 10, Texto);
            Peca.Preco = atof(Texto);
        }
        if(Tecla == TEC_CIMA) Opcao--;
        if(Tecla == TEC_BAIXO || Tecla == TEC_ENTER) Opcao++;
        if(Opcao < 0) Opcao = 4;
        if(Opcao > 4) Opcao = 0;
    }while(Tecla != TEC_ESC);

    return Peca;
}

void SalvarPeca(CadastroPeca P){

    fseek(fpPecas, 0, SEEK_END);
    fwrite(&P, sizeof(CadastroPeca), 1, fpPecas);
    fflush(fpPecas);

    textcoloreback(WHITE, LIGHT_GREEN);
    gotoxy(8, 24); printf("Peca Cadastrado!");
    textcoloreback(WHITE, BLUE);

}

void ImprimirPeca(){
    int L=10;
    CadastroPeca Pecas;
    fseek(fpPecas, 0, SEEK_SET);                      //Colocar o cursor no inicio
    while(fread(&Pecas, sizeof(CadastroPeca), 1, fpPecas)){

        gotoxy(7, L);
        printf("%s", Pecas.NomePecas);
        gotoxy(30, L);
        printf("%s", Pecas.Marca);
        gotoxy(68, L);
        printf("R$ %.2lf", Pecas.Preco);
        gotoxy(86, L);
        printf("%s", Pecas.Modelo);
        gotoxy(107, L);
        printf("%d", Pecas.CodigoPeca);
        L += 1;

    }
}

void ImprimirPecaSaida(){
    FILE *fpClientes;
    fpClientes = fopen("Clientes.txt", "rb+");
    int i, j, L=10;
    CadastroCliente C;
    CadastroPeca P;

    fseek(fpClientes, 0, SEEK_SET);
    while(fread(&C, sizeof(CadastroCliente), 1, fpClientes)){
        fseek(fpPecas, 0, SEEK_SET);
        while(fread(&P, sizeof(CadastroPeca), 1, fpPecas)){
            if(C.Codigo == P.CodigoPeca){

                gotoxy(7, L); printf("%s", C.Nome);
                gotoxy(56, L); printf("%s", P.NomePecas);
                gotoxy(98, L); printf("R$ %.2lf", P.Preco);
                L += 1;
            }
        }
    }

}


int CondicoesSalvarPeca(CadastroPeca CondicaoP){

    textcoloreback(WHITE, RED);
    if(strlen(CondicaoP.NomePecas) < 2){
        gotoxy(8, 24); printf("Nome N%co Existe!", 198);
        return 0;
    }else if(strlen(CondicaoP.Marca) < 2){
        gotoxy(8, 24); printf("Marca N%co Existe!", 198);
        return 0;
    }else if(strlen(CondicaoP.Modelo) < 2){
        gotoxy(8, 24); printf("Modelo N%co Existe!", 198);
        return 0;
    }else if(CondicaoP.Preco <= 0){
        gotoxy(8, 24); printf("Pe%ca N%co Cadastrada!", 135, 198);
        return 0;
    }else if(CondicaoP.CodigoPeca <= 0 || CondicaoP.CodigoPeca == ""){
        gotoxy(6, 24); printf("Codigo N%co Cadastrado!", 198);
        return 0;
    }else{
        return 1;
    }
    textcoloreback(WHITE, BLUE);
}

//Abrir Arquivos

void AbrirPecas(){
    fpPecas = fopen("Pecas.txt", "rb+"); //  w - um novo arquivo vazio  a - acrescentar ou novo
    if(fpPecas == NULL){
        fpPecas = fopen("Pecas.txt", "wb+"); //  w - um novo arquivo vazio  a - acrescentar ou novo
        if(fpPecas == NULL){
            printf("Nao abri Pecas.txt!\n");
            exit(1);
        }
    }
}

void FecharArquivos(){
    fclose(fpPecas);
}



