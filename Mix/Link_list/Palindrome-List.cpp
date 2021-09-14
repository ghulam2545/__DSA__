// You have head of list check whether stored data are palindrome or not
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* link;
    Node* getNew(int val);
    Node* insert(Node* root, int val);
    void print(Node* root);
    bool Palin(Node* root);
    bool palindrome(vector<int>& num);
}* root = nullptr;

int main() {
    Node aa;
    root = aa.insert(root, 10);
    root = aa.insert(root, 20);
    root = aa.insert(root, 40);
    root = aa.insert(root, 40);
    root = aa.insert(root, 20);
    root = aa.insert(root, 10);
    bool ans = aa.Palin(root);
    ans == true ? cout << "Palindrome" : cout << "Not Palindrome";
    // aa.print(root);
    return 0;
}

Node* Node::getNew(int val) {
    Node* node = new Node();
    node->data = val;
    node->link = nullptr;
    return node;
}
Node* Node::insert(Node* root, int val) {
    if (root == nullptr) {
        root = getNew(val);
    } else {
        Node* curr = root;
        while (curr->link != nullptr) {
            curr = curr->link;
        }
        curr->link = getNew(val);
    }
    return root;
}
void Node::print(Node* root) {
    if (root == nullptr) {
        return;
    } else {
        while (root != nullptr) {
            cout << root->data << " ";
            root = root->link;
        }
    }
}
bool Node::Palin(Node* root) {
    vector<int> v;
    if (root == nullptr) {
        return 0;
    } else {
        while (root != nullptr) {
            v.push_back(root->data);
            root = root->link;
        }
    }
    return palindrome(v);
}
bool Node::palindrome(vector<int>& num) {
    bool ans = true;
    for (int i = 0; i <= num.size() / 2; i++) {
        if (num[i] != num[num.size() - 1 - i]) {
            ans = false;
        }
    }
    return ans;
}
