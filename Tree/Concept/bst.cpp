#include <iostream>
#include <queue>
class bst {
   private:
    int data;
    bst *left;
    bst *right;

   public:
    bst *getNewNode(const int value);
    bst *insertNode(bst *root, const int val);
    void preorder(bst *root);
    void postorder(bst *root);
    void inorder(bst *root);
    void levelorder(bst *root);
    bool search(bst *root, const int val);
    const int depthORheight(bst *root);
};

int main() {
    bst *instance = new bst();
    bst *head = nullptr;
    instance->preorder(head);
    std::cout << "\n\n";
    head = instance->insertNode(head, 12);
    head = instance->insertNode(head, 24);
    head = instance->insertNode(head, 8);
    head = instance->insertNode(head, 78);
    head = instance->insertNode(head, 1);
    head = instance->insertNode(head, 15);
    instance->preorder(head);
    std::cout << "\n\n";
    instance->postorder(head);
    std::cout << "\n\n";
    instance->inorder(head);
    std::cout << "\n\n";
    instance->levelorder(head);
    std::cout << "\n\n";
    std::cout << instance->search(head, 8);
    std::cout << "\n\n";
    std::cout << instance->search(head, 22);
    std::cout << "\n\n" << instance->depthORheight(head);
    return 0;
}
bst *bst::getNewNode(const int value) {
    bst *node = new bst();
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
bst *bst::insertNode(bst *root, const int val) {
    if (root == nullptr) {
        root = getNewNode(val);
        return root;
    }
    bst *temp = root;
    if (val <= root->data) {
        temp->left = insertNode(temp->left, val);
    } else {
        temp->right = insertNode(temp->right, val);
    }
    return root;
}
void bst::preorder(bst *root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void bst::postorder(bst *root) {
    if (root == nullptr) return;
    preorder(root->left);
    preorder(root->right);
    std::cout << root->data << " ";
}
void bst::inorder(bst *root) {
    if (root == nullptr) return;
    preorder(root->left);
    std::cout << root->data << " ";
    preorder(root->right);
}
void bst::levelorder(bst *root) {
    if (root == nullptr) return;
    std::queue<bst *> storage;
    storage.push(root);
    while (!storage.empty()) {
        bst *temp = storage.front();
        std::cout << temp->data << " ";
        if (temp->left != nullptr) storage.push(temp->left);
        if (temp->right != nullptr) storage.push(temp->right);
        storage.pop();
    }
}
bool bst::search(bst *root, const int val) {
    if (root == nullptr) return false;
    if (root->data == val) return true;
    return (search(root->left, val) || search(root->right, val));
}
const int bst::depthORheight(bst *root) {
    if (root == nullptr) return -1;
    return (std::max(depthORheight(root->left), depthORheight(root->right)) +
            1);
}
