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

Node* search(Node* root, int key){
    if (root == NULL) return root;

    if (root->data == key){
        return root;
    }
    else if (root->data < key){
        return search(root->right, key);
    }
    else{
        return search(root->left, key);
    }
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

Node* findMinValueNode(Node* root){
    Node* tmp = root;
    while (tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }

    return tmp;
}

Node* deleteNode(Node* root, int key){
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
            Node* tmp = findMinValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }

    return root;
}

int main(){
    Node* root = NULL;
    int n;
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;

        if (root == NULL){
            root = createNode(tmp);
        }
        else{
            insert(root, tmp);
        }
    }

    printInOrder(root);

    return 0;
}