#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinarySearchTree {
   private:
    T data;
    BinarySearchTree<T> *left;
    BinarySearchTree<T> *right;
    int ans;

   public:
    BinarySearchTree<T>();
    BinarySearchTree<T> *GetNewNode(T &val);
    BinarySearchTree<T> *InsertNode(BinarySearchTree *head, T &val);
    void Traverse(BinarySearchTree<T> *head);
    int SumOfVal(BinarySearchTree<T> *head);
    T SumOfVal_2(BinarySearchTree<T> *head);
    bool FindElement(BinarySearchTree<T> *head, T &val);
    int Height(BinarySearchTree<T> *head);
    int NoOfLeaf(BinarySearchTree<T> *head);
};

int main() {
    BinarySearchTree<int> ob;
    BinarySearchTree<int> *root = NULL;
    int num[] = {10, 8, 9, 2, 20, 30, 40, 29};
    int n = sizeof(num) / sizeof(num[0]);
    for (int i = 0; i < n; i++) {
        root = ob.InsertNode(root, num[i]);
    }

    ob.Traverse(root);
    cout << "\n\n";

    cout << ob.Height(root);
    cout << "\n\n" << ob.NoOfLeaf(root);

    return 0;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    ans = 0;
}

template <typename T>
BinarySearchTree<T> *BinarySearchTree<T>::GetNewNode(T &val) {
    BinarySearchTree<T> *node = new BinarySearchTree();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

template <typename T>
BinarySearchTree<T> *BinarySearchTree<T>::InsertNode(BinarySearchTree<T> *head, T &val) {
    if (head == NULL) {
        head = GetNewNode(val);
        return head;
    }
    BinarySearchTree<T> *curr = head;
    if (val <= curr->data) {
        curr->left = InsertNode(curr->left, val);
    } else {
        curr->right = InsertNode(curr->right, val);
    }
    return head;
}

template <typename T>
void BinarySearchTree<T>::Traverse(BinarySearchTree<T> *head) {
    if (head == NULL) {
        return;
    }
    cout << head->data << " ";
    Traverse(head->left);
    Traverse(head->right);
}

template <typename T>
int BinarySearchTree<T>::SumOfVal(BinarySearchTree<T> *head) {
    if (head == NULL) return 0;
    return (head->data + SumOfVal(head->left) + SumOfVal(head->right));
}

template <typename T>
T BinarySearchTree<T>::SumOfVal_2(BinarySearchTree<T> *head) {
    T ans;
    queue<BinarySearchTree<T> *> storage;
    storage.push(head);
    while (!storage.empty()) {
        BinarySearchTree<T> *curr = storage.front();
        ans += curr->data;
        storage.pop();
        if (curr->left != NULL) {
            storage.push(curr->left);
        }
        if (curr->right != NULL) {
            storage.push(curr->right);
        }
    }
    return ans;
}

template <typename T>
bool BinarySearchTree<T>::FindElement(BinarySearchTree<T> *head, T &val) {
    if (head == NULL) {
        return false;
    }
    if (head->data == val) {
        return true;
    }
    return (FindElement(head->left, val) || FindElement(head->right, val));
}

template <typename T>
int BinarySearchTree<T>::Height(BinarySearchTree<T> *head) {
    if (head == NULL) {
        return -1;
    }
    int _left = Height(head->left);
    int _right = Height(head->right);
    return max(_left, _right) + 1;
}

template <typename T>
int BinarySearchTree<T>::NoOfLeaf(BinarySearchTree<T> *head) {
    if (head == NULL) {
        return 0;
    }
    if (head->left == NULL && head->right == NULL) {
        ++ans;
    }
    if (head->left != NULL) NoOfLeaf(head->left);
    if (head->right != NULL) NoOfLeaf(head->right);
    return ans;
}
