#include "AVLNode.h"

AVLNode::AVLNode(){
    word = "";
    frequency = 0;
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

void AVLNode::leftRotation(){
    AVLNode* temp = this->GetrightChild();
    temp->Setparent(this->Getparent());
    this->Setparent(temp);
    this->SetrightChild(temp->GetleftChild());
    temp->SetleftChild(this);
}

void AVLNode::rightRotation(){
    AVLNode* temp = this->GetleftChild();
    temp->Setparent(this->Getparent());
    this->Setparent(temp);
    this->SetleftChild(temp->GetrightChild());
    temp->SetrightChild(this);
}

AVLNode::AVLNode(string w)
{
    word = w;
    frequency = 1;
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

AVLNode::~AVLNode()
{
    //dtor
}

void AVLNode::PreOrder()
{
    cout<<this->Getword()<<endl;
    if(leftChild != NULL)
        leftChild->PreOrder();
    if(rightChild != NULL)
        rightChild->PreOrder();
    return;
}

int max2(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int getHeight(AVLNode* node)
{
    if(node == NULL)
        return 1;

    return max2(getHeight(node->GetleftChild()), getHeight(node->GetrightChild()))+1;
}

int AVLNode::returnBalance()
{
    return getHeight(leftChild) - getHeight(rightChild);
}

AVLNode* AVLNode::SearchWord(string wordWanted)
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

void AVLNode::insertNode(string newWord)
{
    AVLNode* node = this->SearchWord(newWord);
    AVLNode* newNode;
    int balance;
    int compare = newWord.compare(node->Getword());
    if(compare == 0)
        node->Setfrequency(node->Getfrequency()+1);
    else
    {
        newNode = new AVLNode;
        *newNode = AVLNode(newWord);

        newNode->Setparent(node);

        if(compare > 0)
            node->SetrightChild(newNode);
        else
            node->SetleftChild(newNode);
    }

    AVLNode* currentNode = newNode;

    bool madeRotation = false;
    while(currentNode!= NULL && !madeRotation)
    {
        balance = currentNode->returnBalance();

        //LL
        if (balance>1 && newWord.compare(currentNode->GetleftChild()->Getword())<0)
        {
            cout<<"starting LL"<<endl;
            madeRotation = true;
            currentNode->rightRotation();
            cout<<"finishing LL"<<endl;
        }
        //LR
        else if (balance>1 && newWord.compare(currentNode->GetleftChild()->Getword())>0)
        {
            cout<<"starting LR"<<endl;
            madeRotation = true;
            currentNode->GetleftChild()->leftRotation();
            currentNode->rightRotation();
            cout<<"finishing LR"<<endl;
        }
        //RR
        else if (balance < -1 && newWord.compare(currentNode->GetleftChild()->Getword())>0)
        {
            cout<<"starting RR"<<endl;
            madeRotation = true;
            currentNode->leftRotation();
            cout<<"finishing RR"<<endl;
        }
        //RL
        else if (balance < -1 && newWord.compare(currentNode->GetleftChild()->Getword())<0)
        {
            cout<<"starting RL"<<endl;
            madeRotation = true;
            currentNode->GetrightChild()->rightRotation();
            currentNode->leftRotation();
            cout<<"finishing RL"<<endl;
        }

        currentNode = currentNode->Getparent();
    }
}
