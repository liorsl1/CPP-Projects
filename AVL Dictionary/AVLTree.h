#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
#include "Worker.h"

class AVLTree {

    class Node
    {
    public:
        StringKey* key;
        Worker* data;
        Node* left;
        Node* right;
        int height;
        Node();
        ~Node();
        void FreeData();
    };
    Node* root = NULL;

public:
    AVLTree();
    // theta(log(n))
    ~AVLTree();
    // theta(n)
    void makeEmpty(Node* node);
    // theta(log(n))
    int Insert(StringKey* k, Worker* d);
    Node* InsertRec(StringKey* k, Worker* d, Node* node);
    // theta(1)
    int height(Node* node);
    // theta(1)
    Node* rightRotation(Node* node);
    Node* leftRotation(Node* node);
    // theta(log(n))
    Worker* Delete(StringKey* k);
    Node* DeleteRec(StringKey* k, Node* node, Worker** dataPtr);
    // theta(1)
    Node* Balance(Node* node, StringKey* k);
    // theta(n)
    void InorderPrint();
    void InorderPrintRec(Node* root);
    // theta(log(n))
    Worker* Find(StringKey* k);
    Node* FindRec(StringKey* k, Node* node);
    // theta(1)
    int isEmpty();
    // theta(n)
    void FreeElements();
    void FreeElementsRec(Node* root);
};