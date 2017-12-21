// Merge Sort

#include <iostream>
#include <conio.h>
#include <ctime>
// Merge
void merge(int * A, int a1,int a2, int * B , int b1, int b2, int *C){
    int i;
    i = 0;
    while (a1<=a2 && b1<=b2){
        if(A[a1]< B[b1]){
            C[i] = A[a1];
            a1 ++;
            i++;
        }else if(A[a1]>= B[b1]){
            C[i] = B[b1];
            b1 ++;
            i++;
        }
    }
    if(a1>a2){
        for(int j = b1;j<=b2;j++){
            C[i] = B[j];
            i++;
        }
    }
    if(b1>b2){
        for(int j = a1;j<=a2;j++){
            C[i] = A[j];
            i++;
        }
    }
}

// mergesort

void mergesort(int *A, int a, int b){
    if(a<b){
        int j = 0;
        mergesort(A,a,(a+b)/2);
        mergesort(A,(a+b)/2+1,b);
        int C[b-a+1];
        merge(A,a,(a+b)/2,A,(a+b)/2 +1,b,C);
        for(int i = a; i<=b ;i ++){
            A[i] = C[j];
            j++;
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
    mergesort(A,0,9);
    for(int i =0; i<10;i++){
        std::cout << A[i] << " ";
    }
}