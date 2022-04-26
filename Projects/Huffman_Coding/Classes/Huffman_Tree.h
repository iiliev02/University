#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int data;
    char letter;
    Node* left;
    Node* right;
};

class HuffmanTree {
private:
    Node* root;

    /*Приема като аргумент вектор от възел и премахва първия му елемент*/
    void popFront(vector<Node*>&);
    /*Приема като аргумент възел* и унищожава един по един всеки възел*/
    void destructorHelper(Node*);

public:
    HuffmanTree(vector<Node*>);
    ~HuffmanTree();

    /*Връща пътят на текущото дърво*/
    const Node* getRoot() const;
};