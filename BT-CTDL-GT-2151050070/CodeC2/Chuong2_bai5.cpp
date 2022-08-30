#include<iostream>
using namespace std;

#define Max 100
int a[Max];
int sp;

void init(int a[], int& sp)
{
	sp = -1;
}

int isEmty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

int isFull(int a[], int sp)
{
	if (sp == Max - 1)
		return 1;
	return 0;
}

int Push(int a[], int& sp, int x)
{
	if (sp < Max - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int Pop(int a[], int& sp, int x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

void process_stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << " <--";
	cout << endl;
}
int main()
{
	int a[Max];
	int choice, sp, x, i;
	system("cls");
	cout << "=======Bai tap 5 chuong 2 - STACK voi DS dac ======" << endl;
	cout << "1. Kh?i t?o stack r?ng\n";
	cout << "2.Kiem tra stack rong\n";
	cout << "3.Kiem tra stack day\n";
	cout << "4.Them 1 phan tu vao stack\n";
	cout << "5. Lay 1 phan tu trong stack\n";
	cout << "6.XUAT STACK\n";
	cout << "7.THOAT\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao stack thanh cong\n";
			break;
		case 2:
			cout << "Nhap phan tu can them x= ";
			cin >> x;
			i = Push(a, sp, x);
			if (i == 1)
			{
				cout << "Them x= " << x << " vao Stack Thanh cong1" << endl;
				cout << "Stack sau khi can them lai " << endl;
				process_stack(a, sp);
			}
			break;
		case 3:
			i = Pop(a, sp, x);
			if (i == 1)
			{
				cout << "Lay ra phan tu stack thanh cong, gia tri lay ra la: x = " << x << endl;
				cout << "Stack sau khi lay ra 1 phan tu la: " << endl;
				process_stack(a, sp);
			}
			else
				cout << "Lay ra khong thanh cong\n";
			break;
		case 4:
			i = isEmty(a, sp);
			if (i == 1)
				cout << "Stack dang rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 5:
			i = isFull(a, sp);
			if (i == 1)
				cout << "Stack dang day\n";
			else
				cout << "Stack khong day\n";
			break;
		case 6:
			process_stack(a, sp);
			break;
		case 7:
			cout << "GOODBYE\n";
			break;
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}