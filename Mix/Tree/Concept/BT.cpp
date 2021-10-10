// Read article/prob form gfg and implement

#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct BTree {
    string data;
    BTree* left;
    BTree* right;
    BTree* getNewNode(const string& value);
    BTree* insertNode(BTree* src, const string& value);
    int height(BTree* src);
    bool find(BTree* src, const string& data);

    void preOrder(BTree* head);
    void postOrder(BTree* head);
    void inOrder(BTree* head);
    void levelOrder(BTree* head);
    void levelOrder2(BTree* head);  // ???
};
int main() {
    BTree bb;
    BTree* root = nullptr;
    const string names[] = {"name1", "name2", "name3", "name4", "name5", "name6", "name7"};
    int size = sizeof(names) / sizeof(names[0]);
    for (int i = 0; i < size; ++i) {
        root = bb.insertNode(root, names[i]);
    }
    bb.levelOrder(root);
    cout << "\n" << bb.height(root);
    cout << "\n\n";
    cout << bb.find(root, "name3");
    cout << "\n\n" << bb.find(root, "name");

    return 0;
}
BTree* BTree::getNewNode(const string& value) {
    BTree* node = new BTree();
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
BTree* BTree::insertNode(BTree* src, const string& value) {
    if (src == nullptr) {
        src = getNewNode(value);
        return src;
    }
    queue<BTree*> q;
    q.push(src);
    while (q.size()) {
        BTree* temp = q.front();
        if (temp->left != nullptr) {
            q.push(temp->left);
        } else {
            temp->left = getNewNode(value);
            return src;
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        } else {
            temp->right = getNewNode(value);
            return src;
        }
        q.pop();
    }
}
int BTree::height(BTree* src) {
    if (src == nullptr) return -1;
    return max(height(src->left), height(src->right)) + 1;
}
bool BTree::find(BTree* src, const string& data) {
    bool ans = false;
    if (src == nullptr) ans = false;
    queue<BTree*> s;
    s.push(src);
    while (s.size()) {
        BTree* temp = s.front();
        if (temp->left != nullptr) {
            s.push(temp->left);
        }
        if (temp->right != nullptr) {
            s.push(temp->right);
        }
        if (data == (temp->data)) {
            ans = true;
            break;
        }
        s.pop();
    }
    return ans;
}

// Traversals
void BTree::preOrder(BTree* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}
void BTree::postOrder(BTree* head) {
    if (head == nullptr) return;
    preOrder(head->left);
    preOrder(head->right);
    cout << head->data << " ";
}
void BTree::inOrder(BTree* head) {
    if (head == nullptr) return;
    preOrder(head->left);
    cout << head->data << " ";
    preOrder(head->right);
}
void BTree::levelOrder(BTree* head) {
    if (head == nullptr) return;
    queue<BTree*> s;
    s.push(head);
    while (s.size()) {
        BTree* temp = s.front();
        if (temp->left != nullptr) {
            s.push(temp->left);
        }
        if (temp->right != nullptr) {
            s.push(temp->right);
        }
        cout << temp->data << " ";
        s.pop();
    }
}