// insertion sort


#include <iostream>
#include <stdlib.h>

struct Array_
{
    int A[100];
    int len;
};

void add(Array_ &A,int data){
    A.len ++;
    A.A[A.len] = data;
}

void insertionSort(Array_ &A){
    int i,j,key;
    for ( j = 1; j <= A.len ; j++) // duyet tung phan tu tu phan tu so 1
    {  
       key = A.A[j];
        for (i = 0; i <j-1 ; i++) // tim vi tri chen A.A[j]
        {   
            if (A.A[i]>key)
            {
                for(int k = j; k > i;k--){ // chen A.A[j]
                    A.A[k] = A.A[k-1];
                }
                A.A[i] = key;
                break;
            }
        }
    }
}

int main(){
    Array_ A;
    int key;
    add(A,5);
    add(A,4);
    add(A,6);
    add(A,2);
    add(A,8);
    add(A,9);
    add(A,7);
    add(A,3);
    add(A,6);
    add(A,1);
    for(int i = 0 ; i <= A.len ; i++){
        std::cout << " " << A.A[i];
    }
    insertionSort(A);
    std::cout << "" << '\n';
    for(int i = 0 ; i <= A.len ; i++){
        std::cout << " " << A.A[i];
    }
    return 0;
}