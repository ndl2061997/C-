#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

void quickSort(int Data[], int l , int r)
{
	if (l <= r)
	{   
        int temp;
		int key = Data[(l+r)/2];
		int i = l;
		int j = r;
		while (i <= j)
		{
			while (Data[i] < key)
				i++;
			while (Data[j] > key)
				j--;
			if (i <= j)
			{
				temp = Data[i];
                Data[i] = Data[j];
                Data[j] = temp;
				i++;
				j--;
			}
		}	
		if (l < j) quickSort(Data, l, j);
		if (r > i) quickSort(Data, i, r);
	}
}

int main(){
    int * A;
	A = (int*) malloc(10*sizeof(int));
    srand(time(NULL));
    for (int i = 0 ; i<10; i++){
        A[i] = rand()%99+1;
    }
    for(int i = 0 ; i<10;i++){
        cout << A[i] << " ";
    }
	cout << '\n';
    quickSort(A,0,9);
    cout << '\n';
    for(int i = 0 ; i<10;i++){
        cout << A[i] << " ";
    }
    return 0;
}