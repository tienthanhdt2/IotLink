﻿#include<iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
	int data;
	shared_ptr <Node> pnext;
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

class List
{
private:
	shared_ptr <Node> phead;
	shared_ptr <Node> ptail;
public:
	List();
	~List();
	//Cac method
	void addElement(int);
	void insertElement(int, int);
	void deleteElement(int);
	void printElement();
	int searchElement(int);
};

List::List()
{
	phead = NULL;
	ptail = NULL;
}

//Thêm phần tử x vào cuối  dslk
void List::addElement(int x)
{
	//Tạo mới 1 node có data bằng x
	shared_ptr <Node> p = make_shared <Node> (x);
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
void List::insertElement(int x, int index)
{
	//DSLK có index nằm ở đầu
	if (index == 0) {
		shared_ptr<Node> temp = make_shared<Node>(data);
		if (phead == nullptr)
			phead = ptail = temp;
		else {
			temp->pnext = phead;
			phead = temp;
		}
	}
	else {
		int previous = 0;
		for (shared_ptr<Node> p = phead; p != nullptr; p = p->pnext) {
			if (previous == index - 1) {
				shared_ptr<Node> temp = make_shared<Node>(data);
				temp->pnext = p->pnext;
				p->pnext = temp;
				if (temp->pnext == nullptr) ptail = temp;
				break;
			}
			previous++;
		}
	}
}
//Xóa phần tử khỏi danh sách ở vị trí index
void List::deleteElement(int index)
{
	//DSLK 1 phần tử
	if (head != nullptr) {
		if (index == 0) head = head->next;
		else {
			int before = 0;
			for (shared_ptr<Node> p = head; p->next != nullptr; p = p->next) {
				if (before == index - 1) {
					p->next = p->next->next;
					if (p->next == nullptr) tail = p;
					break;
				}
				before++;
			}
		}
	}
}
//Tìm kiếm phần tử có data=x
int List::searchElement(int x)
{
	int index = 0;
	for (shared_ptr<Node> p = phead; p != nullptr; p = p->pnext) {
		if (p->data == x) return index;
		index++;
	}
	return -1;
}
//In ra danh sách liên kết
void List::printElement()
{
	int index = 0;
	for (shared_ptr<Node> p = phead; p != nullptr; p = p->pnext) {
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