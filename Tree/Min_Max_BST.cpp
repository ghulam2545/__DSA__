#include <ctime>
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* GetNew(int& val);
    Node* Insert(Node* root, int& val);
    void Print(Node* root);
    int FindMin(Node* root);
    int FindMax(Node* root);
    int FindMinR(Node* root);
    int FindMaxR(Node* root);
};
int main() {
    int num = 12;
    Node* obj = new Node();
    Node* parent = nullptr;
    srand(time(0));
    int a;
    while (num--) {
        a = rand() % 100;
        parent = obj->Insert(parent, a);
    }

    obj->Print(parent);
    cout << "\n\nMIN : " << obj->FindMin(parent);
    cout << "\n\nMAX : " << obj->FindMax(parent);
    cout << "\n\nMIN : " << obj->FindMinR(parent);
    cout << "\n\nMAX : " << obj->FindMaxR(parent);

    return 0;
}
Node* Node::GetNew(int& val) {
    Node* node = new Node();
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Node* Node::Insert(Node* root, int& val) {
    if (root == nullptr) {
        root = GetNew(val);
    } else {
        if (val < root->data) {
            root->left = Insert(root->left, val);
        } else {
            root->right = Insert(root->right, val);
        }
    }
    return root;
}
void Node::Print(Node* root) {
    if (root == nullptr) {
        return;
    }
    Print(root->left);
    Print(root->right);
    cout << root->data << " ";
}
int Node::FindMin(Node* root) {
    if (root == nullptr) {
        cout << "Empty : ";
        return -1;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}
int Node::FindMax(Node* root) {
    if (root == nullptr) {
        cout << "Empty : ";
        return -1;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}
int Node::FindMinR(Node* root) {
    if (root->left == nullptr) {
        return root->data;
    }
    return FindMinR(root->left);
}
int Node::FindMaxR(Node* root) {
    if (root->right == nullptr) {
        return root->data;
    }
    return FindMaxR(root->right);
}
