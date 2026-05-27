#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int findValueLastNode(Node* root){
    if (root == NULL) return -1;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node* top = q.front();
        q.pop();

        if (top->left != NULL) q.push(top->left);
        if (top->right != NULL) q.push(top->right);

        if (q.size() == 0) return top->data;
    }

    return -1;
}

int main(){


    return 0;
}