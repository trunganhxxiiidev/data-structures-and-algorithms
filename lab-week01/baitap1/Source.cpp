#include<iostream>
using namespace std;
#include<cstdlib>
#include<time.h>
struct node {
	int data;
	node* pNext;
};
struct list {
	node* pHead;
};
node* create_node(int data) {
	node* p = new node;
	if (p == NULL) {
		return NULL;
	}
	p->data = data;
	p->pNext = NULL;
	return p;
}
list* create_list() {
	list* l = new list;
	if (l != NULL) {
		l->pHead = NULL;
	}
	return l;
}
void add_node(list*&l,int data) {
	node* p = create_node(data);
	if (p == NULL) {
		return;
	}
	if (l->pHead == NULL) {
		l->pHead = p;
	}
	else {
		for (node* k = l->pHead; k != NULL; k = k->pNext) {
			if (k->pNext == NULL) {
				k->pNext = p;
				break;
			}
		}
	}
}
int random(int min, int max) {
	return min + rand() % (max - min + 1);
}
list* generate_list(const int& slmin,const int& slmax,const int& gtmin,const int &gtmax) {
	list* l = create_list();
	if (l == NULL) {
		return NULL;
	}
	int n = random(slmin, slmax);
	for (int i = 0; i < n; i++) {
		int x = random(gtmin, gtmax);
		add_node(l, x);
	}
	return l;
}
void printf(list* l) {
	for (node* k = l->pHead; k != NULL; k = k->pNext) {
		cout << k->data << "  ";
	}
}
void split_list(list* l, list*& l1, list*& l2,int x) {
	for (node* k = l->pHead; k != NULL; k = k->pNext) {
		if (k->data < x) {
			add_node(l1, k->data);
		}
		else {
			add_node(l2, k->data);
		}
	}
}
int main() {
	//srand((int)time(0));
	srand(time(NULL));
	list* l = generate_list(10, 100, -50, 50);
	list* l1 = create_list();
	list* l2 = create_list();
	cout << "PRINT TRADITIONAL LIST:\n";
	printf(l);
	int x;
	cout << "\n\n\tNHAP X=";
	cin >> x;
	cout << "\n\n\t\tAFTER SPLIT\n";
	split_list(l, l1, l2, x);
	cout << "LIST 1: ";
	printf(l1);
	cout << "\nLIST 2: ";
	printf(l2);
	return 1;
}