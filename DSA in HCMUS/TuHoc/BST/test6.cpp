#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int key){
    if (root == NULL){
        return createNode(key);
    }

    if (root->data > key){
        root->left = insert(root->left, key);
    }
    else if (root->data < key){
        root->right = insert(root->right, key);
    }

    return root;
}

void printInOrder(Node* root){
    if (root == NULL) return;

    printInOrder(root->left);
    cout << root->data << ' ';
    printInOrder(root->right);
}

bool isValidBST(Node* root, int min, int max){
    if (root == NULL) return true;

    if (root->data <= min || root->data >= max){
        return false;
    }
    else{
        return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
    }
}

int main(){
    int n;
    cin >> n;

    int tmp;
    Node* root = NULL;
    for (int i = 0; i < n; i++){
        cin >> tmp;

        if (root == NULL){
            root = createNode(tmp);
        }
        else{
            insert(root, tmp);
        }
    }

    if (isValidBST(root, INT_MIN, INT_MAX)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}