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

void makeRoot(Node* root, int con, char nhanh){
    if (nhanh == 'L'){
        root->left = createNode(con);
    }
    else{
        root->right = createNode(con);
    }
}

void insertNode(Node* root, int cha, int con, char nhanh){
    if (root == NULL) return;
    
    if (root->data == cha){
        makeRoot(root, con, nhanh);
    }
    else{   
        insertNode(root->left, cha, con, nhanh);
        insertNode(root->right, cha, con, nhanh);
    }
}

int tinhDoCaoCuaCay(Node* root){
    if (root == NULL){
        return -1;
    }
    else{
        return max(tinhDoCaoCuaCay(root->left) + 1, tinhDoCaoCuaCay(root->right) + 1);
    }
}


int main(){
    Node* root = NULL;
    int n;
    cin >> n;

    while (n--){
        int cha, con;
        char nhanh;
        cin >> cha >> con >> nhanh;

        if (root == NULL){
            root = createNode(cha);
            makeRoot(root, con, nhanh);
        }
        else{
            insertNode(root, cha, con, nhanh);
        }
    }

    cout << tinhDoCaoCuaCay(root);

    return 0;
}