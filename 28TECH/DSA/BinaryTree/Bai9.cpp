#include <iostream>
#include <queue>
#include <stack>

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

void printSpiralOrder(Node* root){
    if (root == NULL) return;
    
    stack<Node*> st1, st2;

    st1.push(root);
    while (st1.empty() == false || st2.empty() == false){
        while (st1.empty() == false){
            Node* tmp = st1.top();
            st1.pop();
            cout << tmp->data << ' ';

            if (tmp->right != NULL){
                st2.push(tmp->right);
            }
            if (tmp->left != NULL){
                st2.push(tmp->left);
            }
        }
        while (st2.empty() == false){
            Node* tmp = st2.top();
            st2.pop();
            cout << tmp->data << ' ';

            if (tmp->left != NULL){
                st1.push(tmp->left);
            }
            if (tmp->right != NULL){
                st1.push(tmp->right);
            }
        }
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

    printSpiralOrder(root);
    
    return 0;
}