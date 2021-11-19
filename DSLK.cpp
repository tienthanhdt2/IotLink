#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* pnext;
	Node();
	Node(int);
	~Node();
};

Node::Node()
{
	data = 0;
	pnext = NULL;
}

Node::Node(int x) // Value giá trị node truyền vào
{
	data = x;
	pnext = NULL;
}

Node::~Node()
{

}
class List
{
private:
	Node* phead;
	Node* ptail;
public:
	List();
	~List();
	//Cac method
	void addElement(int);
	void insertElement(int,int);
	void deleteElement(int);
	void printElement();
	int searchElement(int);
}; 

List::List()
{
	phead = NULL;
	ptail = NULL;
}

List::~List()
{
	Node* p = phead;
	while (p!=NULL)
	{
		Node* k = p;
		p = p->pnext;
		delete k;
	}
}
//Thêm phần tử x vào cuối  dslk
void List::addElement(int x) 
{
	//Tạo mới 1 node có data bằng x
	Node* p = new Node(x);
	if (phead == NULL)
	{
		phead = ptail = p;
	}
	else
	{
		ptail->pnext = p;
		ptail = p;
	}
	
}
//Chèn phần tử  có data=x vào vị trí:index
void List::insertElement(int x,int index)
{
	//DSLK có index nằm ở đầu
	if (index==0)
	{
		Node* p = new Node(x);
		//DSLK rỗng
		if (phead==NULL)
		{
			phead = ptail = p;
		}
		else
		{
			p->pnext = phead;
			phead = p;
		}
	}
	else
	{
		//Tạo mới node có data bằng x
		Node* p = new Node(x);
		for (Node* k = phead; k != NULL; k = k->pnext)
		{
			p->pnext = k->pnext; //Liên kết p với pt sau k
			k->pnext = p; //liên kết k vơi p

			if (k == ptail) //K nằm ở vị trí cuối 
			{
				ptail = p; // cập nhật lại ptail
				break;
			}
		}
	}
}
//Xóa phần tử khỏi danh sách ở vị trí index
void List::deleteElement(int index) 
{
	//DSLK 1 phần tử
	if (phead==ptail && phead!=NULL)
	{
		delete[] phead;
		phead = ptail = NULL;
	}
	else if(phead!=ptail)
	{
		//Nếu xóa đầu
		if (index == 0)
		{
			//Tao 1 node để giữ địa chỉ node phead
			Node* p = phead;
			phead = phead->pnext;
			delete p;
		}
		else
		{
			//
			int before=0;
			for (Node* p = phead; p != NULL; p = p->pnext)
			{
				if (before ==index-1)
				{
					Node* k = p->pnext;
					p->pnext = k->pnext;
					//Vị trí cuối cập nhật lại ptail
					if (k->pnext==NULL)
					{
						ptail = p;
						break;
					}
					delete k;
				}
			}
			before++;
		}
	}
}
//Tìm kiếm phần tử có data=x
int List::searchElement(int x)
{
	int index = 0;
	for (Node* p = phead; p != nullptr; p = p->pnext) {
		if (p->data == x) return index;
		index++;
	}
	return -1;
}
//In ra danh sách liên kết
void List::printElement()
{
	int index = 0;
	for (Node* p = phead; p != nullptr; p = p->pnext) {
		cout << "Phan tu " << index << ": " << p->data << endl;
		index++;
	}
}

int main() {
	{
		List list;
		bool kt = true;
		while (kt) {
			int choice;
			system("cls");
			cout << "1. ADD " << endl;
			cout << "2. Insert" << endl;
			cout << "3. Delete" << endl;
			cout << "4. Print" << endl;
			cout << "5. Search " << endl;
			cout << "0. Quit" << endl;
			cout << "Nhap lua chon: ";
			cin >> choice;
			switch (choice)
			{
			case 1: {
				int nums;
				cout << "Nhap so phan tu can them: "; cin >> nums;
				for (int i = 0; i < nums; i++) {
					int x;
					cout << "Nhap phan tu thu " << i << ": "; 
					cin >> x;
					list.addElement(x);
				}
				break;
			}
			case 2: {
				int index, data;
				cout << "Nhap vi tri: "; cin >> index;
				cout << "Nhap gia tri: "; cin >> data;
				list.insertElement(data, index);
				break;
			}
			case 3: {
				int index;
				cout << "Nhap vi tri can xoa: "; cin >> index;
				list.deleteElement(index);
				break;
			}
			case 4: {
				list.printElement();
				system("pause");
				break;
			}
			case 5: {
				cout << "Nhap gia tri can tim: ";
				int data; cin >> data;
				if (list.searchElement(data) == -1) cout << "Khong tim thay";
				else cout << "vi tri: " << list.searchElement(data);
				cout << endl;
				system("pause");
				break;
			}
			case 0: {
				kt = false;
				break;
			}
			}
		}
	}
}