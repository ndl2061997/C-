#include <iostream>
#include <stdlib.h>

int intToBinary(int *b,int n){
    int i,k;
    int C[100];
    i = 0;
    while ((n/2)>0){
        C[i] = n%2;
        i++;
        n = (int)(n/2);
    }
    C[i] = n%2;
    i++;
    for(int j = 0;j<=(i-1);j++){
        k = i-j;
        std::cout <<  k << " " ;
        std::cout <<  C[k];
    }
}

void BinarytoGray(int b[], int n){
    int i;
    while (i<n & b[i]==0)
    {
        i++;
    }
    if(i<n){
        if(b[i] == 0) b[i] = 1;
        if(b[i] == 1) b[i] = 0;
    }
}

int main(){
    int *B,n,i;
    B = new int[100];
    std::cout << "Nhap so : ";
    std::cin >> n;
    i = intToBinary(B,n);
    //BinarytoGray(B,i);
    std::cout << "Ma gray :";
    for(int j = 0;j<i;j++){
        std::cout <<  B[j];
    }
}
