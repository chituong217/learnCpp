#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
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

    if (root->data > key){
        root->left = insert(root->left, key);
    }
    else if (root->data < key){
        root->right = insert(root->right, key);
    }

    return root;
}

void printInOrder(Node* root){
    if (root == NULL) return;

    printInOrder(root->left);
    cout << root->data << ' ';
    printInOrder(root->right);
}

int sumOfLeafNodes(Node* root){
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL){
        return root->data;
    }
    else{
        int left = sumOfLeafNodes(root->left);
        int right = sumOfLeafNodes(root->right);
        return left + right;
    }
}

int main(){
    int n;
    cin >> n;

    int tmp;
    Node* root = NULL;
    for (int i = 0; i < n; i++){
        cin >> tmp;

        if (root == NULL){
            root = createNode(tmp);
        }
        else{
            insert(root, tmp);
        }
    }

    cout << sumOfLeafNodes(root);

    return 0;
}