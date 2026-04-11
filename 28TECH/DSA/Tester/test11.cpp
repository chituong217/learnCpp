#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

};

Node* createNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// sau khi tim thay node cha
void makeRoot(Node* root, int v, char c){
    if (c == 'L'){
        root->left = createNode(v);
    }
    else{
        root->right = createNode(v);
    }
}

// cho v la node con cua u
void insertNode(Node* root, int u, int v, char c){
    if (root == NULL) return;

    if (root->data == u){
        makeRoot(root, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void inorder(Node* root){
   if (root == NULL) return;

   inorder(root->left);
   cout << root->data << ' ';
   inorder(root->right);
}

int main(){
    Node* root = NULL;

    int n;
    cin >> n;

    while(n--){
        int u, v;
        char c;
        cin >> u >> v >> c;

        if (root == NULL){
            root = createNode(u);

            makeRoot(root, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }

    inorder(root);


    return 0;
}