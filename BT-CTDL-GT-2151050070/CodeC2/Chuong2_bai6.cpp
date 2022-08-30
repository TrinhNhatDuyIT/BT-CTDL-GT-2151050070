#include <iostream>
#include <string>
#define MAX 100

using namespace std;

struct Stack
{
	int a[MAX];
	int top;
};

void init(Stack& s)
{
	s.top = -1;
}

bool isFull(Stack s)
{
	return s.top == MAX;
}

bool isEmpty(Stack s)
{
	return s.top == -1;
}

void push(Stack& s, int x)
{
	if (!isFull(s))
		s.a[++s.top] = x;
}

int pop(Stack& s)
{
	if (!isEmpty(s))
		return s.a[s.top--];

	return -1;
}

Stack convertToRadix(int n, int radix = 2)
{
	Stack s;
	init(s);

	while (n != 0)
	{
		push(s, n % radix);
		n /= radix;
	}

	return s;
}

void output(Stack s)
{
	string t[] = { "A", "B", "C", "D", "E", "F" };
	while (!isEmpty(s))
	{
		int x = pop(s);
		if (x < 10)
			cout << x;
		else
			cout << t[x - 10];
	}

	cout << endl;
}

int main()
{
	int n;
	cout << " Nhap 1 so thap phan :";
	cin >> n;
	Stack r = convertToRadix(n, 2);
	output(r);

	system("pause");

	return 0;
}
