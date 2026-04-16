#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int getHeight(Node* root){
    if (root == NULL){
        return 0;
    }
    return root->height;
}

int getBalance(Node* root){
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node* rotateLeft(Node* y){
    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* rotateRight(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* insertNode(Node* root, int key){
    if (root == NULL){
        return createNode(key);
    }

    if (key < root->data){
        root->left = insertNode(root->left, key);
    }
    else if (key > root->data){
        root->right = insertNode(root->right, key);
    }
    else{
        return root;
    }

    // sau khi da insert cua BST
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int BF = getBalance(root);
    if (BF > 1){
        // left
        if (getBalance(root->left) >= 0){
            // left - left
            return rotateRight(root);
        }
        else{
            // left - right
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (BF < -1){
        // right
        if (getBalance(root->right) <= 0){
            // right - right
            return rotateLeft(root);
        }
        else{
            // right - left
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

Node* getMinValueNode(Node* root){
    Node* tmp = root;
    while (tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }
    
    return tmp;
}

Node* deleteNode(Node* root, int key){
    if (root == NULL) return root;

    if (key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data){
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
            Node* tmp = getMinValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }

    // sau khi da deleteNode theo BST
    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int BF = getBalance(root);
    if (BF > 1){
        // left
        if (getBalance(root->left) >= 0){
            // left - left
            return rotateRight(root);
        }
        else{
            // left - right
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (BF < -1){
        // right
        if (getBalance(root->right) <= 0){
            // right - right
            return rotateLeft(root);
        }
        else{
            // right - left
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

void printInOrder(Node* root){
    if (root == NULL) return;

    printInOrder(root->left);
    cout << root->data << ' ';
    printInOrder(root->right);
}

int main(){
    Node* root = NULL;

    int n, tmp;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        root = insertNode(root, tmp);
    }

    printInOrder(root);

    return 0;
}