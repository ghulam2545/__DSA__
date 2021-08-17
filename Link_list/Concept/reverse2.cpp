// Isssue
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* link;
    Node(int val) {
        this->data = val;
        this->link = nullptr;
    }
    Node* f(Node* head) {
        Node* pata = head;
        Node* node1 = new Node(10);
        Node* node2 = new Node(20);
        Node* node3 = new Node(30);
        Node* node4 = new Node(40);
        head = node1;
        head->link = node2;
        head->link->link = node3;
        head->link->link->link = node4;
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->link;
        }
        return pata;
    }
    void rev(Node* head) {
        Node* tt = head;
        if (0) {
        } else {
            Node *Prev, *Curr, *Next;
            Prev = head;
            Curr = head->link;
            Next = head->link;
            Prev->link = nullptr;
            while (Next != nullptr) {
                Next = Next->link;
                Curr->link = Prev;
                Prev = Curr;
            }
            Curr = Next;
            Curr->link = Prev;
            Next = tt;
        }
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->link;
        }
    }
};
int main() {
    Node* head;
    cout << "head   " << head << "  ";
    Node aa(22);
    Node* top = aa.f(head);
    cout << "top  " << top << "  ";
    cout << "Rev  "
         << "\n";
    aa.rev(head);
    return 0;
}
