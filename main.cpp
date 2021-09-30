//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//
#include "main.h"

int main()
{
    auto *primeiraPilha = new TipoPilhaArranjos;
    auto *segundaPilha = new TipoPilhaArranjos;

    cout << "01. Criação da estrutura de dados vazia" << endl;
    inicializaPilha(primeiraPilha);
    inicializaPilha(segundaPilha);
    imprimePilha(primeiraPilha);
    imprimePilha(segundaPilha);

    cout << endl << "02. Inserir um novo item imediatamente após o i-ésimo item" << endl;
    insereValor("banana", primeiraPilha);
    insereValor("laranja", primeiraPilha);
    insereValor("manga", primeiraPilha);
    insereValor("morango", primeiraPilha);
    insereValor("uva", primeiraPilha);
    insereValor("batata", segundaPilha);
    insereValor("cebola", segundaPilha);
    insereValor("vagem", segundaPilha);
    insereValor("cenoura", segundaPilha);
    insereValor("beterraba", segundaPilha);
    insereValor("tomate", segundaPilha);
    imprimePilha(primeiraPilha);
    imprimePilha(segundaPilha);

    cout << endl <<  "03. Retirar o primeiro item" << endl;
    retiraPrimeiroItem(primeiraPilha);
    retiraPrimeiroItem(segundaPilha);
    imprimePilha(primeiraPilha);
    imprimePilha(segundaPilha);

    cout << endl << "04. Retirar o i-ésimo item" << endl;
    retira(primeiraPilha, 1);
    retira(segundaPilha, 2);
    imprimePilha(primeiraPilha);
    imprimePilha(segundaPilha);

    cout << endl <<  "05. Localizar um item na Lista" << endl;
    buscarValor(*primeiraPilha, "banana");
    buscarValor(*primeiraPilha, "laranja");
    buscarValor(*segundaPilha, "tomate");
    buscarValor(*segundaPilha, "cenoura");

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    auto *novaLista = new TipoPilhaArranjos;
    inicializaPilha(novaLista);
    concatenarPilha(*segundaPilha, *primeiraPilha, novaLista);
    imprimePilha(novaLista);

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    auto *novaPilhaEsquerda = new TipoPilhaArranjos;
    auto *novaPilhaDireita = new TipoPilhaArranjos;
    inicializaPilha(novaPilhaEsquerda);
    inicializaPilha(novaPilhaDireita);
    dividirListas(*novaLista, novaPilhaEsquerda, novaPilhaDireita);
    imprimePilha(novaPilhaEsquerda);
    imprimePilha(novaPilhaDireita);

    cout << endl << "08. Fazer uma cópia" << endl;
    auto *listaCopiada = new TipoPilhaArranjos;
    inicializaPilha(listaCopiada);
    copiarLista(*novaPilhaEsquerda, listaCopiada);
    imprimePilha(listaCopiada);

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenaLista(novaLista);
    imprimePilha(novaLista);

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    insereValor("laranja", novaLista);
    imprimePilha(novaLista);
    buscarOcorrenciaDeValor(*novaLista, "laranja");
}
