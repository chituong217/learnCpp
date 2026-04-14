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

int sumRangeSearchBST(Node* root, int L, int R){
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL){
        if (L <= root->data && root->data <= R){
            return root->data;
        }
        else{
            return 0;
        }
    }
    else{
        int mid = 0;
        if (root->data >= L && root->data <= R){
            mid = root->data;
        }

        int left = 0, right = 0;
        if (root->data > L){
            left = sumRangeSearchBST(root->left, L, R);
        }
        if (root->data < R){
            right = sumRangeSearchBST(root->right, L, R);
        }
        return mid + left + right;
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

    int L, R; cin >> L >> R;
    cout << sumRangeSearchBST(root, L, R);

    return 0;
}