#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* newNode(int data);
    Node* InsertAtTail(int data);
    Node* InsertAtHead(int data);
    void print(Node* head);
    void reversePrint(Node* head);
    void Search(Node* head, int val);
};
Node* head = nullptr;
int main() {
    Node* aa = new Node();
    aa->InsertAtTail(12);
    aa->InsertAtTail(22);
    aa->InsertAtTail(33);
    aa->InsertAtTail(45);
    aa->InsertAtHead(99);
    aa->InsertAtHead(88);
    aa->InsertAtHead(77);
    aa->print(head);
    cout << "\n\n";
    aa->reversePrint(head);
    cout<<"\n";
    aa->Search(head, 45);
    aa->Search(head, 55);

    return 0;
}

Node* Node::newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}
Node* Node::InsertAtTail(int data) {
    Node* newlyNode = newNode(data);
    if (head == nullptr) {
        head = newlyNode;
        return head;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newlyNode;
    newlyNode->prev = curr;
    return head;
}
Node* Node::InsertAtHead(int data) {
    Node* newlyNode = newNode(data);
    if (head == nullptr) {
        head = newlyNode;
        return head;
    }
    head->prev = newlyNode;
    newlyNode->next = head;
    head = newlyNode;
    return head;
}
void Node::print(Node* head) {
    if (head == nullptr) {
        cout << "Empty";
        return;
    }
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}
void Node::reversePrint(Node* head) {
    if (head == nullptr) {
        cout << "Empty";
        return;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->prev;
    }
}
void Node::Search(Node* head, int val) {
    bool ans = false;
    if (head == nullptr) {
        return;
    }
    while (head != nullptr) {
        if (head->data == val) {
            ans = true;
        	break;
		}
        head = head->next;
    }
    ans == true ? cout << "Founded \n" : cout << "Not Founded \n";
}
