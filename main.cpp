// Fabio Silveira Tanikawa
// TIA: 32092563
// Júlia Carvalho de Souza Castro
// TIA: 32022298
// Gabriel Batista Cristiano
// TIA: 32090722

#include <iostream>

#include "AVLNode.h"
#include "AVLTree.h"


using namespace std;

int main() {
    AVLTree* treeA = new AVLTree;
    AVLTree* treeB = new AVLTree;
    AVLTree* treeC = new AVLTree;
    AVLTree* treeD = new AVLTree;
    
    
    cout << "----- Questao 1 -----" << endl;
    cout << "Inserindo os nós: 1, 2 e 3" << endl;
    treeA->inserir(1);
    treeA->inserir(2);
    treeA->inserir(3);
    cout << "Arvore Balanceada: " << endl;
    treeA->preOrder();
    cout << "------------------------\n\n";
    cout << "----- Questao 2 -----" << endl;
    cout << "Inserindo os nós: 3, 2 e 1" << endl;
    treeB->inserir(3);
    treeB->inserir(2);
    treeB->inserir(1);
    cout << "Arvore Balanceada: " << endl;
    treeB->preOrder();
    cout << "------------------------\n\n";
    cout << "----- Questao 3 -----" << endl;
    cout << "Inserindo os nós: 3, 1 e 2" << endl;
    treeC->inserir(3);
    treeC->inserir(1);
    treeC->inserir(2);
    cout << "Arvore Balanceada: " << endl;
    treeC->preOrder();
    cout << "------------------------\n\n";
    cout << "----- Questao 4 -----" << endl;
    cout << "Inserindo os nós: 1, 3 e 2" << endl;
    treeD->inserir(1);
    treeD->inserir(3);
    treeD->inserir(2);
    cout << "Arvore Balanceada: " << endl;
    treeD->preOrder();
    cout << "------------------------\n\n";

    delete treeA;
    delete treeB;
    delete treeC;
    delete treeD;
    

    system("pause");
    return 0;
}
