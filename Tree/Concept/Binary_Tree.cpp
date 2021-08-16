// Improve for edges cases

#include <bits/stdc++.h>
using namespace std;
struct BinaryTree {
    int data;
    BinaryTree* left;
    BinaryTree* right;
}* root = nullptr;
BinaryTree* GetNewNode(int val);
BinaryTree* InsertNode(BinaryTree* root, int val);
void Print(BinaryTree* head);
void Search(BinaryTree* head);

int main() {
    root = InsertNode(root, 12);
    root = InsertNode(root, 13);
    root = InsertNode(root, 11);
    root = InsertNode(root, 14);
    root = InsertNode(root, 56);
    root = InsertNode(root, 34);
    root = InsertNode(root, 54);

    Print(root);
    cout << "\n\n";
    Search(root);

    return 0;
}

BinaryTree* GetNewNode(int val) {
    BinaryTree* node = new BinaryTree();
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
BinaryTree* InsertNode(BinaryTree* root, int val) {
    BinaryTree* NewlyNode = GetNewNode(val);
    if (root == nullptr) {
        root = NewlyNode;
    } else {
        if (val <= root->data) {
            root->left = InsertNode(root->left, val);
        } else {
            root->right = InsertNode(root->right, val);
        }
    }
    return root;
}
void Print(BinaryTree* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    Print(head->left);
    Print(head->right);
}
void Search(BinaryTree* head) {
    int num = 0;
    cin >> num;
    bool ans = false;
    if (head == nullptr) return;
    if (head->data == num) {
        ans = true;
    }
    Search(head->left);
    Search(head->right);
    ans == true ? cout << "Found " : cout << "Not Found";
}
