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

void deleteTree(Node* node)
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
     
    delete node;
}

int main(){
/*

                     0
                  /      \
                1           2
               /  \        / 
              3    6       8   
            /  \   /      / \
           4    5  7      9  10

*/

    Node* t1 = create2(4, nullptr, nullptr);
    Node* t2 = create2(5, nullptr, nullptr);
    Node* t3 = create2(7, nullptr, nullptr);
    Node* t4 = create2(9, nullptr, nullptr);
    Node* t5 = create2(10, nullptr, nullptr);
    Node* t6 = create2(3, t1, t2);
    Node* t7 = create2(6, t3, nullptr);
    Node* t8 = create2(8, t4, t5);
    Node* t9 = create2(1, t6, t7);
    Node* t10 = create2(2, t8, nullptr);
    Node* root = create2(0, t9, t10);

    cout << "Binary Tree Height: " << bTreeHeight(root) << endl;
    cout << "Number of Nodes in Binary Tree: " << numberOfNodes(root) << endl;
    cout << "Sum of All Nodes in Binary Tree: " << sumOfNodes(root) << endl;

    cout << "PreOrder traversal: ";
    preOrder(root);
    cout << endl << "InOrder traversal: ";
    inOrder(root);
    cout << endl << "PostOrder traversal: ";
    postOrder(root);

    deleteTree(root);
}