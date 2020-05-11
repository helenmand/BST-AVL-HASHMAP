#include "BinaryTreeNode.h"
#include <string>
#include <iostream>

using namespace std;

BinaryTreeNode::BinaryTreeNode()
{
    word = "";
    frequency = 0;
    leftChild = NULL;
    rightChild = NULL;
}

BinaryTreeNode::BinaryTreeNode(string tword)
{
    word = tword;
    frequency = 1;
    leftChild = NULL;
    rightChild = NULL;
}

BinaryTreeNode::~BinaryTreeNode()
{

}

ostream &operator<< (ostream &stream, BinaryTreeNode &node)
{
    stream<<node.Getword()<<" "<<node.Getfrequency();
    return stream;
}

void BinaryTreeNode::returnWordByNumber(string& tword, int& num)
{
    if(num<0)
        return;

    if (num <= (int)(frequency))
    {
        tword = word;
        num=-1;
    }
    num-=frequency;

    if(leftChild!=NULL)
        leftChild->returnWordByNumber(tword, num);
    if(rightChild!=NULL)
        rightChild->returnWordByNumber(tword, num);

    return;
}

void BinaryTreeNode::PreOrder ()
{
    cout<<*this<<endl;
    if(leftChild != NULL)
        leftChild->PreOrder();
    if(rightChild != NULL)
        rightChild->PreOrder();
    return;
}

void BinaryTreeNode::PostOrder()
{
    if(leftChild != NULL)
        leftChild->PostOrder();
    if(rightChild != NULL)
        rightChild->PostOrder();
    cout<<*this<<endl;
    return;
}

void BinaryTreeNode::InOrder()
{
    if(leftChild != NULL)
        leftChild->InOrder();
    cout<<*this<<endl;
    if(rightChild != NULL)
        rightChild->InOrder();
    return;
}

BinaryTreeNode* BinaryTreeNode::SearchWord(string wordWanted)
{
    if (wordWanted.compare(word) == 0)
        return this;

    if (wordWanted.compare(word) > 0)
    {
        if(rightChild!=NULL)
            return rightChild->SearchWord(wordWanted);
        else
            return this;
    }

    if(leftChild!=NULL)
        return leftChild->SearchWord(wordWanted); //if (wordWanted.compare(node->Getword()) < 0)
    else
        return this;
}

//insertNode 3.0
void BinaryTreeNode::insertNode(string &newWord)
{

    BinaryTreeNode* node = this->SearchWord(newWord);
    int compare = newWord.compare(node->Getword());
    if(compare == 0)
        node->Setfrequency(node->Getfrequency()+1);
    else
    {
        BinaryTreeNode* newNode = new BinaryTreeNode;
        *newNode = BinaryTreeNode(newWord);

        if(compare > 0)
            node->SetrightChild(newNode);
        else
            node->SetleftChild(newNode);
    }

}
