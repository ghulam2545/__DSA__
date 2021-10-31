// min heap
#include <iostream>
using namespace std;
struct heap {
    int capacity;
    int size;
    int* arr;
};
class member : public heap {
   public:
    heap* create(int capacity);
    int parent(int i);
    int left(int i);
    int right(int i);
    int min(heap* h);
    void destroy(heap* h);
    void resize(heap* h);
    void push(heap* h, int data);
    void print(heap* h);
    void pop(heap* h);
    void heapify(heap* h, int i);
};
int main() {
    member* inst = new member();
    heap* MyHeap = new heap();
    MyHeap = inst->create(20);
    inst->push(MyHeap, 40);
    inst->push(MyHeap, 20);
    inst->push(MyHeap, 70);
    inst->push(MyHeap, 10);
    inst->push(MyHeap, 20);
    inst->push(MyHeap, 80);
    inst->push(MyHeap, 30);
    inst->push(MyHeap, 20);
    inst->pop(MyHeap);
    inst->print(MyHeap);
    return 0;
}
heap* member::create(int capacity) {
    heap* buildHeap = new heap();
    if (buildHeap == nullptr) {
        cout << "memory error";
        return nullptr;
    }
    buildHeap->capacity = capacity;
    buildHeap->size = 0;
    buildHeap->arr = new int[capacity];
    if (buildHeap->arr == nullptr) {
        cout << "memory error";
        return nullptr;
    }
    return buildHeap;
}
void member::push(heap* h, int data) {
    if (h->size == h->capacity) {
        resize(h);
    }
    ++(h->size);
    int i = h->size - 1;
    h->arr[i] = data;
    while (i != 0 && h->arr[parent(i)] >= h->arr[i]) {
        std::swap(h->arr[parent(i)], h->arr[i]);
        i = parent(i);
    }
}
void member::pop(heap* h) {
    if (h->size == 0) {
        cout << "empty";
        return;
    } else if (h->size == 1) {
        --(h->size);
    } else {
        std::swap(h->arr[0], h->arr[h->size - 1]);
        --(h->size);
        heapify(h, 0);
    }
}

void member::heapify(heap* h, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < h->size && h->arr[l] < h->arr[i]) smallest = l;
    if (r < h->size && h->arr[r] < h->arr[smallest]) smallest = r;
    if (smallest != i) {
        std::swap(h->arr[i], h->arr[smallest]);
        heapify(h, smallest);
    }
}
int member::parent(int i) { return (i - 1) / 2; }
int member::left(int i) { return (2 * i + 1); }
int member::right(int i) { return (2 * i + 2); }
int member::min(heap* h) { return h->arr[0]; }
void member::print(heap* h) {
    if (h->size == 0) cout << "empty";
    for (int i = 0; i < h->size; ++i) {
        cout << h->arr[i] << " ";
    }
    cout << "\n";
}
void member::destroy(heap* h) {
    delete h;
    delete[] h->arr;
}
void member::resize(heap* h) {
    int* old_arr = h->arr;
    h->arr = new int[h->capacity * 2];
    if (h->arr == NULL) {
        printf("memory error");
        return;
    }
    for (int i = 0; i < h->capacity; ++i) {
        h->arr[i] = old_arr[i];
    }
    h->capacity *= 2;
    delete[] old_arr;
}