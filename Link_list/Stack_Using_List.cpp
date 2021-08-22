#include <iostream>
using namespace std;
template <typename T>
class Node {
    T data;
    Node<T>* link;
    Node<T>* GetNewNode(T input);
    void push(T input);
    void pop();
    bool empty();
    T top();
    int size();
    void print(Node<T>* root);  // Just for help
};
Node<string>* head = nullptr;  // Each time has to mention type

int main() {
    Node<string>* aa;
    aa = new Node<string>();
    
    return 0;
}
template <typename T>
Node<T>* Node<T>::GetNewNode(T input) {
    Node<T>* node = new Node<T>();
    node->data = input;
    node->link = nullptr;
    return node;
}
template <typename T>
void Node<T>::push(T input) {
    if (head == nullptr) {
        head = GetNewNode(input);
    } else {
        Node<T>* curr = head;
        head = GetNewNode(input);
        head->link = curr;
    }
    return;
}
template <typename T>
void Node<T>::pop() {
    if (head == nullptr) {
        cout << "Empty : ";
    } else {
        Node<T>* temp = head->link;
        Node<T>* toDelete = head;
        head = temp;
        free(toDelete);
    }
}
template <typename T>
bool Node<T>::empty() {
    if (head == nullptr)
        return true;
    else
        return false;
}
template <typename T>
T Node<T>::top() {
    if (head == nullptr) {
        cout << "Empty : ";
    } else {
        return head->data;
    }
}
template <typename T>
int Node<T>::size() {
    int ans = 0;
    if (head == nullptr) {
        return 0;
    } else {
        Node<T>* temp = head;
        while (temp != nullptr) {
            ++ans;
            temp = temp->link;
        }
    }
    return ans;
}
template <typename T>
void Node<T>::print(Node<T>* root) {
    if (root == nullptr) {
        cout << "Empty : ";
    } else {
        while (root != nullptr) {
            cout << root->data << " ";
            root = root->link;
        }
    }
    return;
}
