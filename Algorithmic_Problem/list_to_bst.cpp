// From sorted list to bst  NOT WORKING
#include <bits/stdc++.h>
using namespace std;
struct List {
    int data;
    List *link;
    List(const int data);
    List *insertNode(List *root, const int data);
    void printList(List *root);
};

struct Bst {
    int data;
    Bst *left;
    Bst *right;
    Bst(const int data);
    Bst *insertNode(Bst *root, const int data);
    void inorder(Bst *root);
};
Bst *bst = nullptr;
Bst *problem(List *root);

int main() {
    List *first = nullptr;
    first = first->insertNode(first, 10);
    first = first->insertNode(first, 20);
    first = first->insertNode(first, 30);
    first = first->insertNode(first, 40);
    first = first->insertNode(first, 50);
    first = first->insertNode(first, 60);
    first = first->insertNode(first, 70);
    first = first->insertNode(first, 80);
    first = first->insertNode(first, 90);
    first->printList(first);
    cout << "\n\n";
    Bst *ans = problem(first);
    ans->inorder(ans);

    return 0;
}
List::List(const int data) {
    this->data = data;
    this->link = nullptr;
}
List *List::insertNode(List *root, const int data) {
    if (root == nullptr) {
        root = new List(data);
        return root;
    }
    List *temp = root;
    while (temp->link != nullptr) {
        temp = temp->link;
    }
    temp->link = new List(data);
    return root;
}
void List::printList(List *root) {
    if (root == nullptr) {
        cout << "Empty";
        return;
    }
    while (root != nullptr) {
        cout << root->data << " ";
        root = root->link;
    }
}
Bst::Bst(const int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}
Bst *Bst::insertNode(Bst *root, const int data) {
    if (root == nullptr) {
        root = new Bst(data);
        return root;
    }
    Bst *temp = root;
    if (data <= temp->data) {
        temp->left = insertNode(temp, data);
    } else {
        temp->right = insertNode(temp, data);
    }
    return root;
}
void Bst::inorder(Bst *root) {
    if (root == nullptr)
    return;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
Bst *problem(List *root) {
    if (root == nullptr) {
        cout << "Empty";
        return nullptr;
    }
    vector<int> storage;
    while (root != nullptr) {
        storage.push_back(root->data);
        root = root->link;
    }
    int req_ind = storage.size() / 2;
    int req_data = storage[req_ind + 1];
    bst = nullptr;
    bst = bst->insertNode(bst, req_data);
    for (int i = req_ind; i >= 0; i--) {
        bst = bst->insertNode(bst, storage[i]);
    }
    for (int i = req_ind + 2; i < storage.size(); i++) {
        bst = bst->insertNode(bst, storage[i]);
    }
    return bst;
}
