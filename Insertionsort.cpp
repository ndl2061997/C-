// insertion sort


#include <iostream>
#include <conio.h>
#include <ctime>

void insertionSort(int *A,int l, int r){
    int i,j,key;
    for(i = l;i<=r;i++){
        for(j = l;j<=i;j++){
            if(A[j] > A[i]){
                key = A[i];
                for(int k = i;k>j;k--){
                    A[k] = A[k-1];
                }
                A[j] = key; 
            }
        }
    }
}

int main(){
    int A[100];
    srand(time(NULL));
    for (int i = 0 ; i<10; i++){
        A[i] = rand()%99+1;
    }
    for(int i =0; i<10;i++){
        std::cout << A[i] << " ";
    }
    std::cout  << '\n';
    insertionSort(A,0,9);
    for(int i =0; i<10;i++){
        std::cout << A[i] << " ";
    }
    return 0;
}