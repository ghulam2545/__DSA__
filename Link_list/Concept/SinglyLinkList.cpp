#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* link;
    Node* getNewNode(int value);
    Node* InsertAtEnd(int value);
    Node* InsertAtBegin(int value);
    Node* InsertAtPerticular(int value);

    Node* DeleteAtEnd();
    Node* DeleteAtBegin();
    Node* DeleteAtPerticular();

    Node* ReverseList_1(Node* head);
    Node* ReverseList_2(Node* head);

    void PrintForward(Node* head);
    void PrintBackward(Node* head);
};
Node *head = nullptr, *curr = nullptr;

int main() {
    Node* aa = new Node();
    aa->InsertAtEnd(10);
    aa->InsertAtEnd(20);
    aa->InsertAtEnd(30);
    aa->InsertAtBegin(99);
    aa->InsertAtBegin(88);
    aa->InsertAtBegin(77);

    aa->PrintForward(head);
    cout << "\n\n";
    aa->PrintForward(aa->ReverseList_1(head));
    cout << "\n\n";
    // aa->PrintForward(aa->ReverseList_2(head));
    //    aa->PrintBackward(head);
    return 0;
}

Node* Node::getNewNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->link = nullptr;
    return node;
}
Node* Node::InsertAtEnd(int value) {
    Node* NewlyNode = getNewNode(value);
    if (head == nullptr) {
        head = NewlyNode;
        return head;
    }
    curr = head;
    while (curr->link != nullptr) {
        curr = curr->link;
    }
    curr->link = NewlyNode;
    return head;
}
Node* Node::InsertAtBegin(int value) {
    Node* NewlyNode = getNewNode(value);
    if (head == nullptr) {
        head = NewlyNode;
        return head;
    }
    curr = head;
    head = NewlyNode;
    head->link = curr;
    return head;
}
Node* Node::InsertAtPerticular(int value) {
    // Node *left = head, *right = nullptr;
    // for(int i=1; i<pos-1; i++) {
    //     left = left->link;
    // }
    // if(left == nullptr) {
    //     left-
    // }
    // else {

    // }
    // right = left->link;
    // left->link = ptr;
    // ptr->link = right;
    // return head;
}
Node* Node::DeleteAtEnd() {}
Node* Node::DeleteAtBegin() {}
Node* Node::ReverseList_1(Node* head) {
    if (head == nullptr) {
        cout << "Empty : ";
        return head;
    } else if (head->link == nullptr) {
        return head;
    } else {
        Node *Prev = nullptr, *Next = head, *Curr = head;
        while (Curr != nullptr) {
            Next = Curr->link;
            Curr->link = Prev;
            Prev = Curr;
            Curr = Next;
        }
        head = Prev;
    }
    return head;
}

// Fix it
Node* Node::ReverseList_2(Node* head) {
    curr = head;
    stack<int> cont;
    while (curr != nullptr) {
        cont.push(curr->data);
        curr = curr->link;
    }
    curr = nullptr;
    while (cont.size()) {
        Node* temp = getNewNode(cont.top());
        if (curr == nullptr) {
            curr = temp;
        } else {
            while (curr->link != nullptr) {
                curr = curr->link;
            }
            curr = temp;
        }
        cont.pop();
    }
    return curr;
}

void Node::PrintForward(Node* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->data << " ";
    PrintForward(head->link);
}
void Node::PrintBackward(Node* head) {
    if (head == nullptr) {
        return;
    }
    PrintBackward(head->link);
    cout << head->data << " ";
}
