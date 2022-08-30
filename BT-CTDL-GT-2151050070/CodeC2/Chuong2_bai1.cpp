// Bài 1: Chương 2: DANH SÁCH ĐẶC
#include<iostream>
using namespace std;
// #define MAX 100
const int MAX = 100;

// Cau 1.1 - Khai bao cau truc danh sach

int a[MAX];
int n;

// Cau 1.2 - Nhap danh sach
void input(int a[], int& n)
{
	cout << " Nhap vao so luong phan tu cua danh sach : " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a [" << i << "] :";
		cin >> a[i];
	}
}

// Cau 1.3 - Xuat danh sach
void output(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

// Cau 1.4 - Tim phan tu
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
		if (i == n)
			i = -1;
	}
	return i;
}

// Cau 1.5 -  Them cuoi
int insert_last(int a[], int& n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
// Cau 1.6 - Xoa cuoi danh sach
int delete_last(int a[], int& n)
{
	if (n > 0) {
		n--;
		return 1;
	}
	return 0;
}
// Cau 1.7- Xoa tai vi tri i
void xoaphantu(int a[], int& n, int pos)
{
	if (n <= 0)
	{
		return;
	}
	if (pos < 0) {
		pos = 0;
	}
	else if (pos >= n) {
		pos = n - 1;
	}
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	--n;
}
int delete_at_pos(int a[], int& n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = 0; j < n; j++)
		{
			a[j] = a[j + 1];
		}
		--n;
		return 1;
	}
	return 0;
}
// Cau 1.8 - Tim roi xoa
int search_delete(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			delete_at_pos(a, n, i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int a[MAX];
	int n;
	int pos;
	int choice = 0;
	int x, i;
	system("cls");
	cout << " --------BAI TAP---------" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim phan tu co gia tri x trong danh sach " << endl;
	cout << "4. Them phan tu vao cuoi danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6. Xoa phan tu tai vi tri " << endl;
	cout << "7. Tim va xoa phan tu neu co" << endl;
	cout << "8 . Thoat!!" << endl;
	do {
		cout << " Vui long so de thuc hien chuong trinh :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(a, n);
			cout << " Nhap DS thanh cong!!" << endl;
			break;
		case 2:
			cout << " Danh sach da nhap la:";
			output(a, n);
			break;
		case 3:
			cout << " Vui long nhap gia tri can tim:";
			cin >> x;
			i = search(a, n, x);
			if (i == -1)
				cout << " Tim khong thay x =" << x << "trong DS" << endl;
			else
				cout << " Tim thay x = " << x << " trong DS" << endl;
			break;
		case 4:
			cout << "Vui long nhap x cuoi danh sach, x =";
			cin >> x;
			i = insert_last(a, n, x);
			if (i == 0)
				cout << " DS da day, khong the them" << endl;
			else
			{
				cout << " Da them thanh cong x= " << x << " vao cuoi ds " << endl;
				cout << " Danh sach sau them la " << endl;
				output(a, n);
			}
			break;
		case 5:
			i = delete_last(a, n);
			if (i > 0)
			{
				cout << " Xoa phan tu cuoi thanh cong " << endl;
				cout << " Danh sach sau khi xoa la: " << endl;
				output(a, n);
			}
			else
				cout << " Khong co phan tu nao de xoa." << endl;
			break;
		case 6:
			cout << " Nhap vi tri can xoa x=";
			cin >> pos;
			xoaphantu(a, n, pos);
			cout << " Xoa thanh cong " << endl;
			cout << " Danh sach sau khi xoa :";
			output(a, n);
			break;
		case 7:
			cout << " Vui long nhap x can tim de xoa, x= ";
			cin >> x;
			i = search_delete(a, n, x);
			if (i > 0)
			{
				cout << " Xoa phan tu thanh cong " << endl;
				cout << " Danh sach sau khi xoa la: " << endl;
				output(a, n);
			}
			else
				cout << " Khong co phan tu nao de xoa." << endl;
			break;
		case 8:
			cout << " Goodbye.....!!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 8);
	system("pause");
	return 0;
}