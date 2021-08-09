#include <iostream>
struct Node {
	int data;
	Node* link;
	void addEnd(int& val);
	void addBeg(int& val);
	void deleteBeg();
	void deleteEnd();
	void display();
}*head = NULL, *curr = NULL;

int main() {
	Node a;
	int temp = 0;
	std::cout<<"Insertion of node at end :\n";
	for(int i=3; i<7; i++) {
		temp = i*10;
		a.addEnd(temp);
	}
	a.display();
	std::cout<<"\n\nInsertion of node at begning :\n";
	for(int i=1; i<=2; i++) {
		temp = i*10;
		a.addBeg(temp);
	}
	a.display();
	std::cout<<"\n\nDeletion of node at end :\n";
	a.deleteEnd();
	a.display();
	
	std::cout<<"\n\nDeletion of node at begning :\n";
	a.deleteBeg();
	a.display();
	
	
	return 0;
}

void Node::addEnd(int& val) {
	Node* node = new Node();
	node->data = val;
	node->link = NULL;
	if(head == NULL) {
		head = node;
	}
	else {
		curr = head;
		while(curr->link != NULL) {
			curr = curr->link;
		}	
		curr->link = node;
	}
}
void Node::addBeg(int& val) {
	Node* node = new Node();
	node->data = val;
	node->link = NULL;
	if(head == NULL) {
		head = node;
	}
	else {
		curr = head;
		head = node;
		head->link = curr;
	}
}
void Node::display() {
	curr = head;
	if(head == NULL) {
		std::cout<<"Empty list\n";
	}
	else {
		while(curr != NULL) {
			std::cout<<curr->data<<"---->";
			curr = curr->link;
		}
		std::cout<<"NULL";
	}
}
void Node::deleteBeg() {
	if(head == NULL) {
		std::cout<<"Empty list\n";
	}
	else {
		curr = head->link;
		head = curr;
		
	}
}
void Node::deleteEnd() {
	if(head == NULL) {
		std::cout<<"Empty list\n"; return;
	}
	if(head->link == NULL) {
		delete head;
		head = NULL; 
		return;
	}
	curr = head;
	while(true) {
		if(curr->link->link == NULL) {
			break;
		}
		curr = curr->link;
	}
	delete curr->link;
	curr->link = NULL;
}
