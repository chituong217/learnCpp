#include <iostream>
#include <set>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right; 
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;

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

void isLeafSameLevel(Node* root, int level, set<int> &leafsLevel){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL){
        leafsLevel.insert(level);
        return;
    }
    else{
        isLeafSameLevel(root->left, level + 1, leafsLevel);
        isLeafSameLevel(root->right, level + 1, leafsLevel);
    }
}

bool isPerfectBT(Node* root){
    if (root == NULL) return true;

    if (root->left == NULL && root->right == NULL){
        return true;
    }
    else if (root->left != NULL && root->right != NULL){
        return isPerfectBT(root->left) && isPerfectBT(root->right);
    }
    else{
        return false;
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

    bool isValid = true;
    set<int> leafsLevel;
    isLeafSameLevel(root, 0, leafsLevel);
    if(leafsLevel.size() > 1){
        isValid = false;
    }
    if (isPerfectBT(root) == false){
        isValid = false;
    }

    if (isValid == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}