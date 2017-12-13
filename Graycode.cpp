#include <iostream>
#include <stdlib.h>
#include <conio.h>

int intToBinary(int *b,int n){
    int i;
    int C[100];
    i = 0;
    while ((n/2)>0){
        C[i] = n%2;
        i++;
        n = (int)(n/2);
    }
    C[i] = n%2;
    i++;
    for(int j = 0;j<i;j++){
        b[j] = C[i-j-1];
    }
}

void BinarytoGray(int *b, int n){
    int i = n-1;
    while (i>0)
    {
        if(b[i-1] == 1 ){
            if(b[i] == 0){
                b[i] = 1;
                i--;
            }else{
                b[i]=0;
                i--;
            }
        } else i--;
    }
}

int main(){
    int *B,n,i;
    B = new int[100];
    std::cout << "Nhap so : ";
    std::cin >> n;
    i = intToBinary(B,n);
    std::cout << "Binary : ";
    for(int j = 0;j<i;j++){
        std::cout <<  B[j];
    }
    std::cout << '\n' <<"Gray :   ";
    BinarytoGray(B,i);
    for(int j = 0;j<i;j++){
        std::cout <<  B[j];
    }
    getch();
    return 0;
}
