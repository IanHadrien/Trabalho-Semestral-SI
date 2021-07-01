#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

struct cliente {
    char Nome[50];
    char CPF[50];
    char Contato[50];
    int Codigo;
    char Pendente[50];
};
typedef struct cliente CadastroCliente;

CadastroCliente DigitarCliente();
void SalvarClientes(CadastroCliente C);
void ImprimirCliente();

void Alterar();
void FuncaoCodigo(CadastroCliente C);
int CondicoesSalvar(CadastroCliente CondicaoC);

void AbrirCliente();
void FecharArquivosClientes();

#endif // CLIENTES_H_INCLUDED
