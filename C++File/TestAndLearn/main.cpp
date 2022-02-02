#include <iostream>
using namespace std;
struct Node {
	int data;
};

void ChangeNode1(Node*& pnode) {
	pnode = new Node;
	pnode->data = 5;
}

void ChangeNode2(Node *pnode) {
	pnode = new Node;
	pnode->data = 5;
}


void Test1() {
	Node *node = new Node;
	node->data = 10;
	ChangeNode1(node);
	cout << "point using" << node->data << endl;
}

void Test2() {
	Node *node = new Node;
	node->data = 10;
	ChangeNode2(node);
	cout << "point" << node->data << endl;
}

int main() {
	Test1();
	Test2();
	return 0;
}
