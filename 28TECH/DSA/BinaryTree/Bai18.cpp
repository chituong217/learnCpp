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

Node* insert(Node* root, int key){
    if (root == NULL){
        return createNode(key);
    }
    if (key < root->data){
        root->left = insert(root->left, key);
    }
    else if (key > root->data){
        root->right = insert(root->right, key);
    }

    return root;
}

Node* findMinNode(Node* root){
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

void printPostOrder(Node* root){
    if (root == NULL) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << ' ';
}

int main(){
    int n;
    cin >> n;

    int tmp;
    cin >> tmp;
    Node* root = createNode(tmp);

    for (int i = 1; i < n; i++){
        cin >> tmp;
        insert(root, tmp);    
    }

    printPostOrder(root);

    return 0;
}