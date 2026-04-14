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

int findNodeDepth(Node* root, int key){
    if (root == NULL) return -1;
    
    if (root->data == key) return 0;
    
    if (root->data > key){
        int left = findNodeDepth(root->left, key);
        if (left == -1) return -1;
        else return left + 1;
    }
    else{
        int right = findNodeDepth(root->right, key);
        if (right == -1) return -1;
        else return right + 1;
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

    int key;
    cin >> key;
    
    cout << findNodeDepth(root, key);

    return 0;
}