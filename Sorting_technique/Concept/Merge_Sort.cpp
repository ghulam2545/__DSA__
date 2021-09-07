//#include <bits/stdc++.h>
//using namespace std;
//void merge(int* arr1, int size1, int* arr2, int size2, int* farr);
//int main() {
//    int a[] = {1, 4, 5, 7, 8, 10};
//    int b[] = {2, 3, 6, 7, 9, 11, 12, 13, 14};
//    int a1 = sizeof(a) / sizeof(a[0]);
//    int b1 = sizeof(b) / sizeof(b[0]);
//    int finalArr[a1 + b1];
//    merge(a, a1, b, b1, finalArr);
//    for (int i = 0; i < a1 + b1; i++) {
//        cout << finalArr[i] << " ";
//    }
//    return 0;
//}
//
//void merge(int* arr1, int size1, int* arr2, int size2, int* farr) {
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < size1 && j < size2) {
//        if (arr1[i] < arr2[j]) {
//            farr[k] = arr1[i];
//            k += 1;
//            i += 1;
//        } else {
//            farr[k] = arr2[j];
//            k += 1;
//            j += 1;
//        }
//    }
//    while (i < size1) {
//        farr[k] = arr1[i];
//        k += 1;
//        i += 1;
//    }
//    while (j < size2) {
//        farr[k] = arr2[j];
//        k += 1;
//        j += 1;
//    }
//}
