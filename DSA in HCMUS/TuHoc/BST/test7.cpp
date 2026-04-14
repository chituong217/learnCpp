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

Node* findSuccessor(Node* root, int key){
    Node* successor = NULL;
    Node* current = root;

    while (current != NULL){
        if (current->data == key){
            if (current->right == NULL){
                // tra ve node cha
                return successor;
            }
            else{
                // tim node con nho nhat lon hon key
                Node* tmp = current->right;
                while(tmp != NULL && tmp->left != NULL){
                    tmp = tmp->left;
                }

                return tmp;
            }
        }
        else{
            if (current->data > key){
                successor = current;
                current = current->left;
            }
            else{
                current = current->right;
            }
        }
    }

    return NULL;
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

    int key; cin >> key;
    Node* res = findSuccessor(root, key);

    if (res == NULL){
        cout << "NONE";
    }
    else{
        cout << res->data;
    }

    return 0;
}