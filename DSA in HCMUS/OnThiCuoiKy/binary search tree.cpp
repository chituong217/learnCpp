#include <bits/stdc++.h>

using namespace std;

// Binary search tree

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};


BSTNode* createNode(int val){
    BSTNode* newNode = new BSTNode;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BSTNode* insert(BSTNode* root, int val){
    if (root == NULL){
        return createNode(val);
    }

    if (val < root->data){
        root->left = insert(root->left, val);
    }
    else if (root->data < val){
        root->right = insert(root->right, val);
    }

    return root;
}

BSTNode* findMin(BSTNode* root){
    BSTNode* tmp = root;
    while (tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }    

    return tmp;
}

BSTNode* remove(BSTNode* root, int val){
    if (root == NULL) return root;

    if (val < root->data){
        root->left = remove(root->left, val);
    }
    else if (root->data < val){
        root->right = remove(root->right, val);
    }
    else{
        if (root->left == NULL){
            BSTNode* tmp = root;
            root = root->right;
            delete tmp;
        }
        else if (root->right == NULL){
            BSTNode* tmp = root;
            root = root->left;
            delete tmp;
        }
        else{
            BSTNode* minNode = findMin(root->right);
            root->data = minNode->data;

            root->right = remove(root->right, minNode->data);
        }
    }

    return root;
}

void inorder(BSTNode* root){
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void freeTreeRecursive(BSTNode* &root){
    if (root == NULL) return;
    freeTreeRecursive(root->left);
    freeTreeRecursive(root->right);
    delete root;
    root = NULL;
}

void freeTree(BSTNode* &root){
    if (root == NULL) return;

    queue<BSTNode*> q;
    q.push(root);

    while (q.empty() == false){
        BSTNode* top = q.front();
        q.pop();

        if (top->left != NULL) q.push(top->left);
        if (top->right != NULL) q.push(top->right);

        delete top;
    }

    root = NULL;
}


