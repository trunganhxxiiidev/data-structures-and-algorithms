#include<iostream>
using namespace std;
struct node {
	int data;
	node* pNext;
};
struct stack {
	node* pTop;
};
node* initnode(int x) {
	node* p = new node;
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool isEmpty(stack s) {
	if (s.pTop == NULL) {
		return true;
	}
	return false;
}
void push(stack &s, node *p) {
	if (isEmpty(s) == true) {
		s.pTop = p;
	}
	else {
		p->pNext = s.pTop;
		s.pTop = p;
	}
}
bool pop(stack& s,int &x) {
	if (isEmpty(s) == true) {
		return false;
	}
	else {
		node* k = s.pTop;
		 x = s.pTop->data;
		s.pTop = s.pTop->pNext;
		delete k;
	}
}
bool clear(stack& s) {
	if (isEmpty(s) == true) {
		return false;
	}
	else {
		while (s.pTop != NULL) {
			node* k = s.pTop;
			s.pTop = s.pTop->pNext;
			delete k;
		}
		return true;
	}
}
void menu(stack& s) {
	int choice;
	while (true) {
		system("cls");
		cout << "\n1. PUSH";
		cout << "\n2.XUAT DANH SACH STACK";
		cout << "\n0.end";
		cout << "\n\nNhap lua chon: ";
		cin >> choice;
		if (choice == 1) {
			int x;
			cout << "input x=";
			cin >> x;
			node *k=initnode(x);
			push(s, k);
			system("pause");
		}
		else if (choice == 2) {
			cout << "danh sach stack:";
			while (isEmpty(s) == false) {
				int x;
				pop(s, x);
				cout << x << "  ";
			}
			system("pause");
		}
		else if (choice == 3) {
			clear(s);
		}
		else {
			break;
		}
	}
}
int main() {
	stack s;
	s.pTop = NULL;
	menu(s);
	return 1;
}