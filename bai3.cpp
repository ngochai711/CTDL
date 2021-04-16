#include <iostream>
#include <string>
using namespace std;
#define luongcoban 4.42
struct Staff {
    string MSNV;
    string Name;
    float Hesoluong;
    float Salary = luongcoban * Hesoluong;
};
struct Node {
    Staff data;
    Node *pNext;
};
typedef struct Node NODE;
struct List {
    NODE* pHead;
    NODE* pTail;
};
typedef struct List LIST;

NODE* CreateNode(Staff initData) {
    NODE* p = new NODE;
    if(p == NULL) {
        cout << "Khong du bo nho";
        return NULL;
    }
    p->pNext = NULL;
    p->data = initData;
    return p;
}
void CreateList(List &l) {
    l.pHead = l.pTail = NULL;
}
void AddHead(LIST &l, NODE* p) {
    if(l.pHead == NULL) 
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(LIST &l, NODE *p) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void InputStaff(Staff &staff) {
    
    cout << "MSNV: " ;cin >> staff.MSNV;
    
    cout << "Name: " ;cin >> staff.Name;
    
    cout << "He so luong: " ;cin >> staff.Hesoluong;
    
}
void Input(List &l) {
    CreateList(l);
    int n;
    cout << "So nhan vien can nhap: ";
    cin >> n;
    for(int i = 0; i < n;i++) {
    Staff x;
    InputStaff(x);
    Node *p = CreateNode(x);
    AddTail(l,p);
  }
}
void PrintStaff(Staff &staff) {
    cout << "MSNV: " << staff.MSNV << '\t';
    cout << "Name: " << staff.Name << '\t';
    cout << "He so luong: " << staff.Hesoluong << '\t';
    cout << "Salary: " << staff.Hesoluong * luongcoban << '\t';
}
void PrintList(List &l) {    
    for(NODE *p = l.pHead; p != NULL;p = p->pNext) {
    PrintStaff(p->data);
    cout << endl;
  }
}
void DestroyList(List &l) {
    NODE* p = l.pHead;
    while(l.pHead != NULL) {
        l.pHead = p->pNext;
        delete p;
    }
}
void SwapFloat(float &a, float &b) {
    float tmp = a;
    a = b;
    b = tmp;
}
void SwapString(string &a, string &b) {
    a.swap(b);
}
void Swap(Staff &a, Staff &b) {
    SwapString(a.Name,b.Name);
    SwapString(a.MSNV,b.MSNV);
    SwapFloat(a.Hesoluong,b.Hesoluong);
    SwapFloat(a.Salary,b.Salary);
}
void ShortList1(List &l) {
    for(NODE* pTmp1 = l.pHead; pTmp1 != NULL; pTmp1 = pTmp1->pNext) {
        for(NODE* pTmp2 = pTmp1->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext) {
            if(pTmp1->data.Hesoluong < pTmp2->data.Hesoluong) {
                Swap(pTmp1->data, pTmp2->data);
            }
        }
    }
}
void ShortList2(List &l) {
    for(NODE* pTmp1 = l.pHead; pTmp1 != NULL; pTmp1 = pTmp1->pNext) {
        for(NODE* pTmp2 = pTmp1->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext) {
            if(pTmp1->data.Salary > pTmp2->data.Salary) {
                Swap(pTmp1->data, pTmp2->data);
            }
        }
    }
}
void ListStaffWithSalaryUnder6Milions(List &l) {
    NODE* p = l.pHead;
        while (p != NULL && p->data.Salary < 6)
        {
            cout << "MSNV: " << p->data.MSNV << "\tTen: " << p->data.Name << endl;
            p = p->pNext;
        }    
    }
int RemoveStaff(List &l , string ms) {
    NODE* prev = NULL,*p = l.pHead;
    while(p != NULL && p->data.MSNV.compare(ms) != 0) {
        prev = p;
        p = p->pNext;
    }
    prev->pNext = p->pNext;
    delete p;
    return 1;
}
int main() {
 List l;
 Input(l);
//  PrintList(l);
//  cout << "Sap xep List luong giam dan: " << endl;
//  ShortList1(l);
//  PrintList(l);
//  cout << "Nhan vien co muc luong cao nhat la: " << endl;
//  cout << "MSNV: " << l.pHead->data.MSNV << "\tTen: " << l.pHead->data.Name << endl;
//  ShortList2(l);
//  cout << "Sap xep List luong tang dan : " << endl;
//  PrintList(l);
//  cout << "Tim mot nhan vien co MS bang X. Nhap x: ";
 string x;
//  cin >> x;
 cout << "Xoa nhan vien co MS bang X. Nhap x :";
 cin >> x;
 if(RemoveStaff(l,x)) cout << "===== List sau khi xoa =====" << endl;
 PrintList(l);
 cout << "Danh sach nhan vien co muc luong duoi 6 trieu: " << endl;
 ListStaffWithSalaryUnder6Milions(l);
}
