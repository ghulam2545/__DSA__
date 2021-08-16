#include <iostream>
#include <algorithm>
int data[] = {12, 67, 34, 89, 44, 23, 47, 67, 54, 33, 30};
int size = sizeof(data) / sizeof(data[0]);
int* partition(int* start, int* end);
void QuickSort(int* start, int* end);
void print();

int main() {
	print();
	std::cout<<"\n\n";
	int* a = data, *b = &data[size-1];
	QuickSort(a, b);
	print();
	
    return 0;
}

void QuickSort(int* start, int* end) {
    if (start >= end) return;
    int* index = partition(start, end);
    QuickSort(start, index - 1);
    QuickSort(index + 1, end);
}

int* partition(int* start, int* end) {
    int pivotElement = *end;
    int* pIndex = start;
    for (auto i = start; i <= end - 1; i++) {
        if (*i <= pivotElement) {
            std::swap(*i, *pIndex);
            pIndex++;
        }
    }
    std::swap(*end, *pIndex);
    return pIndex;
}

void print() {
    for (auto& e : data) {
        std::cout << e << " ";
    }
}
