#include<iostream>
using namespace std;
struct node {
	int data;
	node* pNext;
};
struct queue {
	node* pTop;
};
node* init(int x) {
	node* p = new node;
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool isEmpty(queue q) {
	if (q.pTop == NULL) {
		return true;
	}
	return false;
}
bool push(queue &q,node* p) {
	if (isEmpty(q)==true) {
		q.pTop = p;
	}
	else {
		for (node* k = q.pTop; k != NULL; k = k->pNext) {
			if (k->pNext == NULL) {
				k->pNext = p;
				break;
			}
		}
	}
	return true;
}
bool pop(queue& q, int& x) {
	if (isEmpty(q) == true) {
		return false;
	}
	else {
		node* k = q.pTop;
		x = q.pTop->data;
		q.pTop = q.pTop->pNext;
		delete k;
	}
}
void clear(queue& q) {
	while (q.pTop != NULL) {
		node* k = q.pTop;
		q.pTop = q.pTop->pNext;
		delete k;
	}
}
void menu(queue &q) {
	int lc;
	while (true) {
		system("cls");
		cout << "\n1.push";
		cout << "\n2.print and pop";
		cout << "\n3.clear";
		cout << "\n\nnhap lua chon: ";
		cin >> lc;
		if (lc == 1) {
			int x;
			cout << "nhap x: ";
			cin >> x;
			node* k = init(x);
			push(q, k);
			system("pause");
		}
		else if (lc == 2) {
			cout << "danh sach queue: ";
			while (isEmpty(q) == false) {
				int x;
				pop(q, x);
				cout << x << "  ";
			}
			system("pause");
		}
		else if (lc == 3) {
			clear(q);
		}
		else {
			break;
		}
	}
}
int main() {
	queue q;
	q.pTop = NULL;
	menu(q);
	return 1;
}