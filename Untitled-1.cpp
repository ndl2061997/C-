#include <iostream>

void print_(int &a){
    std::cout << " " << a;
}

int main(){
    int *n;
    n = new int;
    *n = 6;
    print_(*n);
}