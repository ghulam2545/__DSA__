/*
Given a Singly Linked List which has data members sorted in ascending order.
Construct a Binary Search Tree which has same data members
as the given Linked List.
*/
#include <algorithm>
#include <iostream>
#include <vector>
class List {
   private:
   public:
    int data;
    List *link;
    List *getNewNode(const int &value);
    List *insertBack(List *root, const int &value);
    List *sortList(List *root);
    void printList(List *root);
};
class Bbst : public List {
   private:
    int _data;
    Bbst *left;
    Bbst *right;

   public:
    Bbst *_getNewNode(const int &value);
    Bbst *_insert(Bbst *root, const int &value);
    void printBbst(Bbst *root);
    Bbst *mainProb(List *root);
};

int main() {
    List *listInst;
    Bbst *bstInst;
    List *listHead = nullptr;
    Bbst *BbstHead = nullptr;
    listHead = listInst->insertBack(listHead, 10);
    listHead = listInst->insertBack(listHead, 12);
    listHead = listInst->insertBack(listHead, 8);
    listHead = listInst->insertBack(listHead, 3);
    listHead = listInst->insertBack(listHead, 23);
    listHead = listInst->sortList(listHead);

    // printing list data
    listInst->printList(listHead);
    std::cout << "\n\n";
    BbstHead = bstInst->mainProb(listHead);
    // printing bst data
    bstInst->printBbst(BbstHead);
    std::cout << "\n\n";

    return 0;
}
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
    temp->link = getNewNode(value);
    return root;
}
List *List::sortList(List *root) {
    if (root == nullptr) {
        std::cout << "Empty\n";
        return nullptr;
    }
    List *temp = root;
    std::vector<int> storage;
    while (temp != nullptr) {
        storage.push_back(temp->data);
        temp = temp->link;
    }
    sort(storage.begin(), storage.end());
    List *rootToBeReturn = nullptr;
    for (int i = 0; i < storage.size(); i++) {
        rootToBeReturn = insertBack(rootToBeReturn, storage[i]);
    }
    return rootToBeReturn;
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
Bbst *Bbst::_getNewNode(const int &value) {
    Bbst *node = new Bbst();
    node->_data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Bbst *Bbst::_insert(Bbst *root, const int &value) {
    if (root == nullptr) {
        root = _getNewNode(value);
        return root;
    }
    Bbst *temp = root;
    if (value <= temp->_data) {  // insert in left
        temp->left = _insert(temp->left, value);
    } else {  // insert in right
        temp->right = _insert(temp->right, value);
    }
    return root;
}
void Bbst::printBbst(Bbst *root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->_data << " ";
    printBbst(root->left);
    printBbst(root->right);
}
Bbst *Bbst::mainProb(List *root) {
    if (root == nullptr) {
        std::cout << "Empty :\n";
    }
    Bbst *bstHead = nullptr;
    while (root != nullptr) {
        bstHead = _insert(bstHead, root->data);
        root = root->link;
    }
    return bstHead;
}