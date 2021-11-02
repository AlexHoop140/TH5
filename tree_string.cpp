#include <iostream>
#include <string>

using namespace std;

typedef string dataType;

struct Node{
    dataType Data;
    Node *left;
    Node *right;
};

void init(Node *&root){
    root = new Node();
}

Node* newNode(dataType n){
    Node* node = new Node;

    node->Data = n;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

void addNode(Node *&root, string str){
    Node *p = root;
    if((p == nullptr)){
        p = newNode(str);
    } else {
        if(p->Data > str){
            if(p->left != nullptr){
                addNode(p->left, str);
            } else{
                p->left = newNode(str);
            }
        } else{
            if(p->right != nullptr){
                addNode(p->right, str);
            } else {
                p->right = newNode(str);
            }
        }
    }
}

void preOrder(Node* root){
    if(root != NULL){
        cout << root->Data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void deleteTree(Node*& node)
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
     
    delete node;
}


Node *search(Node *root, dataType str){
    if(root == nullptr){
        return nullptr;
    } else {
        if(root->Data == str)
            return root;
        else if(root->Data < str)
                return search(root->right, str);
            else
                return search(root->left, str);
    }
}


int main(){
    Node *bst;
    init(bst);
    addNode(bst, "abd");
    addNode(bst, "zb");
    addNode(bst, "a");
    addNode(bst, "cb");
    addNode(bst, "abc");
    addNode(bst, "bcd");
    addNode(bst, "efg");
    addNode(bst, "hik");
    addNode(bst, "pkll");
    addNode(bst, "trung");
    addNode(bst, "ptl");
    addNode(bst, "tpa");

    preOrder(bst);
    cout << endl;
    if(search(bst, "k") != nullptr)
        cout << "Co";
    else
        cout << "Khong co";
    deleteTree(bst);
}