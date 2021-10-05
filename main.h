//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//

#ifndef PCO001_LISTA_ARRANJOS_MAIN_H
#define PCO001_LISTA_ARRANJOS_MAIN_H
#define INICIO_ARRANJO 1
#define TAMANHO_MAXIMO 100

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef struct
{
    string chave;
} TipoItem;

typedef struct TipoPilha
{
    TipoItem item[TAMANHO_MAXIMO];
    int topo;
} TipoPilha;

bool isCheia(const TipoPilha *pilha) {
    if (pilha->topo == TAMANHO_MAXIMO) {
        cout << "ERRO! Pilha está cheia" << endl;
        return true;
    }
    return false;
}

bool isVazia(const TipoPilha *pilha)
{
    if (pilha->topo == -1)
    {
        cout << "ERRO! Pilha está vazia" << endl;
        return true;
    }
    return false;
}

void imprimePilha(TipoPilha *pilha)
{
    cout << "Pilha: " << endl;
    for (int i = 0; i <= pilha->topo; i++)
    {
        cout << to_string(i) + ") " + pilha->item[i].chave << endl;
    }
    cout << endl;
}

void inicializaPilha(TipoPilha* pilha)
{
    pilha->topo = -1;
}

void empilhar(string item, TipoPilha* pilha)
{
    if(isCheia(pilha)) return;
    pilha->topo++;
    pilha->item[pilha->topo].chave = item;
}

void desempilhar(TipoPilha* pilha)
{
    if (isVazia(pilha)) return;
    pilha->item[pilha->topo].chave = "";
    pilha->topo--;
}

void descarregaPilhaAuxiliarNaPilha(TipoPilha *pilhaAux, TipoPilha *pilha) {
    for (int j = pilhaAux->topo; j != -1; j--)
    {
        empilhar(pilhaAux->item[j].chave, pilha);
        desempilhar(pilhaAux);
    }
}

TipoPilha *carregaPilhaAuxiliarAtePosicao(int posicao, TipoPilha *pilha, TipoPilha* pilhaAux) {
    for (int i = pilha->topo; i >= posicao; i--)
    {
        empilhar(pilha->item[i].chave, pilhaAux);
        desempilhar(pilha);
    }
    return pilhaAux;
}

TipoPilha *carregaPilhaAuxiliarAtePosicao(int posicao, TipoPilha *pilha) {
    TipoPilha pilhaAux;
    inicializaPilha(&pilhaAux);
    return carregaPilhaAuxiliarAtePosicao(posicao, pilha, &pilhaAux);
}

void insereItemAposPosicao(string item, int posicao, TipoPilha* pilha)
{
    if (isCheia(pilha)) return;
    TipoPilha* pilhaAux = carregaPilhaAuxiliarAtePosicao(posicao, pilha);
    int topoAux = pilhaAux->topo;
    empilhar(item, pilha);
    pilhaAux->topo = topoAux;
    descarregaPilhaAuxiliarNaPilha(pilhaAux, pilha);
}

void retira(TipoPilha* pilha, int posicao)
{
    if(isVazia(pilha)) return;
    TipoPilha *pilhaAux = carregaPilhaAuxiliarAtePosicao(posicao+1, pilha);
    int topoAux = pilhaAux->topo;
    desempilhar(pilha);
    pilhaAux->topo = topoAux;
    descarregaPilhaAuxiliarNaPilha(pilhaAux, pilha);
}

void localizaItemPosicao(int posicao, TipoPilha* pilha)
{
    if(isVazia(pilha)) return;
    string shouldChange = "n";
    TipoPilha* pilhaAux = carregaPilhaAuxiliarAtePosicao(posicao+1, pilha);
    int topoAux = pilhaAux->topo;
    cout << "O valor na posição " + to_string(posicao) + " é " + pilha->item[pilha->topo].chave << endl;
    cout << "Deseja alterar o valor (s/n)? ";
    // cin >> shouldChange;
    if (shouldChange == "s")
    {
        string novoValor;
        cout << "Entre com o novo valor: ";
        cin >> novoValor;
        desempilhar(pilha);
        empilhar(novoValor, pilha);
    }
    pilhaAux->topo = topoAux;
    descarregaPilhaAuxiliarNaPilha(pilhaAux, pilha);
}

TipoPilha combinarPilhas(TipoPilha* pilhaUm, TipoPilha* pilhaDois)
{
    int tamanhoNovo = pilhaUm->topo + pilhaDois->topo;
    if (tamanhoNovo > TAMANHO_MAXIMO)
    {
        cout << "ERRO! As combinação das pilhas excede o tamanho máximo!" << endl;
    }
    TipoPilha  novaPilha;
    inicializaPilha(&novaPilha);
    carregaPilhaAuxiliarAtePosicao(0, pilhaUm, &novaPilha);
    carregaPilhaAuxiliarAtePosicao(0, pilhaDois, &novaPilha);
    return  novaPilha;
}

TipoPilha dividirPilha(TipoPilha* original, int posicao)
{
    TipoPilha novaPilha;
    inicializaPilha(&novaPilha);
    if(isVazia(original)) return novaPilha;
    carregaPilhaAuxiliarAtePosicao(posicao + 1, original, &novaPilha);
    return novaPilha;
}

TipoPilha copiarPilha(TipoPilha* original)
{
    TipoPilha pilhaAux;
    inicializaPilha(&pilhaAux);
    carregaPilhaAuxiliarAtePosicao(0, original, &pilhaAux);
    int topoAux = pilhaAux.topo;
    TipoPilha copia;
    inicializaPilha(&copia);
    pilhaAux.topo = topoAux;
    for (int i = pilhaAux.topo; i >= 0; i--)
    {
        empilhar(pilhaAux.item[i].chave, original);
        empilhar(pilhaAux.item[i].chave, &copia);
        desempilhar(&pilhaAux);
    }
    return copia;
}

void localizaItemPosicao(TipoPilha* pilha, const string& valorBuscado)
{
    if(isVazia(pilha)) return;
    int ocorrencia = 0;
    vector<int> posicao;
    bool isPresent = false;
    TipoPilha copia = copiarPilha(pilha);
    while(copia.topo != -1)
    {
        if(copia.item[copia.topo].chave == valorBuscado)
        {
            ocorrencia++;
            posicao.push_back(pilha->topo);
            isPresent = true;
        }
        desempilhar(&copia);
    }
    if (isPresent)
    {
        cout << to_string(ocorrencia) + " ocorrências do valor " + valorBuscado + " encontradas" << endl;
        return;
    }
    cout << "ERRO! Valor " + valorBuscado + " não encontrado" << endl;
}

#endif //PCO001_LISTA_ARRANJOS_MAIN_H