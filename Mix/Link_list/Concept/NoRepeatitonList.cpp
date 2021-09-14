#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *link;
};
Node *head = nullptr;
Node *GetNew(int val);
Node *Insert(Node *head, int val);
void Print(Node *head);
Node *NoRepeate(Node *head);
int main() {
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 3);
    Print(head);
    Print(NoRepeate(head));
    return 0;
}
Node *GetNew(int val) {
    Node *node = new Node();
    node->data = val;
    node->link = nullptr;
    return node;
}
Node *Insert(Node *head, int val) {
    if (head == nullptr) {
        head = GetNew(val);
    } else {
        Node *curr = head;
        while (curr->link != nullptr) {
            curr = curr->link;
        }
        curr->link = GetNew(val);
    }
    return head;
}
void Print(Node *head) {
    if (head == nullptr) {
        cout << "Empty : \n";
        return;
    }
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << "  ";
        curr = curr->link;
    }
}
Node *NoRepeate(Node *head) {
    if (head == nullptr || head->link == nullptr) {
        return head;
    }
    int firstData = head->data;
    Node *firstRef = head;
    Node *Next = head->link;
    Node *Curr = head;
    Node *temp;
    while (Curr != nullptr) {
        if (firstData == Next->data) {
            temp = Next;
            Next = Next->link;
            Curr->link = Next;
            free(temp);
            Curr = Next;
            firstData = Curr->data;
            firstRef = Curr;
        } else {
            Curr = Next;
            firstData = Curr->data;
            firstRef = Curr;
        }
    }
    return head;
}