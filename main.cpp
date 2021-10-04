//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//
#include "main.h"

int main()
{
    TipoPilha primeiraPilha;
    TipoPilha segundaPilha;

    cout << "01. Criação da estrutura de dados vazia" << endl;
    inicializaPilha(&primeiraPilha);
    inicializaPilha(&segundaPilha);
    imprimePilha(&primeiraPilha);
    imprimePilha(&segundaPilha);

    cout << endl << "02. Empilhar" << endl;
    empilhar("banana", &primeiraPilha);
    empilhar("laranja", &primeiraPilha);
    empilhar("manga", &primeiraPilha);
    empilhar("morango", &primeiraPilha);
    empilhar("uva", &primeiraPilha);
    empilhar("batata", &segundaPilha);
    empilhar("cebola", &segundaPilha);
    empilhar("vagem", &segundaPilha);
    empilhar("cenoura", &segundaPilha);
    empilhar("beterraba", &segundaPilha);
    empilhar("tomate", &segundaPilha);
    imprimePilha(&primeiraPilha);
    imprimePilha(&segundaPilha);

    cout << endl <<  "03. Desempilhar" << endl;
    desempilhar(&primeiraPilha);
    desempilhar(&segundaPilha);
    imprimePilha(&primeiraPilha);
    imprimePilha(&segundaPilha);

    cout << endl << "04. Inserir um novo item após o i-ésimo item" << endl;
    insereItemAposPosicao("goiaba", 2, &primeiraPilha);
    insereItemAposPosicao("jiló", 3, &segundaPilha);
    imprimePilha(&primeiraPilha);
    imprimePilha(&segundaPilha);

    /*
    cout << endl <<  "05. Localizar um item na Lista" << endl;
    localizaItemPosicao(*primeiraPilha, "banana");
    localizaItemPosicao(*primeiraPilha, "laranja");
    localizaItemPosicao(*segundaPilha, "tomate");
    localizaItemPosicao(*segundaPilha, "cenoura");

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    auto *novaLista = new TipoPilha;
    inicializaPilha(novaLista);
    combinarPilhas(*segundaPilha, *primeiraPilha, novaLista);
    imprimePilha(novaLista);

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    auto *novaPilhaEsquerda = new TipoPilha;
    auto *novaPilhaDireita = new TipoPilha;
    inicializaPilha(novaPilhaEsquerda);
    inicializaPilha(novaPilhaDireita);
    dividirPilha(*novaLista, novaPilhaEsquerda, novaPilhaDireita);
    imprimePilha(novaPilhaEsquerda);
    imprimePilha(novaPilhaDireita);

    cout << endl << "08. Fazer uma cópia" << endl;
    auto *listaCopiada = new TipoPilha;
    inicializaPilha(listaCopiada);
    copiarPilha(*novaPilhaEsquerda, listaCopiada);
    imprimePilha(listaCopiada);

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenaLista(novaLista);
    imprimePilha(novaLista);

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    empilhar("laranja", novaLista);
    imprimePilha(novaLista);
    localizaItemPosicao(*novaLista, "laranja");*/
}
