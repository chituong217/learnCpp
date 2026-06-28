#include <bits/stdc++.h>

using namespace std;

struct AVLNode {
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;
};

AVLNode* createNode(int val){
    AVLNode* newNode = new AVLNode;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int getHeight(AVLNode* node){
    if (node == NULL) return 0;
    return node->height;
}

int getBalanceFactor(AVLNode* node){
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    int BF = leftHeight - rightHeight;
    return BF;
}

AVLNode* rotateLeft(AVLNode* x){
    AVLNode* y = x->right;
    AVLNode* h = y->left;

    y->left = x;
    x->right = h;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

AVLNode* rotateRight(AVLNode* y){
    AVLNode* x = y->left;
    AVLNode* h = x->right;

    x->right = y;
    y->left = h;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

AVLNode* insert(AVLNode* root, int val){
    if (root == NULL) return createNode(val);

    if (val < root->data){
        root->left = insert(root->left, val);
    }
    else if (val > root->data){
        root->right = insert(root->right, val);
    }

    // update chieu cao
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // check balance
    int BF = getBalanceFactor(root);

    if (BF > 1){
        if (getBalanceFactor(root->left) >= 0){
            // lech LL
            root = rotateRight(root);
        }
        else{
            // lech LR
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (BF < -1){
        if (getBalanceFactor(root->right) <= 0){
            // lech RR
            root = rotateLeft(root);
        }
        else{
            // lech RL
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }


    return root;
}

void freeAVL(AVLNode* &root){
    if (root == NULL) return;

    freeAVL(root->left);
    freeAVL(root->right);

    delete root;
    root = NULL;
}


