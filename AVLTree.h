// Fabio Silveira Tanikawa
// TIA: 32092563
// Júlia Carvalho de Souza Castro
// TIA: 32022298
// Gabriel Batista Cristiano
// TIA: 32090722

#ifndef AVLTREE_H
#define AVLTREE_H


#include "AVLNode.h"


class AVLTree {
    private:
        AVLNode *root;

        int height(AVLNode*);
        int qtNodes(AVLNode*);

        AVLNode* inserir(AVLNode*, int);
        void preOrder(AVLNode *no);
        void posOrder(AVLNode *no);
        void inOrder(AVLNode *no);
        AVLNode* rotateLL(AVLNode*);
        AVLNode* rotateRR(AVLNode*);
        AVLNode* rotateLR(AVLNode*);
        AVLNode* rotateRL(AVLNode*);
        void reverseOrder(AVLNode*);
        int maximo(int, int);

    protected:

    public:
        AVLTree();
        virtual ~AVLTree();
        
        AVLNode* getRoot();
        bool isEmpty();
        int height();
        int qtNodes();
        void inserir (int valor);
        void preOrder();
        void posOrder();
        void inOrder();
        void reverseOrder();



};

#endif // AVLTREE_H
