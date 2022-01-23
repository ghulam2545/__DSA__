// Doubly Link List
// a forward and backward pointing relation
// insert -- delete -- size -- empty -- clear -- reverse -- sort etc

#include <iostream>
using namespace std;

template <class T>
class DoublyLinkList {
   public:
    // DoublyLinkList() = default;                                             // default constr
    // DoublyLinkList(const DoublyLinkList<T>& __l) = default;                 // copy constr
    // DoublyLinkList(const DoublyLinkList<T>&& __l) = default;                // move constr
    // DoublyLinkList<T>& operator=(const DoublyLinkList<T>& __l) = default;   // copy assign
    // DoublyLinkList<T>& operator=(const DoublyLinkList<T>&& __l) = default;  // move assign

    using iterator = T*;
    constexpr iterator begin();

    // this will cerate a node by provided data
    constexpr DoublyLinkList<T>* getNewNode(T data);

    // insertion
    constexpr DoublyLinkList<T>* push_back(DoublyLinkList<T>* __head, const T& data);
    constexpr DoublyLinkList<T>* push_front(DoublyLinkList<T>* __head, const T& data);
    constexpr DoublyLinkList<T>* insert(DoublyLinkList<T>* __head, const T& data, iterator pos);

    // deletion
    DoublyLinkList* pop_front();
    DoublyLinkList* pop_back();
    DoublyLinkList* erase();
    void clear();

    void print(DoublyLinkList<T>* __head) {
        if (__head == nullptr) return;
        while (__head != nullptr) {
            cout << __head->data << "  ";
            __head = __head->next;
        }
    }

   private:
    T data;
    DoublyLinkList<T>* next;
    DoublyLinkList<T>* prev;
};

int main() {
    DoublyLinkList<int>* myList = nullptr;
    DoublyLinkList<int>* oo = new DoublyLinkList<int>();
    oo->print(myList);
    myList = oo->push_back(myList, 12);
    myList = oo->push_back(myList, 23);

    myList = oo->push_front(myList, 212);
    myList = oo->push_front(myList, 323);

    oo->print(myList);

    return 0;
}

template <class T>
constexpr DoublyLinkList<T>* DoublyLinkList<T>::getNewNode(T data) {
    DoublyLinkList<T>* node = new DoublyLinkList<T>();
    node->data = data;
    node->prev = nullptr;
    node->next = nullptr;
    return node;
}

template <class T>
constexpr DoublyLinkList<T>* DoublyLinkList<T>::push_back(DoublyLinkList<T>* __head, const T& data) {
    if (__head == nullptr) {
        __head = getNewNode(data);
        return __head;
    }
    DoublyLinkList<T>* newNode = getNewNode(data);
    DoublyLinkList<T>* last = __head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return __head;
}

template <class T>
constexpr DoublyLinkList<T>* DoublyLinkList<T>::push_front(DoublyLinkList<T>* __head, const T& data) {
    if (__head == nullptr) {
        __head = getNewNode(data);
        return __head;
    }
    DoublyLinkList<T>* newNode = getNewNode(data);
    newNode->next = __head;
    newNode->prev = nullptr;
    __head->prev = newNode;
    __head = newNode;
    return __head;
}

template <class T>
constexpr DoublyLinkList<T>* DoublyLinkList<T>::insert(DoublyLinkList<T>* __head, const T& data, iterator pos) {}