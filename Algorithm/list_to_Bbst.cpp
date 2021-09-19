/*
Given a Singly Linked List which has data members sorted in ascending order.
Construct a Balanced Binary Search Tree which has same data members
as the given Linked List.
*/
#include <iostream>
#include <vector>
class List {
   private:
    int data;
    List *link;

   public:
    List *getNewNode(const int &value);
    List *insertBack(List *root, const int &value);
    List *sortList(List *root);
    void printList(List *root);
};

int main() { return 0; }
List *List::getNewNode(const int &value) {
    List *node = new List();
    node->data = value;
    node->link = nullptr;
    return node;
}
List *List::insertBack(List *root, const int &value) {
    if (root == nullptr) {
        root = getNewNode(value);
        return root;
    }
    List *temp = root;
    while (temp->link != nullptr) {
        temp = temp->link;
    }
    temp = getNewNode(value);
    return root;
}
List *List::sortList(List *root) {
    if (root == nullptr) {
        std::cout << "Empty\n";
        return nullptr;
    }
    List *rootToBeReturn = root;
    List *temp = root;
    std::vector<int> storage;
    while (temp != nullptr) {
        storage.push_back(temp->data);
        temp = temp->link;
    }
    // some stuff here...
}
void List::printList(List *root) {
    if (root == nullptr) {
        std::cout << "Empty\n";
        return;
    }
    while (root != nullptr) {
        std::cout << root->data << "  ";
        root = root->link;
    }
}