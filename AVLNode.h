#ifndef AVLNODE_H
#define AVLNODE_H

#include "BinaryTreeNode.h"

class AVLNode
{
    public:
        AVLNode();
        AVLNode(string s);
        virtual ~AVLNode();

        AVLNode* GetrightChild() { return rightChild; }
        void SetrightChild(AVLNode* val) { rightChild = val; }
        AVLNode* GetleftChild() { return leftChild; }
        void SetleftChild(AVLNode* val) { leftChild = val; }
        AVLNode* Getparent() { return parent; }
        void Setparent(AVLNode* val) { parent = val; }

        unsigned int Getfrequency() { return frequency; }
        void Setfrequency(unsigned int val) { frequency = val; }
        string Getword() { return word; }
        void Setword(string val) { word = val; }

        AVLNode* SearchWord(string);


        void PreOrder();

        void leftRotation();
        void rightRotation();
        void insertNode(string);
        void deleteNode(string);

        int returnBalance();
    private:
        AVLNode* rightChild;
        AVLNode* leftChild;
        AVLNode* parent;
        string word;
        unsigned int frequency;
};

int max2(int, int);
int getHeight(AVLNode*);

#endif // AVLNODE_H
