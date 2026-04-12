#include <iostream>
#include <queue>

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

void printLevelOrder(Node* root){
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (q.empty() == false){
        Node* tmp = q.front(); 
        q.pop();
        cout << tmp->data << ' ';

        if (tmp->left != NULL){
            q.push(tmp->left);
        }
        if (tmp->right != NULL){
            q.push(tmp->right);
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

    printLevelOrder(root);
    
    return 0;
}