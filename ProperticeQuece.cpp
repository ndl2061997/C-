// Hàng đợi ưu tiên - Min heap

#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

struct Node // Cấu trúc 1 phần tử của Quece
{
    char *data;
    int propertices;
};

struct Quece // Quece
{
    Node *A;
    int len; // tong so phan tu co trong quece
    int size; // Kích thước của Quece
};
// Khởi tạo hàm đợi
void createQuece(Quece* &h){
    h = (Quece*)malloc(sizeof(Quece*));
    h->len = 0;
    h->size = 0;
}
// Thêm 1 phần tử vào hàm đợi
void add(Quece* &h,char* data, int propertices){
    // Kiểm tra xem hàng đợi còn đủ không gian để thêm không 
    if(h->size == 0) {
        h->A = (Node*) malloc(4*sizeof(Node));
        h->size = 4;
    } else if(h->len >= h->size){
        h->A = (Node*) realloc(h->A,2*h->size*sizeof(Node));
        h->size = h->size*2;
    }  
    h->len ++;
    h->A[h->len].data = data;
    h->A[h->len].propertices = propertices;
    // Up heap
    int i, j;
    i = h->len;
    j = i/2;
    while(i>1){
        if(h->A[i].propertices < h->A[j].propertices ){
            Node temp;
            temp = h->A[i];
            h->A[i] = h->A[j];
            h->A[j] = temp;
        }
        i = j;
        j = j/2;
    }
}

int main(){
    Quece* h;
    createQuece(h);
    add(h,(char*)"Hoc bai ",3);
    add(h,(char*)"di choi ",1);
    add(h,(char*)"Tam ",6);
    add(h,(char*)"An com ",2);
    for(int i = 1 ; i<= h->len;i++){
        std::cout  << h->A[i].data << '\n';
    }
}