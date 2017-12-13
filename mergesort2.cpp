#include<iostream>
using namespace std;
void SinhMangNgauNhien(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
}
void XuatMangNgauNhien(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i];
		cout << "    ";
	}
	cout << endl;
}
void Merge(int *a, int *b, int low, int pivot, int hight) {
	int h = low;//Biến chạy h lưu trữ phần tử đầu tiên của mảng
	int i = low;//Biến chạy
	int j = pivot + 1;//Biến chạy
	int k;
    int v = 0;
	while ((i <= pivot) && (j <= hight)) {
		if (a[i] <= a[j]) {
			b[v] = a[i];//lưu phần tử đó vào mảng tạm B
			i++;
            v++;
		}
		else {
			b[v] = a[j];//ngược lại thì lưu phần tử bên phải vào mảng tạm
			j++;
            v++;
		}
	}
    
	if (i > pivot && j <= hight) {  
		for (k = j; k <= hight; k++) {
			b[v] = a[k];
			i++;
            v++;
		}
	}
	else if(j > hight && i <= pivot) {
		for (k = i; k <= pivot; k++) {
			b[v] = a[k];
			i++;
            v++;
		}
	}
    v = 0;
	for (k = low; k <= hight; k++) {
		a[k] = b[v];
        v++;
	}
}
//Hàm sắp xếp MergeSort
void MergeSort(int a[], int b[], int low,int hight) {
	int pivot;
	if (low < hight) {
		pivot = (low + hight) / 2;
		MergeSort(a, b, low, pivot);
		MergeSort(a, b, pivot + 1, hight);
		Merge(a, b, low, pivot, hight);
	}
}
int main() {
	int num;
	int a[] = {12,10,43,23,-78,45,123,56,98,41,90,24};
	num = sizeof(a) / sizeof(int);
	int b[num];
	MergeSort(a, b, 0, num - 1);
	for (int i = 0; i < num; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}
/*int n;
cout << "Nhap vao so luong phan tu cua mang n= ";
cin >> n;
SinhMangNgauNhien(a, n);
XuatMangNgauNhien(a, n);*/