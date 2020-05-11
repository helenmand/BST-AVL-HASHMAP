#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <string>
#include <iostream>

using namespace std;

class BinaryTreeNode
{
    public:
        BinaryTreeNode();
        BinaryTreeNode(string);
        virtual ~BinaryTreeNode();

        //The three Order functions just print the data
        void PreOrder ();
        void PostOrder();
        void InOrder();

        BinaryTreeNode* SearchWord(string);
        void returnWordByNumber(string& aWord, int& num); //Each node is numbered with the "Post Order" method taking note of freq

        //BinaryTreeNode* NewNode( string &s );
        void insertNode(string &s);

        BinaryTreeNode* GetrightChild() { return rightChild; }
        void SetrightChild(BinaryTreeNode* val) { rightChild = val; }
        BinaryTreeNode* GetleftChild() { return leftChild; }
        void SetleftChild(BinaryTreeNode* val) { leftChild = val; }
        unsigned int Getfrequency() { return frequency; }
        void Setfrequency(unsigned int val) { frequency = val; }
        string Getword() { return word; }
        void Setword(string val) { word = val; }

    private:
        BinaryTreeNode* rightChild;
        BinaryTreeNode* leftChild;
        unsigned int frequency;
        string word;
};

ostream &operator<< (ostream &stream, BinaryTreeNode &node);

#endif // BINARYTREENODE_H
