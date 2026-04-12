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

bool searchBST(Node* root, int key){
    if (root == NULL) return false;

    if (root->data == key){
        return true;
    }
    else if (root->data > key){
        return searchBST(root->left, key);
    }
    else{
        return searchBST(root->right, key);
    }
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
    if (searchBST(root, x) == true){
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}