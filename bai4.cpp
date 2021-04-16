
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct Goods {
    string Name;
    float Price;
    int Sl;
};
struct Node {
    Goods data;
    Node *pNext;
};
typedef struct Node NODE;
struct List {
    NODE* pHead;
    NODE* pTail;
};
typedef struct List LIST;

NODE* CreateNode(Goods initData) {
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
void InputGoods(Goods &goods) {
    
    cout << "Name: " ;cin >> goods.Name;
    
    cout << "Price: " ;cin >> goods.Price;
    
    cout << "So luong: " ;cin >> goods.Sl;
    
}
void Input(List &l) {
    int n;
    cout << "So hang hoa can nhap: ";
    cin >> n;
    for(int i = 0; i < n;i++) {
    Goods x;
    InputGoods(x);
    Node *p = CreateNode(x);
    AddTail(l,p);
  }
}
void PrintGoods(Goods &g) {
    cout << "Name: " << g.Name << '\t';
    cout << "Price: " << g.Price << '\t';
    cout << "So luong: " << g.Sl << '\t';
}
void PrintList(List &l) {    
    for(NODE *p = l.pHead; p != NULL;p = p->pNext) {
    PrintGoods(p->data);
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
void SwapInt(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void SwapString(string &a, string &b) {
    a.swap(b);
}
void Swap(Goods &a, Goods &b) {
    SwapString(a.Name,b.Name);
    SwapFloat(a.Price,b.Price);
    SwapInt(a.Sl,b.Sl);
}
void ShortList(List &l) {
    for(NODE* pTmp1 = l.pHead; pTmp1 != NULL; pTmp1 = pTmp1->pNext) {
        for(NODE* pTmp2 = pTmp1->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext) {
            if(pTmp1->data.Price > pTmp2->data.Price) {
                Swap(pTmp1->data, pTmp2->data);
            }
        }
    }
}
void Compare(List &l) {
    int x, y;
    cout << "Nhap 2 so nguyen can so sanh: " ;
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
    for(NODE* pTmp1 = l.pHead; pTmp1 != NULL; pTmp1 = pTmp1->pNext) {
        if(pTmp1->data.Sl > x && pTmp1->data.Sl < y) {
            PrintGoods(pTmp1->data);
        }
    }
}
int main() {
 List l;
 CreateList(l);
 Input(l);
 PrintList(l);
 cout << "Sap xep mat hang theo gia tang dan: " << endl;
 ShortList(l);
 PrintList(l);
 Compare(l);
}
