#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
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

void insertNode(Node* root, int cha, int con, char nhanh)
{
    if (root == NULL) return;

    if (root->data == cha){
        makeRoot(root, con, nhanh);
    }
    else{
        insertNode(root->left, cha, con, nhanh);
        insertNode(root->right, cha, con, nhanh);
    }
}

void printPreOrder(Node* root){
    if (root == NULL) return;

    cout << root->data << ' ';
    printPreOrder(root->left);
    printPreOrder(root->right);
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

    printPreOrder(root);
    
    return 0;
}