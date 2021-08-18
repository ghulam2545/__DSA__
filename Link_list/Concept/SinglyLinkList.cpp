#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* link;
    Node* getNewNode(int value);
    Node* InsertAtEnd(int value);
    Node* InsertAtBegin(int value);
    Node* InsertAtPerticular(int value);

    Node* DeleteAtEnd(Node* head);
    Node* DeleteAtBegin(Node* head);
    Node* DeleteAtPerticular(Node* head);

    Node* ReverseList_InPlace(Node* head);
    Node* ReverseList_UsingStack(Node* head);

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
//    cout << "\n\n";
//    aa->PrintForward(aa->ReverseList_UsingStack(head));
    cout << "\n\n";

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
Node* Node::DeleteAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "Empty : ";
    } else if (head->link == nullptr) {
        Node* temp = head;
        head = nullptr;
        free(temp);
    } else {
        Node* temp = head;
        while (temp->link->link != nullptr) {
            temp = temp->link;
        }
        Node* toBeDelete = temp->link;
        temp = nullptr;
        free(toBeDelete);
    }
    return head;
}
Node* Node::DeleteAtBegin(Node* head) {}
Node* Node::ReverseList_InPlace(Node* head) {
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
Node* Node::ReverseList_UsingStack(Node* head) {
    stack<int> cont;
    while (head != nullptr) {
        cont.push(head->data);
        head = head->link;
    }
    curr = nullptr;
    while (!cont.empty()) {
        Node* temp = getNewNode(cont.top());
        if (curr == nullptr) {
            curr = temp;
        } else {
            Node* tt = curr;
            while (tt->link != nullptr) {
                tt = tt->link;
            }
            tt->link = temp;
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
