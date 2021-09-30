//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//

#ifndef PCO001_LISTA_ARRANJOS_MAIN_H
#define PCO001_LISTA_ARRANJOS_MAIN_H
#define INICIO_ARRANJO 1
#define TAMANHO_MAXIMO 100

#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    string chave;
} TipoItem;

typedef struct TipoLista
{
    TipoItem item[TAMANHO_MAXIMO];
    int primeiro{}, ultimo{};
} TipoPilhaArranjos;

bool isCheia(const TipoPilhaArranjos *lista) { return lista->ultimo == TAMANHO_MAXIMO; }

bool isVazia(const TipoPilhaArranjos *lista) { return lista->primeiro == lista->ultimo; }

void imprimePilha(TipoPilhaArranjos *lista)
{
    cout << "Lista -> ";
    for (int i = 0; i < lista->ultimo; i++)
    {
        cout << to_string(i+1) + ") " + lista->item[i].chave;
        if (i + 1 < lista->ultimo)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void inicializaPilha(TipoPilhaArranjos* lista)
{
    lista->primeiro = INICIO_ARRANJO;
    lista->ultimo = lista->primeiro;
}

void insereValor(string item, TipoPilhaArranjos* lista)
{
    int posicao;

    if(isCheia(lista))
    {
        cout << "ERRO! Lista está cheia" << endl;
        return;
    }
    if(lista->ultimo < posicao)
    {
        lista->ultimo = posicao;
    }
    lista->item[posicao - 1].chave = std::move(item);
}

void retiraPrimeiroItem(TipoPilhaArranjos* lista)
{
    if (isVazia(lista))
    {
        cout << "ERRO! Lista está vazia" << endl;
        return;
    }
    for (int i = 0; i < lista->ultimo; i++)
    {
        lista->item[i] = lista->item[i+1];
    }
    lista->ultimo--;
}

void retira(TipoPilhaArranjos* lista, int posicao)
{
    if(isVazia(lista) || posicao - 1 > lista->ultimo)
    {
        cout << "ERRO! Lista está vazia ou índice fora do limite" << endl;
        return;
    }
    for(int i = posicao-1; i < lista->ultimo; i++)
    {
        lista->item[i] = lista->item[i+1];
    }
    lista->ultimo--;
}

void buscarValor(const TipoPilhaArranjos& lista, const string& valorBuscado)
{
    for (int i = lista.primeiro; i <= lista.ultimo; i++)
    {
        if(strcmp(lista.item[i - 1].chave.c_str(), valorBuscado.c_str()) == 0)
        {
            cout << "Valor " + valorBuscado + " encontrado na posição " + to_string(i) << endl;
            return;
        }
    }
    cout << "ERRO! Valor " + valorBuscado + " não encontrado" << endl;
}

void concatenarPilha(const TipoPilhaArranjos& primeiraLista, const TipoPilhaArranjos& segundaLista, TipoPilhaArranjos* novaLista)
{
    int posicao = 1;
    if (primeiraLista.ultimo + segundaLista.ultimo > TAMANHO_MAXIMO)
    {
        cout << "ERRO! O tamanho das duas lista é maior do que a nova lista" << endl;
    }
    for (int i = primeiraLista.primeiro; i <= primeiraLista.ultimo; i++)
    {
        insereValor(primeiraLista.item[i-1].chave, novaLista);
        posicao++;
    }
    for (int j = segundaLista.primeiro; j <= segundaLista.ultimo; j ++)
    {
        insereValor(segundaLista.item[j-1].chave,  novaLista);
        posicao++;
    }
}

void dividirListas(TipoPilhaArranjos& listaOriginal, TipoPilhaArranjos* novaListaEsquerda, TipoPilhaArranjos* novaListaDireita)
{
    int posicao = 1;
    int meio = listaOriginal.ultimo/2;
    for(int i = listaOriginal.primeiro - 1; i < listaOriginal.ultimo; i++)
    {
        if(i < meio)
        {
            insereValor(listaOriginal.item[i].chave, novaListaEsquerda);
        }
        else
        {
            insereValor(listaOriginal.item[i].chave, novaListaDireita);
            posicao++;
        }
    }
}

void copiarLista(TipoPilhaArranjos& listaOriginal, TipoPilhaArranjos* novaLista)
{
    for(int i = listaOriginal.primeiro; i <= listaOriginal.ultimo; i++)
    {
        insereValor(listaOriginal.item[i-1].chave , novaLista);
    }
}
void ordenaLista(TipoPilhaArranjos* lista)
{
    string temp;
    for(int j = 0; j<lista->ultimo-1; j++)
    {
        for(int i = 0; i < lista->ultimo-1; i++)
        {
            if(lista->item[i].chave.compare(lista->item[i+1].chave) > 0)
            {
                temp = lista->item[i].chave;
                lista->item[i].chave = lista->item[i+1].chave;
                lista->item[i+1].chave = temp;
            }
        }
    }
}
void buscarOcorrenciaDeValor(TipoPilhaArranjos& lista, const string& valorBuscado)
{
    int ocorrencia = 0;
    bool isPresent = false;
    for (int i = lista.primeiro; i <= lista.ultimo; i++)
    {
        if(strcmp(lista.item[i - 1].chave.c_str(), valorBuscado.c_str()) == 0)
        {
            ocorrencia++;
            isPresent = true;
        }
    }
    if (isPresent)
    {
        cout << to_string(ocorrencia) + " ocorrências do valor " + valorBuscado + " encontradas" << endl;
        return;
    }
    cout << "ERRO! Valor " + valorBuscado + " não encontrado" << endl;
}

#endif //PCO001_LISTA_ARRANJOS_MAIN_H