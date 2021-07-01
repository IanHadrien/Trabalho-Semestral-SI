#include "Clientes.h"
#include "Interface.h"
#include "EntradaDados.h"

FILE *fpClientes;

CadastroCliente DigitarCliente(){
    CadastroCliente Cliente;
    char Nome[101], CPF[51], Contato[51], Texto[101];
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

    textcoloreback(BLUE, WHITE);
    strcpy(Contato, "");
    gotoxy(30, 8); printf("%*s", 20, " ");
    gotoxy(30, 8); printf("%d", Nome);
    gotoxy(30, 12); printf("%*s", 20, " ");
    gotoxy(30, 12); printf("%s", strcpy(Cliente.CPF, ""));
    gotoxy(30, 16); printf("%*s", 25, " ");
    gotoxy(30, 16); printf("%s", Contato);
    gotoxy(30, 20); printf("%*s", 10, " ");
    gotoxy(30, 20); printf("%d", Codigo=0);
    textcoloreback(WHITE, BLUE);

    strcpy(Cliente.Nome, "");
    strcpy(Cliente.Contato, "");
    strcpy(Texto, "");

    int Tecla, Opcao = 0;
    do{
        if(Opcao == 0){
            Tecla = EntradaDados(30, 8, 20, Cliente.Nome);
        }
        else if(Opcao == 1){
            Tecla = EntradaDadosNumeros(30, 12, 20, Cliente.CPF);
        }
        else if(Opcao == 2){
            Tecla = EntradaDados(30, 16, 25, Cliente.Contato);
        }
        else if(Opcao == 3){
            Tecla = EntradaDadosNumeros(30, 20, 10, Texto);
            Cliente.Codigo = atoi(Texto);
        }
        if(Tecla == TEC_CIMA) Opcao--;
        if(Tecla == TEC_BAIXO || Tecla == TEC_ENTER) Opcao++;
        if(Opcao < 0) Opcao = 3;
        if(Opcao > 3) Opcao = 0;
    }while(Tecla != TEC_ESC);
    strcpy(Cliente.Pendente, "Pendente");

    return Cliente;
}

void SalvarClientes(CadastroCliente C){
    fseek(fpClientes, 0, SEEK_END);
    fwrite(&C, sizeof(CadastroCliente), 1, fpClientes);
    fflush(fpClientes);

    textcoloreback(WHITE, LIGHT_GREEN);
    gotoxy(8, 24); printf("Cliente Cadastrado!");
    textcoloreback(WHITE, BLUE);

}

void ImprimirCliente(){
    int i, L=10;
    CadastroCliente Clientes;
    fseek(fpClientes, 0, SEEK_SET);
    while(fread(&Clientes, sizeof(CadastroCliente), 1, fpClientes)){

        if(Clientes.Codigo==100 || Clientes.Codigo==200 || Clientes.Codigo==400 || Clientes.Codigo==500 || Clientes.Codigo==700 || Clientes.Codigo==110 || Clientes.Codigo==112 || Clientes.Codigo==113){

                if(strcmp(Clientes.Pendente, "Pendente") == 0){
                    gotoxy(7, L);
                    printf("%s", Clientes.Nome);
                    gotoxy(85, L);
                    printf("%s", Clientes.Pendente);

                    gotoxy(45, L);
                    if(Clientes.Codigo == 100){
                        printf("Formata%c%co de Sistema", 135, 198);
                    }else if(Clientes.Codigo == 200){
                        printf("Desistala%c%co de Software", 135, 198);
                    }else if(Clientes.Codigo == 400){
                        printf("Atauliza%c%co de Sistemas", 135, 198);
                    }else if(Clientes.Codigo == 500){
                        printf("Remo%c%co de Excesso de Poeira", 135, 198);
                    }else if(Clientes.Codigo == 700){
                        printf("Organiza%c%co de Cabos Internos", 135, 198);
                    }else if(Clientes.Codigo == 110){
                        printf("Troca de Pe%cas Defeituosas", 135);
                    }else if(Clientes.Codigo == 112){
                        printf("Limpeza de Arquivos Temporarios");
                    }else if(Clientes.Codigo == 113){
                        printf("N%co Sei Meu Problema", 198);
                    }

                    gotoxy(107, L);
                    printf("%d", Clientes.Codigo);
                    L += 1;

            }
        }
    }
}


void Alterar(){
    CadastroCliente Clientes;
    textcoloreback(WHITE, BLUE);
    Borda(4, 9, 110, 16);
    char NomeDigitado[51], NovoStatus[50];

    gotoxy(17, 14); printf("Nome do Cliente: ");
    textcoloreback(BLUE, WHITE);
    Borda(35, 13, 20, 2);
    gotoxy(36, 14); scanf(" %50[^\n]", NomeDigitado);
    textcoloreback(WHITE, BLUE);

    fseek(fpClientes, 0, SEEK_SET);
    while(fread(&Clientes, sizeof(CadastroCliente), 1, fpClientes)){
        if(strcmp(Clientes.Nome, NomeDigitado) == 0){
            gotoxy(17, 19); printf("    Novo Status: ");
            textcoloreback(BLUE, WHITE);
            Borda(79, 13, 20, 2);
            textcoloreback(WHITE, BLUE);
            gotoxy(65, 14); printf("Status Atual:");
            textcoloreback(BLUE, WHITE);
            Borda(79, 18, 20, 2);
            textcoloreback(WHITE, BLUE);
            gotoxy(61, 19); printf("Valor do Servi%co:", 135);

            textcoloreback(BLUE, WHITE);
            FuncaoCodigo(Clientes);
            textcoloreback(WHITE, BLUE);

            textcoloreback(BLUE, WHITE);
            Borda(35, 18, 20, 2);

            gotoxy(36, 19); scanf(" %50[^\n]", Clientes.Pendente);
            fseek(fpClientes, -sizeof(Clientes), SEEK_CUR);
            fwrite(&Clientes, sizeof(Clientes), 1, fpClientes);


            textcoloreback(WHITE, BLUE);
            break;

        }
    }

}

void FuncaoCodigo(CadastroCliente C){

    if(C.Codigo == 100){
        gotoxy(80, 19); printf("R$ 100,00");
    }else if(C.Codigo == 200){
        gotoxy(80, 19); printf("R$ 200,00");
    }else if(C.Codigo == 400){
        gotoxy(80, 19); printf("R$ 140,00");
    }else if(C.Codigo == 500){
        gotoxy(80, 19); printf("R$ 250,00");
    }else if(C.Codigo == 700){
        gotoxy(80, 19); printf("R$ 120,00");
    }else if(C.Codigo == 110){
        gotoxy(80, 19); printf("R$ 500,00");
    }else if(C.Codigo == 112){
        gotoxy(80, 19); printf("R$ 120,00");
    }else if(C.Codigo == 113){
        gotoxy(80, 19); printf("R$ $$$$$$");
    }

    gotoxy(80, 14); printf("%s", C.Pendente);
}

// Verificar Condições
int CondicoesSalvar(CadastroCliente CondicaoC){

    textcoloreback(WHITE, RED);
    if(CondicaoC.Codigo == 0 || CondicaoC.Codigo > 999){
        gotoxy(6, 24); printf("Codigo N%co Encontrado!", 198);
        return 0;
    }else if(strlen(CondicaoC.CPF) < 11){
        gotoxy(8, 24); printf("CPF N%co Existe!", 198);
        return 0;
    }else if(strlen(CondicaoC.Nome) < 2 || strlen(CondicaoC.Contato) < 2){
        gotoxy(5, 24); printf("Cliente N%co Cadastrado!", 198);
        return 0;
    }else{
        return 1;
    }
    textcoloreback(WHITE, BLUE);

}

void AbrirCliente(){
    fpClientes = fopen("Clientes.txt", "rb+"); //  w - um novo arquivo vazio  a - acrescentar ou novo
    if(fpClientes == NULL){
        fpClientes = fopen("Clientes.txt", "wb+"); //  w - um novo arquivo vazio  a - acrescentar ou novo
        if(fpClientes == NULL){
            printf("Nao abri Clientes.txt!\n");
            exit(1);
        }
    }
}

void FecharArquivosClientes(){
    fclose(fpClientes);
}


