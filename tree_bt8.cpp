#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef int dataType;

struct Node{
    dataType Data;
    Node *parent;
    Node *left;
    Node *right;
};

Node* newNode(dataType n){
    Node* node = new Node();

    node->Data = n;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* leftChild(Node* root){
    if(root != NULL){
        return root->left;
    } else 
        return NULL;
}

Node* rightChild(Node* root){
    if(root != NULL){
        return root->right;
    } else 
        return NULL;
}

int isLeaf(Node* root){
    if(root != NULL){
        return (leftChild(root)==NULL) && (rightChild(root)==NULL);
    }
    return 0;
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

void tagParent(Node *root){ 
    if(root != NULL){
        if(rightChild(root) != NULL){
            root->right->parent = root; 
        };
        if(leftChild(root) != NULL){
            root->left->parent = root; 
        };
        tagParent(root->left);
        tagParent(root->right);
    }
}

Node *locateNode(struct Node* node, int key)
{
    if(node != NULL){
        if(node->Data == key){
            return node;
        } else{
            Node *temp = locateNode(node->left, key);
            if(temp == NULL){
                temp = locateNode(node->right, key);
            }
            return temp;
        }
    } else{
        return NULL;
    }
}

bool checkDNA(Node *root, Node *n, Node *m){
    if((n != NULL && m != NULL) && (n->parent == m->parent)){
        return true;
    }else 
        return false;
}

bool checkAncestor(Node *p, Node *m){
    // Node *p = n;
    if(p != NULL){
        // cout << "p data: " << p->Data << endl;
        if(p->Data == m->Data){
            return true;
        } else{
            checkAncestor(p->parent, m);
        }
    }
    if(p == NULL)
        return false;
}

int countNodeWithOneLeaf(Node *root){
    Node *p = root;
    if (p == NULL) return 0;
    if ((p->left != NULL && p->right == NULL) || (p->left==NULL && p->right != NULL))
        return 1 + countNodeWithOneLeaf(p->left) + countNodeWithOneLeaf(p->right);
    else 
        return countNodeWithOneLeaf(p->left) + countNodeWithOneLeaf(p->right);

}

int countLeaves(Node *root){
    Node *p = root;
    if(p == NULL) 
        return 0;
    if((p->left == NULL) && (p->right == NULL)){
        return 1 + countLeaves(p->left) + countLeaves(p->right);
    } else{
        return countLeaves(p->left) + countLeaves(p->right);
    }
};

void deleteTree(Node* node)
{
    if (node == NULL) return;

    deleteTree(node->left);
    deleteTree(node->right);
     
    delete node;
}

int main(){
/*

                     0
                  /      \
                1           2
               /  \          / \
              3    6        8    12
            /  \   / \     / \
           4    5  7  13  9  10

*/
    Node *root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(13);
    root->right->left = newNode(8);
    root->right->right = newNode(12);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);


    tagParent(root);

    if (checkDNA(root, locateNode(root, 1), locateNode(root, 2)) == true){
        cout << "Those nodes have the same father node" << endl;
    } else
        cout << "Those nodes DO NOT have the same father node" << endl;

    if (checkAncestor(locateNode(root, 9), locateNode(root, 1)) == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << "Number of node with only one leaf: " << countNodeWithOneLeaf(root);
    cout << endl;
    cout << "Number of leaves: " << countLeaves(root);

    deleteTree(root);
}