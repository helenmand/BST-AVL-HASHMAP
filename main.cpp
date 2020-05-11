#include "BinaryTreeNode.h"

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <chrono>

using namespace std;

void createSearchList(string searchList[], int searchAmount, int wordAmount, BinaryTreeNode* root)
{
    int i, randomNumber;
    string tempString;
    double duration;

    srand(time(0));

    //cout<<"RANDOM LIST:"<<endl; //DEBUG
    auto start = chrono::high_resolution_clock::now();
    for(i=0;i<searchAmount;i++)
    {
        randomNumber = rand() % wordAmount;
        //cout<<randomNumber<<" "; //DEBUG
        root->returnWordByNumber(tempString, randomNumber);
        searchList[i] = tempString;
        //cout<<tempString<<endl; //DEBUG
    }
    auto finish = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(finish-start).count();
    duration/=1000000;
    cout<<"Randon List Creation lasted: "<<duration<<" seconds!"<<endl;
}
/*
auto start = chrono::high_resolution_clock::now();
auto finish = chrono::high_resolution_clock::now();
duration = chrono::duration_cast<chrono::microseconds>(finish-start).count();
duration/=1000000;
cout<<"Randon List Creation lasted: "<<duration<<" seconds!"<<endl;
*/

int main()
{
    string fileName;
    ifstream file;
    double duration;
    int i;

    cout<<"Please insert text file name, example: \"book.txt\""<<endl;
    cout<<"NOTE: File should be in the same folder as main.cpp"<<endl;

    cin>>fileName;

    if(fileName.find('.') == string::npos) //If file name lacks an extension, add a '.txt' at the end
        fileName+=".txt";

    file.open(fileName, ios::in);

    if(!file.is_open())
    {
        cout<<"Couldn't open file! Aborting..."<<endl;
    }
    else
    {
        cout<<"File opened successfully!"<<endl;

        int numberOfWords = 0;
        char fileChar; //current character being examined in the txt file
        string newWord;
        bool inWord = false;

        BinaryTreeNode* BinaryTreeRoot = new BinaryTreeNode;
        //Root of BalancedBinaryTree
        //First Element of hash table

        //CONSTRUCT THE THREE DATA STRUCTURES
        auto start = chrono::high_resolution_clock::now();
        while(file.get(fileChar))
        {
            if (inWord)
            {
                if(isalpha(fileChar))
                {
                    newWord+=fileChar;
                }
                else
                {
                    if (fileChar != '-' && fileChar != '\'')
                    {
                        //newWord+='\0';
                        if(numberOfWords == 0)
                        {
                            *BinaryTreeRoot = BinaryTreeNode(newWord);
                            //create root of BalancedBinaryTree
                            //insert first element of hash table
                        }
                        else
                        {
                            BinaryTreeRoot->insertNode(newWord);
                            //insert temp to BalancedBinaryTree
                            //insert temp to hash table

                        }

                        //cout<<"Found word: "<<newWord<<endl; //DEBUG
                        numberOfWords++;
                        newWord.clear(); //empties newWord string
                        inWord = false;
                    }
                }
            }
            else
            {
                if (isalpha(fileChar))
                {
                    inWord = true;
                    newWord+=fileChar;
                }
            }
        }
        file.close();
        auto finish = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(finish-start).count();
        duration/=1000000;
        cout<<"Binary Tree Creation lasted: "<<duration<<" seconds!"<<endl;

        //BinaryTreeRoot->PreOrder(); //DEBUG

        cout<<"Created the three data structures, with a total of "<<numberOfWords<<" words"<<endl<<endl;
        cout<<"Insert amount of words to be searched: ";
        int searchAmount;
        cin>>searchAmount;

        if(searchAmount>numberOfWords)
        {
            searchAmount = numberOfWords;
            cout<<"Your input exceeds the total amount of words, the amount of words to be searched has been set to "<<numberOfWords<<endl<<endl;
        }

        //CREATE WORD SEARCH LIST
        string wordsToSearch[searchAmount];
        createSearchList(wordsToSearch, searchAmount, numberOfWords, BinaryTreeRoot);

        auto start = chrono::high_resolution_clock::now();

        for(i=0;i<searchAmount;i++)
        {
            BinaryTreeRoot->SearchWord(wordsToSearch[i]);
        }

        auto finish = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(finish-start).count();
        duration/=1000000;
        cout<<"Binary Tree: Search lasted "<<duration<<" seconds!"<<endl;
    }

    return 0;
}
