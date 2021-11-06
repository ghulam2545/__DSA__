// sorted item to bbst

#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* left;
    Node* right;
};
class solve {
   public:
    Node* getNode(char val);
    Node* build(char* arr, int start, int end);
    void inOrder(Node* root);
};
int main() {
    char letter[] = {'H', 'I', 'J', 'B', 'A', 'E', 'C', 'F', 'D', 'G', 'K', 'L'};
    int size = sizeof(letter) / sizeof(letter[0]);
    sort(letter, letter + size);
    solve aa;
    Node* head = aa.build(letter, 0, size - 1);
    aa.inOrder(head);

    return 0;
}
Node* solve::getNode(char val) {
    Node* node = new Node();
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Node* solve::build(char* arr, int start, int end) {
    if (end < start) return nullptr;
    int mid = (start + end) / 2;
    Node* root = getNode(arr[mid]);
    root->left = build(arr, start, mid - 1);
    root->right = build(arr, mid + 1, end);
    return root;
}
void solve::inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}