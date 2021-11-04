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

void InOrder(Node* root){
    if(root != NULL){
        InOrder(root->left);
        cout << root->Data << " ";
        InOrder(root->right);
    }
}

void PostOrder(Node* root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->Data << " ";
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

dataType DeleteMin(Node *&root){
	dataType k;
	if(root->left == NULL){
		k = root->Data;
		root = root->right;
		return k;
	}
	else return DeleteMin(root->left);
}

void DeleteNode(dataType x, Node *&root){
	if(root!=NULL)
		if(x < root->Data)	
			DeleteNode(x, root->left);
		else 
			if(x > root->Data)	
				DeleteNode(x,root->right);
			else
				if((root->left==NULL) && (root->right==NULL))
					root = NULL;
				else
					if(root->left == NULL)	
						root = root->right;
					else 
						if(root->right == NULL)	
							root = root->left;
						else
                        	root->Data = DeleteMin(root->right);
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

    cout << "PreOrder of BST :" << endl; 
    preOrder(bst);
    cout << endl;
    
    cout << "InOrder of BST :" << endl; 
    InOrder(bst);
    cout << endl;
    
    cout << "PostOrder of BST :" << endl; 
    PostOrder(bst);
    cout << endl;

    string inp;
    cout << "TYPE IN VALUE TO SEARCH: ";
    getline(cin, inp);
    if(search(bst, inp) != nullptr)
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;

    string inp2;
    cout << "TYPE IN VALUE TO DELETE: ";
    getline(cin, inp2);
    DeleteNode(inp2, bst);
    cout << "Tree after deleting" << endl;
    preOrder(bst);
    
    deleteTree(bst);
}