#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	Node(int& val);
	void addEnd(int& num);
	void display();
}*head = nullptr, *curr = nullptr;

int main() {
		
	
	return 0;
}
Node::Node(int& val) {
	this->data = val;
	this->left = nullptr;
	this->right = nullptr;
}
void Node::addEnd(int& num) {
	Node *node = new Node(num);
	if(head == nullptr) {
		std::cout<<"Empty list\n";
		return;
	}
	
	
}
