
#include <iostream>
using namespace std;
//Khai boa cau truc 1 node
struct Node {
  int data;
  struct Node* pNext;
};
typedef struct Node NODE;
//DSLK don duoc quan ly boi 2 con tro
struct List {
  NODE* pHead;
  Node* pTail;
};
typedef struct List LIST;
//khoi tao DSLK
void CreateList(List &l) {
  l.pHead = NULL;
  l.pTail = NULL;
}
//khoi tao node head
// struct Node* head;
NODE *CreatNode(int value){
  //cap phat vung nho cho NODE tmp;
  Node *tmp = new Node;
  //khong du bo nho
  if(tmp == NULL) {
    cout << "Khong du bo nho de cap phat!";
    //tro con tro ve 0
    return NULL;
  }
  tmp->pNext = NULL;
  tmp->data = value;
  return tmp;
}
//Them node vao dau danh sach
void AddHead(List &l, NODE *p) {
  //DSLK rong 
  if(l.pHead == NULL) {
    l.pHead = l.pTail = p;
  } 
  else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}
//Them node vao cuoi danh sach 
void AddTail(List &l, Node *p) {
  if (l.pHead==NULL) {
    l.pHead = l.pTail = p;
  }
  else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}
void Input(List &l) {
  CreateList(l);
  int n;
  cout << "Nhap vao so Node can tao: ";
  cin >> n;
  for(int i = 0; i < n;i++) {
    int x;
    cout << "Nhap data Node " << i+1  << ':';
    cin >> x;
    Node *p = CreatNode(x);
    AddTail(l,p);
  }
}
void Output(List &l)
 {  
  for(Node *p = l.pHead; p != NULL;p = p->pNext) {
    cout << p->data << " ";
  }
 }
int Length(NODE* head) {
  int length = 0;
  for(NODE* p = head; p != NULL; p = p->pNext) length++;
  return length;
}
int Search(List l, int x)
{
  int count = 1;
  Node *p;
  p = l.pHead;
  int i = 0;
  while((p!= NULL)&&(p->data != x)) {
  p = p->pNext;
  i++;
  }
  if(i != Length(l.pHead)) return i+1;
  return -1;
}
int RemoveHead(List &l, int &x) {
  if(l.pHead != NULL) {
  Node *p = l.pHead;
  //Luu gia tri cua node bi huy lại de su dung
  x = p->data;
  l.pHead = p->pNext;
  delete p;
  }
  if(l.pHead == NULL) {
    l.pTail = NULL;
    return 1;
  }
  else return 0;
}
int RemoveAfterQ(List& l, Node* q, int& x)
{
	Node* p;
	if (q != NULL)
	{
		p = q->pNext; //p là nút cần xoá
		if (p != NULL) // q không phài là nút cuối
		{
			if (p == l.pTail) //nút cần xoá là nút cuối cùng 
				l.pTail = q;// cập nhật lạ pTail
			q->pNext = p->pNext; x = p->data;
			delete p;
		}
		return 1;
	}
	else
		return 0;
}
// int Get(NODE head, int index)
// int RemoveAfterQ(List &l,Node *q, int &x)
// { Node *p;
// if(q!=NULL)
// { p=q->pNext; //p là nút cần xoá
// if(p!=NULL) // q không phài là nút cuối
// { if(p==l.pTail) //nút cần xoá là nút cuối cùng
// l.pTail=q;// cập nhật lạ pTail
// q->pNext=p->pNext; x=p->Info;
// delete p;
// }
// return 1;
// }
// else
// return 0;
// }
// int RemoveX(List &l, int x)
//   { 
//   Node *p,*q = NULL; p=l.Head;
//   while((p!=NULL)&&(p->Info!=x)) //tìm
//   { q=p;
//   p=p->Next;
//   }
//   if(p==NULL) //không tìm thấy phần tử có khoá bằng x
//   return 0;
//   if(q!=NULL)//tìm thấy phần tử có khoá bằng x
//   DeleteAfterQ(l,q,x);
//   else //phần tử cần xoá nằm đầu List
//   RemoveHead(l,x);
//   return 1;
// }

// void RemoveNode(List l, int x) {

// }
void InsertAfterP(LIST& l, NODE* m)
{
	Node* p;
	p = l.pHead;
	if (p != NULL)
	{
		m->pNext = p->pNext;
		p->pNext = m;
		if (l.pTail == p)
			l.pTail = m;
	}
	else
	{
		AddHead(l, m);
	}
}
int RemoveX(LIST& l, int x)
{
	Node* p, * q = NULL; p = l.pHead;
	while (p != NULL && p->data != x)
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL) //không tìm thấy phần tử có khoá bằng x
		return 0;
	if (q != NULL)//tìm thấy phần tử có khoá bằng x
		RemoveAfterQ(l, q, x);
	else //phần tử cần xoá nằm đầu List
		RemoveHead(l, x);
	return 1;
}
void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void ShortList(List &l) {
    for(NODE* pTmp1 = l.pHead; pTmp1 != NULL; pTmp1 = pTmp1->pNext) {
        for(NODE* pTmp2 = pTmp1->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext) {
            if(pTmp1->data > pTmp2->data) {
                Swap(pTmp1->data, pTmp2->data);
            }
        }
    }
}
int main() {  
  int data;
  List l;
  Input(l);
  //1.Liet ke tat ca thanh phan du lieu cua 1 nut
  cout << "DSLK: ";
  Output(l); cout << endl;
  //2.Tim phan tu co tu khoa bang x]
  cout <<"Tim phan tu co khoa bang x"<< endl;
  int x;
  cin >> x;
  if(Search(l, x) != -1) cout << "Node thu " << Search(l, x) << " co gia tri bang x" << endl;
  else cout << "Khong co node nao co gia tri bang x" << endl;
  //3.Xoa 1 phan tu dau
  cout << "Xoa 1 phan tu dau: " << endl;
  if(RemoveHead(l, data)) cout << "Sau khi xoa , DSLK rong" << endl;
  else {
  cout << "Danh sach LK sau khi xoa NODE dau: "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ;
  Output(l); cout << endl;
  }
  cout << "Data cua node vua xoa la: " << data;
  //4.Xoa 1 phan tu co tu khoa bang x
  cout << "\nNhap gia tri Node can xoa: ";
	cin >> x;
	RemoveX(l, x);
	cout << "List sau khi xoa: " << endl;
	Output(l);
  //5.Sap xep tang dan theo thanh phan du lieu
  cout << "\nSap xep tang dan: ";
	ShortList(l);
  Output(l);
  //6.Chen 1 phan tu vao DSLK, sao cho sau khi chene DSLK van tang theo thanh phan du lieu
  cout << "\nNhap data cho Node can chen: ";
	cin >> x;
	Node* m = CreatNode(x);
	InsertAfterP(l, m);
	cout << endl;
  cout << "DSLK: " << endl;
	Output(l);
	return 0;
}
