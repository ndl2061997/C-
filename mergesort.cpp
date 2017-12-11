// merge sort

#include <iostream>
#include <stdlib.h>

struct array_{  // dinh nghia mang
    int A[100];
    int len;
}
 // Trộn 2 dãy đã sắp
void merge(array_ &A,array_ &B,array_ &C){  
    if(A.len == 0 && B.len >0 ){
        insert_(C,removeMin(B));
        mergt(A,B,C);
    } else if(B.len == 0 && A.len >0){
        insert_(C,removeMin(A));
        merge(A,B,C);
    } else if(B.len <> 0 && A.len <>0){
        if(A.A[0]<B.A[0]){
            insert_(C,removeMin(A));
            merge(A,B,C);
        }
        if(B.A[0]<A.A[0]){
            insert_(C,removeMin(B));
            merge(A,B,C);
        }
    }
}
// thêm 1 phần tử vào mảng
void insert_(array_ &A,int data){
    A.A[A.len] = data;
    A.len ++;
}
// lấy ra phần tử nhỏ nhất trong mảng và xóa nó khỏi mảng
int removeMin(array_ &A){
    int data = A.A[0];
    for (int i = 0; i < A.len -1; i++)
    {
        A.A[i] = A.A[i+1];
    }
    A.len --;
    return data;
}

// Ham cho day ngau nhien

void randomArray_(array_ &A,int n){  // cho random day A voi n phan tu
    for(int i = 0;i<n;i++){
        insert_(A,rand()%100);
    }
}

// sắp xếp trộn dùng đệ quy

void mergerSort(array_ &A,int a0,int an){
    if(an-a0>0){
        
        mergesort(A,a0,(an-a0)%2);
        mergesort(A,(an-a0)%2+1,an);

    }
}