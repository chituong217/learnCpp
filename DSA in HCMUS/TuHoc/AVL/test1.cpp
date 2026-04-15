#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* root){
    if (root == NULL) return 0;
    else return root->height;
}

Node *leftRotate(Node* y){
    Node* x = y->right;
    Node* T = x->left;

    x->left = y;
    y->right =T;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

int getBalance(Node* root){
    if (root == NULL) return 0;
    else return getHeight(root->left) - getHeight(root->right);
}

Node* insert(Node* root, int key){
    // thao tac chen cua BST
    if (root == NULL){
        Node* newNode = new Node;
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < root->data){
        root->left = insert(root->left, key);
    }
    else if (key > root->data){
        root->right = insert(root->right, key);
    }
    else{
        return root;
    }

    // bo sung cho AVL
    // cap nhat lai chieu cao cua node cha sau khi da insert node la
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // kiem tra tinh can bang balance factor
    int BF = getBalance(root);
    if (BF > 1 && getBalance(root->left) >= 0){
        // left - left
        return rightRotate(root);
    }
    
    if (BF < -1 && getBalance(root->right) <= 0){
        // right - right
        return leftRotate(root);
    }

    if (BF > 1 && getBalance(root->left) < 0){
        // left - right
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (BF < -1 && getBalance(root->right) > 0){
        // right - left
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }    

    return root;
}

Node* minValueNode(Node* root){
    Node* current = root;
    while(current != NULL && current->left != NULL){
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key){
    // delete cua cay BST
    if (root == NULL) return root;

    if (root->data > key){
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if (root->left == NULL){
            Node* tmp = root;
            root = root->right;
            delete tmp;
        }
        else if (root->right == NULL){
            Node* tmp = root;
            root = root->left;
            delete tmp;
        }
        else{
            Node* tmp = minValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }

    // bo sung cua cay AVL

    // truong hop cay chi co 1 node va xoa di mat -=> rong
    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int BF = getBalance(root);

    if (BF > 1){
        if (getBalance(root->left) >= 0){
            // left - left
            return rightRotate(root);
        }
        else{
            // left - right
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    
    if (BF < -1){
        if (getBalance(root->right) <= 0){
            // right - right
            return leftRotate(root);
        }
        else{
            // right - left
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

int main(){

    return 0;
}