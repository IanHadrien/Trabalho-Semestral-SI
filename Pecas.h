#ifndef CADASTROCLIENTE_H_INCLUDED
#define CADASTROCLIENTE_H_INCLUDED
#include <stdio.h>

struct peca {
    char NomePecas[50];
    char Marca[50];
    char Modelo[50];
    double Preco;
    int CodigoPeca;
};
typedef struct peca CadastroPeca;

CadastroPeca DigitarPeca();

void ImprimirPeca();
void SalvarPeca(CadastroPeca P);
void ImprimirPecaSaida();

int CondicoesSalvarPeca(CadastroPeca CondicaoP);

void AbrirPecas();
void FecharArquivos();

#endif // CADASTROCLIENTE_H_INCLUDED
