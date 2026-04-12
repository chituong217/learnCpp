#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void makeRoot(Node* root, int con, char nhanh)
{
    if (nhanh == 'L')
    {
        root->left = createNode(con);
    }
    else
    {
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

void printInOrder(Node* root){
    if (root == NULL) return;

    printInOrder(root->left);
    cout << root->data << ' ';
    printInOrder(root->right);
}

int main()
{
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

    printInOrder(root);

    return 0;
}