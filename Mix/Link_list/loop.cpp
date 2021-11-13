// detect loop and remove
#include <iostream>
#include <unordered_set>
using namespace std;
struct Node {
    int data;
    Node* link;
    Node(const int& data) {
        this->data = data;
        this->link = nullptr;
    }
};
class solve {
   public:
    Node* insert(Node* root, const int& data);
    void print(Node* root);
    bool detect(Node* root);
    Node* remove(Node* root);
};
int main() {
    solve* oo = new solve();
    Node* head = nullptr;
    for (int i = 1; i < 12; ++i) {
        head = oo->insert(head, i);
    }
    // making loop
    head->link->link->link->link = head;
    // oo->print(head);
    cout << "\n";
    cout << oo->detect(head);
    cout << "\n";
    head = oo->remove(head);
    oo->print(head);

    return 0;
}
Node* solve::insert(Node* root, const int& data) {
    if (root == nullptr) {
        return root = new Node(data);
    }
    Node* temp = root;
    while (temp->link != nullptr) {
        temp = temp->link;
    }
    temp->link = new Node(data);
    return root;
}
void solve::print(Node* root) {
    if (root == nullptr) return;
    while (root != nullptr) {
        cout << root->data << " ";
        root = root->link;
    }
}
bool solve::detect(Node* root) {
    bool ans = false;
    unordered_set<Node*> s;
    if (root == nullptr) return false;
    s.insert(root);
    while (root->link != nullptr) {
        if (s.find(root->link) == s.end()) {
            s.insert(root->link);
        } else {
            ans = true;
            break;
        }
        root = root->link;
    }
    return ans;
}
Node* solve::remove(Node* root) {
    Node* ans = root;
    if (root == nullptr) return root;
    unordered_set<Node*> s;
    s.insert(root);
    while (root->link != nullptr) {
        if (s.find(root->link) == s.end()) {
            s.insert(root->link);
        } else {
            root->link = nullptr;
            break;
        }
        root = root->link;
    }
    return ans;
}