#include <iostream>
#include <string>

using namespace std;

struct Node{
    char data;
    Node* next;
};

struct Stack{
    Node* top;
    int size;
};

Node* createNode(char data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void push(Stack &st, char data){
    Node* newNode = createNode(data);
    newNode->next = st.top;

    st.top = newNode;
    st.size++;
}

char pop(Stack &st){
    if (st.top != NULL){
        Node* tmp = st.top;
        st.top = tmp->next;
        char top = tmp->data;

        delete tmp;
        st.size--;

        return top;
    }
    return '\0';
}

bool isEmpty(Stack &st){
    return st.top == NULL;
}

int precedence(char x){
    // ham kiem tra do uu tien
    if (x == '+' || x == '-'){
        return 1;
    }
    else if (x == '*' || x == '/'){
        return 2;
    }
    else{
        return 0;
    }
}

string infixToPostfix(string infix){
    Stack st;
    st.top = NULL; st.size = 0;
    string postfix = "";

    for (int i = 0; i < (int)infix.size(); i++){
        if (isalpha(infix[i]) || isdigit(infix[i])){
            postfix += infix[i];
        }
        else{
            if (isEmpty(st)){
                push(st, infix[i]);
            }
            else{
                if (infix[i] == '('){
                    push(st, infix[i]);
                }
                else if (infix[i] == ')'){
                    while (isEmpty(st) == false && st.top->data != '('){
                        postfix = postfix + pop(st);
                    }
                    pop(st); // lay dau mo ngoac ra
                }
                else{
                    while (isEmpty(st) == false && precedence(infix[i]) <= precedence(st.top->data)){
                        postfix = postfix + pop(st);
                    }

                    push(st, infix[i]);
                }
            }
        }
    }
    while (isEmpty(st) == false){
        postfix = postfix + pop(st);
    }

    return postfix;
}

int main(){

    return 0;
}