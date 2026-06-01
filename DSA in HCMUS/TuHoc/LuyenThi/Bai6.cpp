#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    int height;
};

int getHeight(Node* root){
    if (root == NULL) return 0;
    return root->height;
}

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

Node* insert(Node* root, int data){
    if (root == NULL) return createNode(data);

    if (data < root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right)); 

    return root;
}

bool checkAVL(Node* root){
    if (root == NULL) return true;

    int BF = getHeight(root->left) - getHeight(root->right);
    if (BF > 1 || BF < -1) return false;
    else{
        return checkAVL(root->left) && checkAVL(root->right);
    }
}

int main(){
    Node* root = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        
        root = insert(root, tmp);
    }

    if (checkAVL(root)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}