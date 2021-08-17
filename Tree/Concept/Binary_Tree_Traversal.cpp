#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
}* root = nullptr;
Node* GetNewNode(int value);
Node* InsertNode(Node* head, int value);
void PreOder(Node* head);
void PostOrder(Node* head);
void InOrder(Node* head);
void LevelOreder(Node* head);

int main() {
    root = InsertNode(root, 12);
    root = InsertNode(root, 34);
    root = InsertNode(root, 11);
    root = InsertNode(root, 45);
    root = InsertNode(root, 32);
    root = InsertNode(root, 31);
    cout << "PreOrder : \n";
    PreOder(root);
    cout << "\n\nPostOrder : \n";
    PostOrder(root);
    cout << "\n\nInOrder : \n";
    InOrder(root);
    cout << "\n\nLevelOrder : \n";
    LevelOreder(root);

    return 0;
}
Node* GetNewNode(int value) {
    Node* node = new Node();
    ;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
Node* InsertNode(Node* head, int value) {
    Node* NewlyCreatedNode = GetNewNode(value);
    if (head == nullptr) {
        head = NewlyCreatedNode;
    } else {
        if (value <= head->data) {
            head->left = InsertNode(head->left, value);
        } else {
            head->right = InsertNode(head->right, value);
        }
    }
    return head;
}

// DFS
void PreOder(Node* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    PreOder(head->left);
    PreOder(head->right);
}
void PostOrder(Node* head) {
    if (head == nullptr) return;
    PostOrder(head->left);
    PostOrder(head->right);
    cout << head->data << " ";
}
void InOrder(Node* head) {
    if (head == nullptr) return;
    InOrder(head->left);
    cout << head->data << " ";
    InOrder(head->right);
}

// BFS
void LevelOreder(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* temp;
    queue<Node*> qq;
    qq.push(head);
    while (qq.size()) {
        temp = qq.front();
        cout << temp->data << " ";
        if (temp->left != nullptr) {
            LevelOreder(temp->left);
        }
        if (temp->right != nullptr) {
            LevelOreder(temp->right);
        }
        qq.pop();
    }
}
