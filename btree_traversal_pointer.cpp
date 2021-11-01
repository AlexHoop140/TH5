#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef int dataType;

struct Node{
    dataType Data;
    Node *left;
    Node *right;
};

void init(Node* root){
    root = new Node();
}

Node* newNode(dataType n){
    Node* node = new Node();

    node->Data = n;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* create2(dataType val, Node* left, Node* right){
    Node* n = new Node();
    n->Data = val;
    n->left = left;
    n->right = right;
    return n;
}

void preOrder(Node* root){
    if(root != NULL){
        cout << root->Data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->Data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->Data << " ";
    }
}



/*
Node *insert(Node *root, int key){
    if(root == NULL)
        return newNode(key);
    if(root->Data > key)
        root->left = insert(root->left, key);
    else if(root->Data < key)
        root->right = insert(root->right, key);

    return root;
}

void input(Node *&root, int n){
    for(int i = 0; i < n; i++){
        int key;
        cout << "Nhap gia tri: ";
        cin >> key;
        root = insert(root, key);
    }
}
*/

int bTreeHeight(Node *root){
    int leftTreeHeight = 0, rightTreeHeight  = 0;
    if(root == NULL)
        return -1;
    leftTreeHeight = bTreeHeight(root->left);
    rightTreeHeight = bTreeHeight(root->right);

    if(leftTreeHeight > rightTreeHeight)
        return leftTreeHeight + 1;
    else
        return rightTreeHeight + 1;
}

int numberOfNodes(Node *root){
    if(root == NULL)
        return 0;
    return 1 + numberOfNodes(root->right) + numberOfNodes(root->left);
}

int sumOfNodes(Node *root){
    if(root == NULL)
        return 0;
    return root->Data + sumOfNodes(root->right) + sumOfNodes(root->left);
}

int main(){
    
    Node *root;
    init(root);
    root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(7);
    root->right->left = newNode(8);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);

    cout << bTreeHeight(root) << endl;
    cout << numberOfNodes(root) << endl;
    cout << sumOfNodes(root) << endl;

    preOrder(root);
    inOrder(root);
    postOrder(root);
}