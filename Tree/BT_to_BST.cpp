#include <iostream>
using namespace std;
class Node {
    int data;
    Node* left;
    Node* right;
    public:
    Node* getNew(int val);
    Node* insert(Node* root, int insertVal);
};

int main() {
    Node *oo = new Node();

    return 0;
}

Node* Node::getNew(int val) {
    Node *node = new Node();
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Node* Node::insert(Node* root, int insertVal) {
    if(root == nullptr) {
        root = getNew(insertVal);
        return root;
    }
    Node* temp = root;
    
}