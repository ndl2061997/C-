// Cây nhị phân

#include <iostream>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isEmpty(Node *root){
    if(root == NULL) return true;
    else return false;
}

bool isExternal(Node *N){
    if(N->left == NULL && N->right == NULL){
        return true;
    }else{
        return false;
    }
}

Node* createNode(){
    Node *N;
    N = (Node*)malloc(sizeof(Node));
    N->left = NULL;
    N->right = NULL;
    return N;
}

void insertNode(Node* &root,int data){ // Truyền tham biến cho con trỏ kiểu Node 
    if(isEmpty(root)){
        root = createNode();
        root->data = data;
    }else{
        if(data < root->data)  insertNode(root->left,data);
        if(data > root->data)  insertNode(root->right,data);
    }
}
// Find Node
bool findNode(Node * root, int data){
    if(isEmpty(root)){
        return false;
    }else{
        if(data == root->data) return true;
        if(data < root->data) return findNode(root->left,data);
        if(data > root->data) return findNode(root->right,data);
    }
}

// Các thuật toán duyệt cây

// Duyệt theo thứ tự trước
void preOrder(Node* root){    
    if(root != NULL){
        std::cout << " " << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Duyệt theo thứ tự trong 
void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        std::cout << " " << root->data;
        inOrder(root->right);
    }
}
// Duyệt theo thứ tự sau
void postOrder(Node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        std::cout << " " << root->data;
    }
}

int main(){
    Node * root = NULL;
    insertNode(root,6);
    insertNode(root,5);
    insertNode(root,7);
    insertNode(root,10);
    insertNode(root,2);
    insertNode(root,4);
    insertNode(root,1);
    std::cout << "preOrder: " << '\n';
    preOrder(root);
    std::cout << '\n'<<"inOrder: " << '\n';
    inOrder(root);
    std::cout << '\n' << "postOrder:" << '\n';
    postOrder(root);
    return 0;
}