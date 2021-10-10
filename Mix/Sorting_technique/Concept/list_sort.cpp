// diffculty level : hard

#include <ctime>
#include <iostream>
using namespace std;
struct List {
    int data;
    List* link;
    List* getNewNode(const int& value);
    List* insert(List* head, const int& value);
    void print(List* head);
    void sort();
    List* merge_list(List* h1, List* h2);
    List* mergeSort(List* head);
    List* middle(List* head);
};
int main() {
    List ll;
    List* head = nullptr;
    srand(time(0));
    for (int i = 0; i < 9; ++i) {
        head = ll.insert(head, rand() % 100);
    }
    ll.print(head);
    cout << "\n\n";

    List* ans = ll.mergeSort(head);
    ll.print(ans);
    return 0;
}
List* List::getNewNode(const int& value) {
    List* node = new List();
    node->data = value;
    node->link = nullptr;
    return node;
}
List* List::insert(List* head, const int& value) {
    if (head == nullptr) {
        head = getNewNode(value);
    } else {
        List* temp = head;
        while (temp->link != nullptr) {
            temp = temp->link;
        }
        temp->link = getNewNode(value);
    }
    return head;
}
void List::print(List* head) {
    if (head == nullptr) return;
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->link;
    }
}
List* List::merge_list(List* h1, List* h2) {
    List* head = nullptr;
    List* tail = nullptr;
    if (h1->data <= h2->data) {
        head = h1;
        h1 = h1->link;
    } else {
        head = h2;
        h2 = h2->link;
    }
    tail = head;
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data <= h2->data) {
            tail->link = h1;
            h1 = h1->link;
        } else {
            tail->link = h2;
            h2 = h2->link;
        }
        tail = tail->link;
    }
    if (h1 != nullptr) {
        tail->link = h1;
    } else {
        tail->link = h2;
    }
    return head;
}
List* List::middle(List* head) {
    List* mid = head;
    List* tail = head->link;

    while (mid->link != nullptr && (tail != nullptr && tail->link != nullptr)) {
        mid = mid->link;
        tail = tail->link->link;
    }
    return mid;
}
List* List::mergeSort(List* head) {
    if (head == nullptr || head->link == nullptr) {
        return head;
    }
    List* mid = new List();
    mid = middle(head);
    List* head2 = mid->link;
    mid->link = NULL;
    List* newHead = merge_list(mergeSort(head), mergeSort(head2));
    return newHead;
}