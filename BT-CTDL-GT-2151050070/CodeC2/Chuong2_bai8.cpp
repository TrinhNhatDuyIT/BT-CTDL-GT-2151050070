#include<iostream>
using namespace std;

/* khai báo Node */
struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;

/* khai báo cấu trúc của Stack */
struct stack
{
    NODE* pTop; 
};
typedef struct stack STACK;

/* hàm khởi tạo Stack */
void KhoiTaoStack(STACK& s)
{
    s.pTop = NULL;
}

/* hàm khởi tạo 1 cái node */
NODE* KhoiTaoNode(int x)
{
    NODE* p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhông đủ bộ nhớ để cấp phát !";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

/* hàm kiểm tra Stack rỗng*/
bool IsEmpty(STACK s)
{
    // nếu stack rỗng
    if (s.pTop == NULL)
    {
        return false;
    }
    return true;
}

/* Thêm phần tử vào đầu Stack (top)*/
bool Push(STACK& s, NODE* p)
{
    // node p đang rỗng
    if (p == NULL)
    {
        return false;
    }

    // nếu danh sách rỗng
    if (IsEmpty(s) == false)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}

/* Lấy phần tử đầu danh sách và hủy nó đi */
bool Pop(STACK& s, int& x) // x chính là giá trị cần lấy ra
{
    // nếu danh sách rỗng
    if (IsEmpty(s) == false)
    {
        return false;
    }
    NODE* p = s.pTop;
    s.pTop = s.pTop->pNext;
    x = p->data;
    return true;
}

/* Xem thông tin của node đầu danh sách */
bool Top(STACK s, int& x)
{

    if (IsEmpty(s) == false)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}

/* Hàm đổi cơ số 10 sang các cơ số 2, 8, 16 */
void Chuyen_Co_So(STACK& s, int cosocandoi, int hethapphan)
{
    while (hethapphan != 0)
    {
        int x = hethapphan % cosocandoi;
        NODE* p = KhoiTaoNode(x);
        Push(s, p);
        hethapphan /= cosocandoi;
    }
}

/* xuất danh sách stack */
void XuatStack(STACK& s)
{
    while (IsEmpty(s) == true)
    {
        int x;
        Pop(s, x);
        if (x < 10)
        {
            cout << x;
        }
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
    }
}

int main()
{
    STACK s;
    KhoiTaoStack(s);

    int hethapphan, cosocandoi;
    cout << "\nNhap gia tri thap phan can chuyen: ";
    cin >> hethapphan;
    do {
        cout << "\nNhap co so can chuyen (2, 8, 16):  ";
        cin >> cosocandoi;
    } while (cosocandoi != 2 && cosocandoi != 8 && cosocandoi != 16);

    Chuyen_Co_So(s, cosocandoi, hethapphan);
    cout << "\nKet qua:\n";
    XuatStack(s);
    cout << endl;

}