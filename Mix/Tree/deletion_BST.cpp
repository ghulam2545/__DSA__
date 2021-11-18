// do complete
// deletion in bst

#include <cmath>
#include <ctime>
#include <iostream>

#include "2d_Tree.h"
using namespace std;
// struct Tree {
//     int data;
//     Tree* left;
//     Tree* right;
// };
class solve {
   public:
    Tree* getNode(const int& data);
    Tree* insert(Tree* root, const int& data);
    Tree* Delete(Tree* root, const int& data);

   private:
};
int main() {
    srand(time(0));
    solve* oo = new solve();
    Tree* head = NULL;
    for (int i = 0; i < 12; ++i) {
        head = oo->insert(head, rand() % 100);
    }
    print_ascii_tree(head);
    return 0;
}
Tree* solve::getNode(const int& data) {
    Tree* node = new Tree();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Tree* solve::insert(Tree* root, const int& data) {
    if (root == NULL) {
        root = getNode(data);
        return root;
    }
    Tree* temp = root;
    if (data < root->data) {
        temp->left = insert(temp->left, data);
    } else {
        temp->right = insert(temp->right, data);
    }
    return root;
}
Tree* solve::Delete(Tree* root, const int& data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = Delete();
    } else if (data > root->data) {
    }
}