#include <iostream>
#include <ctime>
#include <stack>
struct Node {
	int data;
	Node *next;
	Node(int& val);
	void addNode(int& num);
	void display();
	void reverseList();
}*head = nullptr, *curr = nullptr;
int main() {
	int tt = 8;
	Node aa(tt);
	srand(time(0));
	int num = 0;
	while(tt--) {
		num = rand() % 100;
		aa.addNode(num);
	}
	aa.display();
	aa.reverseList();
	std::cout<<"\n\n";
	aa.display();
	return 0;
}
Node::Node(int& val) {
	this->data = val;
	this->next = nullptr;
}
void Node::addNode(int& num) {
	Node *node = new Node(num);
	if(head == nullptr) {
		head = node;
	}
	else {
		curr = head;
		while(curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = node;
	}
}
void Node::display() {
	if(head == nullptr) {
		std::cout<<"Empty list"; return;	
	}
	curr = head;
	while(curr != nullptr) {
		std::cout<<curr->data<<"---->";
		curr = curr->next;
	}
	std::cout<<"NULL";
}
void Node::reverseList() {
	int num = 0;
	Node rnode(num);
	std::stack<int> ss;
	if(head == nullptr) {
		std::cout<<"Empty list"; return;	
	}
	curr = head;
	while(curr != nullptr) {
		ss.push(curr->data);
		curr = curr->next;
	}
	head = nullptr;
	while(ss.size() != 0) {
		rnode.addNode(ss.top());
		ss.pop();
	}
	
}
