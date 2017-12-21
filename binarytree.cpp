// Cây nhị phân

#include <iostream>
#include <stdlib.h>
#include <conio.h>

struct Node  // Cấu trúc 1 nút trong cây
{
    int data;
    Node *left;
    Node *right;
};

bool isEmpty(Node *root){  // kiểm tra xem câu có rỗng không
    if(root == NULL) return true;
    else return false;
}

bool isExternal(Node *N){  // Kiểm tra xem 1 nút có phải lá không
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
Node* findNode(Node * root, int data){
    if(isEmpty(root)){
        return NULL;
    }else{
        if(data == root->data) return root;
        if(data < root->data) return findNode(root->left,data);
        if(data > root->data) return findNode(root->right,data);
    }
}

Node* findMasterNode(Node * root, int data){
    if(isEmpty(root) ) return NULL;
    if (findNode(root,data) == NULL) return NULL;
    Node* p = root;
    Node* f = NULL;
    do{
        if(p->data == data) return f;
        f = p;
        if (p->data > data) p = p->left;
        else if (p->data < data) p = p->right;
    } while (p != NULL);
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

// delete Node
bool deleteNode(Node* &root,int data){
    Node* p = findNode(root,data);
    if(p == NULL ) return false;
    if((p->left !=NULL && p->right != NULL) || (p->left == NULL && p->right != NULL)) {  // Nút cần xóa có cả 2 con hoặc chỉ có con phải
        Node* q = p->right;
        while (q->left != NULL) q = q->left; // Tìm nút trái nhất của cây con phải
        int temp = q->data;
        deleteNode(root,temp);  // Xóa nốt q ra khỏi cây
        p->data = temp;
    } else if(p->left != NULL && p->right == NULL){  // Nút cần xóa chỉ có con trái
        Node* q = p->left;
        while (q->right != NULL) q = q->right; // Tìm nút phải nhất của con trái
        int temp = q->data;
        deleteNode(root,temp);  // Xóa nốt q ra khỏi cây
        p->data = temp;
    } else if (p->left == NULL && p->right == NULL){  // Nút cần xóa là nút lá
        Node* f = findMasterNode(root,data);
        if(f == NULL){
            root = NULL;
        } else {
            if(f->data > data) f->left = NULL;
            if(f->data < data) f->right = NULL;
        }
    }
}

int main(){
    Node * root = NULL;
    insertNode(root,6);
    insertNode(root,5);
    insertNode(root,9);
    insertNode(root,15);
    insertNode(root,2);
    insertNode(root,4);
    insertNode(root,1);
    insertNode(root,16);
    insertNode(root,17);
    insertNode(root,13);
    insertNode(root,12);
    insertNode(root,14);
    insertNode(root,11);
    std::cout << "preOrder: " << '\n';
    preOrder(root);
    deleteNode(root,6);
    deleteNode(root,9);
    deleteNode(root,11);
    std::cout << '\n' << "preOrder: " << '\n';
    preOrder(root);
    return 0;
}                                                                                         