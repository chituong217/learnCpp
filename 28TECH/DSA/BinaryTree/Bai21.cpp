#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* findMinNode(Node* root){
    Node* tmp = root;
    while (tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }

    return tmp;
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

    return root;
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
            Node* tmp = root->right;
            delete root;

            return tmp;
        }
        else if (root->right == NULL){
            Node* tmp = root->left;
            delete root;

            return tmp;
        }
        else{
            Node* tmp = findMinNode(root->right);

            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
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
    int n, tmp, x;
    cin >> n >> tmp;
    Node* root = createNode(tmp);
    for (int i = 1; i < n; i++){
        cin >> tmp;
        insertNode(root, tmp);
    }

    cin >> x;
    root = deleteNode(root, x);

    printInOrder(root);

    return 0;
}