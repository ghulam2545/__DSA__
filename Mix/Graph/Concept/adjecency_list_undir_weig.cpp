// Uncomplete......

#include <iostream>
struct Node {
	int data;
	Node *next;
	Node(char& value);
}*head = nullptr, *curr = nullptr;

int main() {
	int v,e; 
	std::cout<<"Enter no of vertex and edges :  ";
	std::cin>>v>>e;
	std::cout<<"Enter vertex data :  ";
	char ver;
	for(int i=0; i<v; i++) {
		std::cin>>ver;
		if(head == nullptr) {
			Node ob(ver);
//			Node(ver);
		}
		else {
			
		}
	}
	
	
	
	return 0;
}

Node::Node(char& value) {
	Node* node = new Node(value);
	node->data = value;
	node->next = nullptr;
	if(head == nullptr) {
		head = node;
	}
	else {
		
	}
}

