// Fabio Silveira Tanikawa
// TIA: 32092563
// Júlia Carvalho de Souza Castro
// TIA: 32022298
// Gabriel Batista Cristiano
// TIA: 32090722

#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree() { root = NULL; }


AVLTree::~AVLTree() {}


bool AVLTree::isEmpty() { return root==NULL;}


int AVLTree::height() { return height(root); }


int AVLTree::height(AVLNode *no) { return no==NULL? -1:no->getHeight(); }

int AVLTree::maximo(int lhs, int rhs) { return lhs>rhs? lhs: rhs; }


int AVLTree::qtNodes() { return qtNodes(root); }


int AVLTree::qtNodes(AVLNode* no) {
    if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}



void AVLTree::inserir (int valor) { root = inserir(root,valor); }


AVLNode* AVLTree::inserir(AVLNode* node, int valor) {
    if (node == NULL)
       	return new AVLNode(valor);

    if (valor < node->getData()) {
        node->setLeft(inserir(node->getLeft(), valor));
        node->getLeft()->setParent(node);
        if (height( node->getRight() ) - height( node->getLeft() ) == -2 ) {
            if(valor < node->getLeft()->getData())
            {
                node = rotateLL( node );
                cout << "Rotacao LL" << endl;
            }
            else
            {
                node = rotateLR( node );
                cout << "Rotacao LR" << endl;
            }
        }
    }
    else {
        if (valor > node->getData()) {
            node->setRight(inserir(node->getRight(),valor));
            node->getRight()->setParent(node);
            if( height( node->getRight() ) - height( node->getLeft() ) == 2 ) {
                if( valor > node->getRight()->getData())
                {
                    node = rotateRR( node );
                    cout << "Rotacao RR" << endl;
                }
                else
                {
                    node = rotateRL( node );
                    cout << "Rotacao RL" << endl;
                }
            }
        }
    }
    
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1);
    return node;
}


AVLNode* AVLTree::rotateLL(AVLNode *node) {
    AVLNode *leftSubTree = node->getLeft();
    node->setLeft(leftSubTree->getRight());
    leftSubTree->setRight( node );
    leftSubTree->setParent(nullptr);
    node->setParent(leftSubTree);
    node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
    leftSubTree->setHeight( maximo(height(leftSubTree->getLeft()), height(node) + 1));
    return leftSubTree;
}


AVLNode* AVLTree::rotateRR(AVLNode *node) {
    AVLNode *rightSubTree = node->getRight();
    node->setRight(rightSubTree->getLeft());
    rightSubTree->setLeft( node );
    rightSubTree->setParent(nullptr);
    node->setParent(rightSubTree);
    node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
    rightSubTree->setHeight( maximo(height(rightSubTree->getRight()), height(node) + 1));
    return rightSubTree;
}


AVLNode* AVLTree::rotateLR(AVLNode *node) {
    node->setLeft(rotateRR(node->getLeft()));
    return rotateLL(node);
}


AVLNode* AVLTree::rotateRL(AVLNode *node) {
    node->setRight(rotateLL(node->getRight()));
    return rotateRR(node);
}


void AVLTree::preOrder() { preOrder(root); }


void AVLTree::inOrder() { inOrder(root); }


void AVLTree::posOrder() { posOrder(root); }


void AVLTree::reverseOrder() { reverseOrder(root); }


void AVLTree::preOrder(AVLNode *no) {
    if (no!=NULL) {
        cout<<no->getData();
        if(no->IsRoot(no))
        {
            cout << " Nó pai. / Fator: " << no->getHeight() << endl;
        }else
        {
            if(no->getData() == no->getParent()->getLeft()->getData())
            {
                cout << " Nó Filho da esquerda. / Fator: " << no->getHeight() << endl;
            }
            if(no->getData() == no->getParent()->getRight()->getData())
            {
                cout << " Nó Filho da direita. / Fator: " << no->getHeight() << endl;
            }
        }
        
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}


void AVLTree::posOrder(AVLNode *no) {
    if (no!=NULL) {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout<<no->getData()<<endl;
    }
}


void AVLTree::inOrder(AVLNode *no) {
    if (no!=NULL) {
        inOrder(no->getLeft());
        cout<<no->getData()<<endl;
        inOrder(no->getRight());
    }
}


void AVLTree::reverseOrder(AVLNode *no) {
    if (no!=NULL) {
        reverseOrder(no->getRight());
        cout<<no->getData()<<endl;
        reverseOrder(no->getLeft());
    }
}
