#include <ctime>
#include <iostream>
#include <queue>
using namespace std;
struct Btree {
    int data;
    Btree* left;
    Btree* right;
    Btree* getNode(const int& data);
    Btree* insert(Btree* src, const int& data);
    void inorder(Btree* head);  // this is solution
};
int main() {
    Btree aa;
    srand(time(0));
    Btree* root = nullptr;
    root = aa.insert(root, 12);
    root = aa.insert(root, 32);
    root = aa.insert(root, 11);
    root = aa.insert(root, 33);
    root = aa.insert(root, 15);
    root = aa.insert(root, 51);
    cout << "\n";
    aa.inorder(root);
    cout << "\n";

    return 0;
}
Btree* Btree::getNode(const int& data) {
    Btree* node = new Btree();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Btree* Btree::insert(Btree* src, const int& data) {
    if (src == nullptr) {
        src = getNode(data);
        return src;
    }
    Btree* temp = src;
    if (data <= src->data) {
        temp->left = insert(temp->left, data);
        return src;
    } else {
        temp->right = insert(temp->right, data);
        return src;
    }
}
void Btree::inorder(Btree* head) {
    if (head == nullptr) return;
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}