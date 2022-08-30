#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
struct Queue
{
	Node* front;
	Node* rear;
};
//11.2.Viết thủ tục khởi tạo queue rỗng.
void init(Queue& q)
{
	q.front = q.rear = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho!" << endl;
		return NULL;
	}
	p->info = x;
	p->link = NULL;
	return p;
}
//11.3.Viết thủ tục kiểm tra queue rỗng.
int isEmpty(Queue q)
{
	if (q.front == NULL)
		return 1;
	return 0;
}
//11.4.Viết thủ tục thêm một phần tử vào queue.
void push(Queue& q, Node* p)
{
	if (!q.front) q.front = q.rear = p;
	else {
		q.rear->link = p;
		q.rear = p;
	}
}
//11.5.Viết thủ tục xóa một phần tử trong queue
int pop(Queue& q)
{
	if (q.front)
	{
		Node* p = q.front;
		q.front = q.front->link;
		return p->info;
		delete p;
	}
	return 0;
}
void input(Queue& q)
{
	int n, x;
	cout << "Nhap so phan tu ban muon them vao Queue: ";
	cin >> n;
	while (n--) {
		cout << "\nNhap phan tu trong hang doi: ";
		cin >> x;
		Node* p = createNode(x);
		push(q, p);
	}
}
void output(Queue q)
{
	Node* p = q.front;
	while (p)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
void menu(Queue q) {
	int lc;
	do {
		cout << "============== Menu ==============" << endl
			<< "1. Nhap phan tu cho Queue" << endl
			<< "2. Xuat phan tu trong Queue" << endl
			<< "3. Kiem tra Queue rong" << endl
			<< "4. Xoa 1 phan tu trong Queue" << endl
			<< "5. Them 1 phan tu vao Queue" << endl
			<< "0. Thoat" << endl
			<< "============== End ==============" << endl
			<< "Nhap lua chon cua ban: " << endl;
		cin >> lc;
		system("cls");
		switch (lc) {
		case 0:
			break;
		case 1:
			input(q);
			break;
		case 2:
			cout << "Cac phan tu trong Queue la: ";
			output(q);
			break;
		case 3:
			if (isEmpty(q) == 1)
				cout << "Queue rong!" << endl;
			else cout << "Queue khong rong!" << endl;
			break;
		case 4:
			pop(q);
			cout << "Xoa thanh cong, nhap 2 de xem lai Queue!" << endl;
			break;
		case 5:
		{
			int x;
			cout << "Nhap phan tu ban muon them vao Queue: ";
			cin >> x;
			Node* p = createNode(x);
			push(q, p);
			cout << "Them thanh cong, nhap 2 de xem lai Queue " << endl;
			break;
		}
		default:
			cout << "\nNhap sai, vui long nhap lai!";
		}
	} while (lc);
}
int main()
{
	Queue q;
	init(q);
	int lc;
	menu(q);
	return 0;
}
