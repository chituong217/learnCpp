#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int data){
    if (root == NULL) return newNode(data);

    if (root->key < data){
        root->right = insert(root->right, data);
    }
    else if (root->key > data){
        root->left = insert(root->left, data);
    }
    
    return root;
}

Node* search(Node* root, int data){
    if (root == NULL || root->key == data) return root;

    if (root->key < data){
        return search(root->right, data);
    }
    else{
        return search(root->left, data);
    }
}

Node* findMinNode(Node* root){
    Node* tmp = root;
    while (tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }

    return tmp;
}

Node* deleteNode(Node* root, int data){
    if (root == NULL) return root;

    if (root->key < data){
        root->right = deleteNode(root->right, data);
    }
    else if (root->key > data){
        root->left = deleteNode(root->left, data);
    }
    else{
        if (root->left == NULL){
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL){
            Node* tmp = root->left;
            delete root;
            return tmp;
        }

        Node* tmp = findMinNode(root->right);
        root->key = tmp->key;
        root->right = deleteNode(root->right, tmp->key);
    }

    return root;
}

void NLR(Node* root){
    if (root == NULL) return;

    cout << root->key << ' ';
    NLR(root->left);
    NLR(root->right);
}

void LNR(Node* root){
    if (root == NULL) return;

    LNR(root->left);
    cout << root->key << ' ';
    LNR(root->right);
}

void LRN(Node* root){
    if (root == NULL) return;

    LRN(root->left);
    LRN(root->right);
    cout << root->key << ' ';
}

void levelOrder(Node* root){
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (q.empty() == false){
        Node* top = q.front();
        q.pop();
        cout << top->key << ' ';

        if (top->left != NULL) q.push(top->left);
        if (top->right != NULL) q.push(top->right);
    }
}

int main(){
    Node* root = NULL;
    int lenh;

    while (cin >> lenh){
        if (lenh == 1){
            int x;
            cin >> x;

            root = insert(root, x);
        }
        else if (lenh == 2){
            int x;
            cin >> x;

            if (search(root, x) == NULL){
                cout << "false\n";
            }
            else{
                cout << "true\n";
                root = deleteNode(root, x);
            }
        }
        else if (lenh == 3){
            string s;
            cin >> s;

            if (s == "NLR") NLR(root);
            else if (s == "LNR") LNR(root);
            else if (s == "LRN") LRN(root);
            else if (s == "LevelOrder") levelOrder(root);
            cout << "\n";
        }
        else if (lenh == 4){
            int x;
            cin >> x;
            if (search(root, x) == NULL) cout << "false\n";
            else cout << "true\n";
        }
    }

    return 0;
}