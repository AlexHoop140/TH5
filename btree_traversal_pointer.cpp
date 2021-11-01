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

Node* newNode(dataType n){
    Node* node = new Node();

    node->Data = n;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preOrderWithoutRecursion(Node *root){

    Node *p = root;
    stack<Node*> ptr_list;
    while(p != NULL || !ptr_list.empty()){
        while(p != NULL){
            cout << p->Data << " ";
            ptr_list.push(p);
            p = p->left;
        }

        p = ptr_list.top();
        ptr_list.pop();
        p = p->right;
    }
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

void inOrderWithoutRecursion(Node *root){

    Node *p = root;
    stack<Node*> ptr_list;
    while(p != NULL || !ptr_list.empty()){
        while(p != NULL){
            ptr_list.push(p);
            p = p->left;
        }

        p = ptr_list.top();
        ptr_list.pop();
        cout << p->Data << " ";
        p = p->right;
    }
        
}

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->Data << " ";
    }
}

void postOrderWithoutRecursion(Node *root){
    Node *p = root;
    Node *last_visited = NULL;
    stack<Node*> ptr_list;

    while((p != NULL) && (last_visited != root)){
        while((p != NULL) && (p != last_visited)){
            ptr_list.push(p);
            p = p->left;
        }

        p = ptr_list.top();
        ptr_list.pop();

        if((p->right == NULL) || (p->right == last_visited)){
            cout << p->Data << " ";
            last_visited = p;
        }else{
            ptr_list.push(p);
            p = p->right;
        }
    }
}

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

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
Node* minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

Node* deleteNode(Node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->Data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->Data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete (root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->Data = temp->Data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->Data);
    }
    return root;
}

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
    Node *root = newNode(0);
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

    // Node* root = newNode(10);
    // root->left = newNode(8);
    // root->right = newNode(2);
    // root->left->left = newNode(3);
    // root->left->right = newNode(5);

    // Node *root = new Node;
    // root = NULL;
    // root = insert(root, 5);
    // root = insert(root, 1);
    // root = insert(root, 6);
    // int n; 
    // cout << "Nhap so phan tu cho cay: ";
    // cin >> n;
    // input(root, n);

    // preOrder(root);
    // inOrder(root);
    
    // preOrder(root->right);
}