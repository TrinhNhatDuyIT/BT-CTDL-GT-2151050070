#include <iostream>
#include <stdio.h>
#include<ctime>
#define MAX 5000

//1.1 KHOI TAO CAU TRUC DANH SACH
int a[MAX];
int b[MAX];
int n;
using namespace std;

// 1.2 NHAP DANH SACH
void Input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = "; cin >> a[i];
	}
}

// 1.2 NHAP DANH SACH TU DONG
void Random(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10000 + 1;
	}
}

// 1.3 XUAT DANH SACH
void Output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i + 1 << "] = " << a[i] << "\t";
	}
}
// COPY ARRAY
void CopyArray(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}
// HOAN DOI
void swap(int& a, int& b)
{
	int  c;
	c = a;
	a = b;
	b = c;
}

// 1.4 
void InsertionSort(int a[], int n)
{
	int x, i, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i]; // biến x lưu giá trị a[i]
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

// 1.5
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}

// 1.6
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

// 1.7
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}

// 1.8
void QuickSort(int a[], int l, int r) {
	int x = a[(l + r) / 2];
	int i = l;
	int j = r;
	while (i < j) {
		while (a[i] < x)
		{
			i++;
		}
		while (a[j] > x)
		{
			j--;
		}
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j)
	{
		QuickSort(a, l, j);
	}
	if (i < r)
	{
		QuickSort(a, i, r);
	}
}

// 1.9 HeapSort
void shift(int a[], int i, int n) {
	int j = 2 * i + 1;
	if (j >= n)
	{
		return;
	}
	if (j + 1 < n)
	{
		if (a[j] < a[j + 1])
			j++;
	}
	if (a[i] >= a[j])
	{
		return;
	}
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}

void HeapSort(int a[], int n) {
	int i = (n / 2) - 1;
	while (i >= 0)
	{
		shift(a, i, n);
		i--;
	}
	int r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		r--;
		if (r > 0)
			shift(a, 0, r);
	}
}

int main() {
	int choice, x, i;
	clock_t start;
	double duration;
	system("cls");
	cout << "------MENU------\n";
	cout << "0. Phat dong phan tu mang ngau nhien\n";
	cout << "1. Nhap phan tu mang\n";
	cout << "2. Xuat phan tu mang\n";
	cout << "3. Sap xep theo InsertionSort\n";
	cout << "4. Sap xep theo SelectionSort\n";
	cout << "5. Sap xep theo InterchangeSort\n";
	cout << "6. Sap xep theo BubbleSort\n";
	cout << "7. Sap xep theo QuickSort\n";
	cout << "8. Sap xep theo HeapSort\n";
	cout << "9. Thoat chuong trinh!\n";
	do {
		cout << "Lua chon cua ban: "; cin >> choice;
		switch (choice)
		{
		case 0: {
			cout << "Hay nhap so phan tu trong mang: "; cin >> n;
			Random(a, n);
			Output(a, n); cout << endl;
			break;
		}
		case 1: {
			cout << "Hay nhap so phan tu trong mang: "; cin >> n;
			cout << "Nhap phan tu mang: \n";
			Input(a, n);
			cout << "Mang da nhap xong!\n";
			break;
		}
		case 2: {
			cout << "Mang ban da nhap la: \n";
			Output(a, n); cout << endl;
			break;
		}
		case 3: {
			CopyArray(a, b, n);
			start = clock();
			cout << "Mang xep theo InsertionSort:\n";
			InsertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100) {
				cout << "DS sau khi sap xep voi InsertionSort la " << endl;
				Output(b, n);
			}
			if (duration > 0) {
				cout << "Thoi gian InsertionSort la " << duration * 1000000 << " Milliseconds" << endl;
			}
			cout << "Mang da duoc sap xep!\n";
			break;
		}
		case 4: {
			CopyArray(a, b, n);
			start = clock();
			cout << "Mang xep theo SelectionSort:\n";
			SelectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100) {
				cout << "DS sau khi sap xep voi SelectionSort la " << endl;
				Output(b, n);
			}
			if (duration > 0) {
				cout << "Thoi gian SelectionSort la " << duration * 1000000 << " Milliseconds" << endl;
			}
			cout << "Mang da duoc sap xep!\n";
			break;
		}
		case 5: {
			CopyArray(a, b, n);
			start = clock();
			cout << "Mang xep theo InterchangeSort:\n";
			InterchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100) {
				cout << "DS sau khi sap xep voi InterchangeSort la " << endl;
				Output(b, n);
			}
			if (duration > 0) {
				cout << "Thoi gian InterchangeSort la " << duration * 1000000 << " Milliseconds" << endl;
			}
			cout << "Mang da duoc sap xep!\n";
			break;
		}
		case 6: {
			CopyArray(a, b, n);
			start = clock();
			cout << "Mang xep theo BubbleSort:\n";
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100) {
				cout << "DS sau khi sap xep voi BubbleSort la " << endl;
				Output(b, n);
			}
			if (duration > 0) {
				cout << "Thoi gian BubbleSort la " << duration * 1000000 << " Milliseconds" << endl;
			}
			cout << "Mang da duoc sap xep!\n";
			break;
		}
		case 7: {
			CopyArray(a, b, n);
			start = clock();
			cout << "Mang xep theo QuickSort:\n";
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100) {
				cout << "DS sau khi sap xep voi QuickSort la " << endl;
				Output(b, n);
			}
			if (duration > 0) {
				cout << "Thoi gian QuickSort la " << duration * 1000000 << " Milliseconds" << endl;
			}
			cout << "Mang da duoc sap xep!\n";
			break;
		}
		case 8: {
			CopyArray(a, b, n);
			start = clock();
			cout << "Mang xep theo HeapSort:\n";
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100) {
				cout << "DS sau khi sap xep voi HeapSort la " << endl;
				Output(b, n);
			}
			if (duration > 0) {
				cout << "Thoi gian HeapSort la " << duration * 1000000 << " Milliseconds" << endl;
			}
			cout << "Mang da duoc sap xep!\n";
			break;
		}
		case 9: {
			cout << "Cam on ban da su dung chuong trinh <3! Hen gap lai!\n";
			break;
		}
		default: cout << "Nhap sai cu phap, nhap lai: "; cin >> choice;
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}
