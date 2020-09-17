#include "AVLTree.h"

AVLTree::AVLTree()
{
}

AVLTree::~AVLTree()
{
    makeEmpty(root);
}

void AVLTree::makeEmpty(Node* node)
{
    if (node == NULL)
        return;
    makeEmpty(node->left);
    makeEmpty(node->right);
    delete node;
}

int AVLTree::Insert(StringKey* k, Worker* d) {
    root = InsertRec(k, d, root);
    if (root == NULL)
        return 0;
    return 1;
}

AVLTree::Node* AVLTree::InsertRec(StringKey* k, Worker* d, Node* node) {

    if (node == NULL) {
        node = new Node();
        node->data = d;
        node->key = k;
        node->left = node->right = NULL;
        node->height = 0;
    }
    //1 is returned for smaller
    else if (k->Compare(node->key) != 1) {
        node->right = InsertRec(k, d, node->right);
    }

    else {
        node->left = InsertRec(k, d, node->left);
    }
    //Calling for balance if needed, and returning the updated node.
    return Balance(node, k);
}

int AVLTree::height(Node* node) {
    return node == NULL ? 0 : node->height;
}

// The right rotation method, we transform our tree, by changing the parent of the nodes and positions, accordingly.
AVLTree::Node* AVLTree::rightRotation(Node* node)
{
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = 1 + max(height(node->left), height(node->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
    return newRoot;
}

// Same principle as right rotation, with opposite directions.
AVLTree::Node* AVLTree::leftRotation(Node* node)
{
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = 1 + max(height(node->left), height(node->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));
    return newRoot;
}

//The balance method, updates the nodes height, then checks and operates the rotations needed.
AVLTree::Node* AVLTree::Balance(Node* node, StringKey* k)
{
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = height(node->left) - height(node->right);

    // If our left subtree is heavier (because the difference is positive)
    // we place our parent as a right-subtree
    if (balance > 1) {
        if (k->Compare(node->left->key) == 1)
            return rightRotation(node);

        // leaf is >= , we first fix subtree, then rotate right
        else {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
    }
    // Our right subtree is heavier
    else if (balance < -1) {
        // leaf is >= , place the parent as left subtree
        if (k->Compare(node->right->key) != 1) {
            return leftRotation(node->left);
        }
        else {
            node->right = rightRotation(node->right);
            return leftRotation(node->left);
        }
    }
    return node;
}

void AVLTree::InorderPrint()
{
    cout << endl;
    InorderPrintRec(root);
}

void AVLTree::InorderPrintRec(Node* root)
{
    if (root == NULL)
        return;
    InorderPrintRec(root->left);
    root->data->printDetails();
    cout << endl;
    InorderPrintRec(root->right);
}

Worker* AVLTree::Find(StringKey* k)
{
    Node* node = FindRec(k, root);
    if (node == NULL)
        return NULL;
    return node->data;
}

AVLTree::Node* AVLTree::FindRec(StringKey* k, Node* node)
{
    if (node == NULL)
        return NULL;
    StringKey* key = node->key;
    if (k->Compare(key) == 0)
        return node;
    else if (k->Compare(key) == 1)
        return FindRec(k, node->left);
    else
        return FindRec(k, node->right);
}

Worker* AVLTree::Delete(StringKey* k)
{
    Worker* worker = NULL;
    root = DeleteRec(k, root, &worker);
    return worker;
}

AVLTree:: Node* AVLTree::DeleteRec(StringKey* k, Node* node,Worker** dataPtr)
{
    if (node == NULL) return NULL;
    if (k->Compare(node->key) == 1) {
        node->left = DeleteRec(k, node->left,dataPtr);
    }
    else if (k->Compare(node->key) == 2) {
        node->right = DeleteRec(k, node->right,dataPtr);
    }
    // we got 0 -> meaning the key equals.
    else {
        Node* right = node->right;
        *dataPtr = node->data;

        if (node->right == NULL) {
            Node* left = node->left;
            delete(node);
            node = left;
        }
        else if (node->left == NULL) {
            delete(node);
            node = right;
        }
        else {
            // The min value of the right subtree is the new root.
            while (right->left != NULL)
                right = right->left;
            node->key = right->key;
            node->data = right->data;
            // we need to delete the min node from the right subtree.
            node->right = DeleteRec(right->key, node->right,dataPtr);
        }
    }
    if (node == NULL)
        return node;
    return Balance(node, k);
}

int AVLTree::isEmpty()
{
    return (root == NULL);
}

void AVLTree::FreeElements()
{
    FreeElementsRec(root);
}

void AVLTree::FreeElementsRec(Node* root)
{
    if (root == NULL)
        return;
    FreeElementsRec(root->left);
    FreeElementsRec(root->right);
    root->FreeData();
}

AVLTree::Node::Node()
{
    height = 0;
    key = NULL;
    data = NULL;
    right = left = NULL;
}

AVLTree::Node::~Node()
{
}

void AVLTree::Node::FreeData()
{
    delete data;
}
