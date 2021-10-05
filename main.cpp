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

    cout << endl <<  "05. Retirar i-ésimo item" << endl;
    retira(&segundaPilha, 2);
    imprimePilha(&segundaPilha);

    cout << endl <<  "06. Localizar um item na Lista" << endl;
    localizaItemPosicao(1, &primeiraPilha);
    localizaItemPosicao(3, &primeiraPilha);
    localizaItemPosicao(0, &segundaPilha);
    localizaItemPosicao(3, &segundaPilha);
    imprimePilha(&primeiraPilha);
    imprimePilha(&segundaPilha);

    cout << endl << "07. Combinar duas ou mais estruturas em uma" << endl;
    TipoPilha novaPilha;
    inicializaPilha(&novaPilha);
    novaPilha = combinarPilhas(&segundaPilha, &primeiraPilha);
    imprimePilha(&novaPilha);

    cout << endl << "08. Partir uma estrutura em duas ou mais" << endl;
    TipoPilha novaPilhaDireita;
    inicializaPilha(&novaPilhaDireita);
    novaPilhaDireita = dividirPilha(&novaPilha, 3);
    imprimePilha(&novaPilha);
    imprimePilha(&novaPilhaDireita);

    cout << endl << "09. Fazer uma cópia" << endl;
    TipoPilha pilhaCopiada;
    inicializaPilha(&pilhaCopiada);
    pilhaCopiada = copiarPilha(&novaPilhaDireita);
    imprimePilha(&pilhaCopiada);

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    empilhar("laranja", &pilhaCopiada);
    imprimePilha(&pilhaCopiada);
    localizaItemPosicao(&pilhaCopiada, "laranja");
}
