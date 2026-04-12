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
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int key){
    if (root == NULL){
        return createNode(key);
    }

    if (key < root->data){
        root->left = insert(root->left,  key);
    }
    else if (key > root->data){
        root->right = insert(root->right, key);
    }

    return root;
}

int findMin(Node* root){
    Node* tmp = root;
    while (tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }

    return tmp->data;
}

int findMax(Node* root){
    Node* tmp = root;
    while (tmp != NULL && tmp->right != NULL){
        tmp = tmp->right;
    }

    return tmp->data;
}

int main(){
    int n, tmp;
    cin >> n;

    cin >> tmp;
    Node* root = createNode(tmp);
    for (int i = 1; i < n; i++){
        cin >> tmp;
        insert(root, tmp);
    }

    cout << findMax(root) << ' ' << findMin(root);

    return 0;
}