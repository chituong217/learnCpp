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

void printInOrderTraversal(Node* root){
    if (root == NULL) return;

    printInOrderTraversal(root->left);
    cout << root->data << ' ';
    printInOrderTraversal(root->right);
}

Node* searchBST(Node* root, int key){
    if (root == NULL) return root;

    if (root->data == key){
        return root;
    }
    else if (key < root->data){
        return searchBST(root->left, key);
    }
    else{
        return searchBST(root->right, key);
    }
}

Node* insertBST(Node* root, int data){
    if (root == NULL) return createNode(data);

    if (data < root->data){
        root->left = insertBST(root->left, data);
    }
    else if (root->data < data){
        root->right = insertBST(root->right, data);
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

Node* deleteBST(Node* root, int data){
    if (root == NULL) return root;

    if (data < root->data){
        root->left = deleteBST(root->left, data);
    }
    else if (root->data < data){
        root->right = deleteBST(root->right, data);
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
            Node* minRightTree = findMinNode(root->right);
            root->data = minRightTree->data;

            root->right = deleteBST(root->right, minRightTree->data);
        }
    }

    return root;
}

int main(){


    return 0;
}