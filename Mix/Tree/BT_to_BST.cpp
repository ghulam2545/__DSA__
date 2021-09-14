#include <iostream>
#include <queue>
#include <vector>
class bt {
   private:
    int data;
    bt* left;
    bt* right;

   public:
    bt* getNewNode(const int val);
    bt* insertNode(bt* root, const int val);
    void deleteNode(bt* root, int val);  // exist*
    std::vector<int>& levelorder(bt* root);
    bt* bt_to_bst(bt* root);  // return ref of bst
};

int main() {
    bt* instance = new bt();
    bt* head = nullptr;
    head = instance->insertNode(head, 10);
    head = instance->insertNode(head, 20);
    head = instance->insertNode(head, 30);
    head = instance->insertNode(head, 40);
    head = instance->insertNode(head, 50);
    head = instance->insertNode(head, 60);
    head = instance->insertNode(head, 70);
    head = instance->insertNode(head, 80);
    std::vector<int> tt = instance->levelorder(head);
    for (int& e : tt) std::cout << e << " ";

    return 0;
}
bt* bt::getNewNode(const int val) {
    bt* node = new bt();
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
bt* bt::insertNode(bt* root, const int val) {
    if (root == nullptr) {
        root = getNewNode(val);
        return root;
    }
    std::queue<bt*> storage;
    storage.push(root);
    while (storage.size()) {
        bt* newNode = getNewNode(val);
        bt* temp = storage.front();
        if (temp->left != nullptr) {
            storage.push(temp->left);
        } else {
            temp->left = newNode;
            return root;
        }
        if (temp->right != nullptr) {
            storage.push(temp->right);
        } else {
            temp->right = newNode;
            return root;
        }
        storage.pop();
    }
}
std::vector<int>& bt::levelorder(bt* root) {
    static std::vector<int> bag;  // for some reason
    if (root == nullptr) return bag;
    std::queue<bt*> storage;
    storage.push(root);
    bt* temp;
    while (storage.size()) {
        temp = storage.front();
        bag.push_back(temp->data);
        if (temp->left != nullptr) storage.push(temp->left);
        if (temp->right != nullptr) storage.push(temp->right);
        storage.pop();
    }
    std::cout << "\n\ndeepest node : " << temp->data << " \n\n";
    return bag;
}

// swapping done but not last node deleted
void bt::deleteNode(bt* root, int val) {
    std::queue<bt*> sto;
    bt* toBeDelete = nullptr;
    sto.push(root);
    bt* top;
    while (sto.size()) {
        top = sto.front();
        if (top->data == val) {
            toBeDelete = top;
        }
        if (top->left != nullptr) sto.push(top->left);
        if (top->right != nullptr) sto.push(top->right);
        sto.pop();
    }
    toBeDelete->data = top->data;
    // delete top;
}
bt* bt::bt_to_bst(bt* root) {
    std::vector<int> frombt = levelorder(root);
    // do here;
}