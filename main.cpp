#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

// c��u tru�c nu�t cu�a c�y
struct Node{
    int data;
    Node *left;
    Node *right;
};
// cây
struct  BinaryTree{
    Node *root;
};
// tạo 1 nút mới
Node* createNode(){
    Node *N;
	N = (Node*)malloc(sizeof(Node));
    N->data = 0;
    N->left = NULL;
    N->right = NULL;
    return N;
}
// Khởi tạo 1 cây mới
BinaryTree* createTree()
{
	BinaryTree *T;
	T = (BinaryTree*)calloc(1,sizeof(BinaryTree));
    T->root = NULL;
    return T;
}
// Tìm 1 nút của cây
Node* search(int data, Node *root){	
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    if (root->data > data)
        return search(data, root->left);
    if (root->data < data)
        return search(data, root->right);
}
// thêm 1 nút vào cây
void insertNode(Node* &root, int data)
{   
	if(root == NULL){
		root = createNode();	
		root->data = data;
	} else {
		if(root->data > data) insertNode(root->left,data);
		if(root->data < data) insertNode(root->right,data);	
	}
}

// Ti�m con nho� nh��t cu�a 1 nu�t

// Xo�a 1 nu�t kho�i c�y

/*void deleteNode(Node* &root, int data){
    Node *N;
    N = search(data,root);
    if(N != NULL){
        if(findMinchild(N) == N){ // tr���ng h��p na�y N la� 1 nu�t la�
            N = NULL;
        } else if(findMinchild(N) != N){ // Tr���ng h��p na�y N kh�ng pha�i la� 1 nu�t la�
            N->data = findMinchild(N)->data;         // ta ga�n N = con nho� nh��t
        	//findMinchild(N)=NULL;
		}
    }
}*/

// Ca�c ph��ng pha�p duy��t c�y
// preOrder

void preOrder(Node* root){
    if(root!=NULL){
        std::cout <<  root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// inOrder

void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}

// PostOrder
void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->data << " ";
        
    }
}

int main(){
    BinaryTree *T;
    T = createTree();
    insertNode(T->root,10);
    insertNode(T->root,13);
    insertNode(T->root,9);
    insertNode(T->root,1);
    insertNode(T->root,5);
    insertNode(T->root,17);
    insertNode(T->root,20);
    insertNode(T->root,15);
    insertNode(T->root,7);
    insertNode(T->root,2);
    insertNode(T->root,6);
    insertNode(T->root,14);
    preOrder(T->root);
    std:: cout << '\n';
    Node * N = search(5,T->root);
    if (N != NULL) std:: cout << "Tim thay";
    else std:: cout << "Kh�ng tim thay";
    N = search(5,T->root);
    N->data = 6;
    preOrder(T->root); 
    int n; 
    std::cout << " Nhap vao n ";
    std::cin >> n;
    getch();
    return 0;
}

