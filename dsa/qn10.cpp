//Program-2: Program to implement SELECTION SORT.
#include <iostream>
using namespace std;
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
void printArray(int array[], int n) {
for (int i = 0; i < n; i++) {
cout << array[i] << " ";
}
cout << endl;
}
void selectionSort(int array[], int n) {
for (int i = 0; i < n - 1; i++) {
int min_idx = i;
for (int j = i + 1; j < n; j++) {
if (array[j] < array[min_idx])
min_idx = j;
}
swap(&array[min_idx], &array[i]);
}
}
int main() {
int data[] = {20, 12, 10, 15, 2};
int n = sizeof(data) / sizeof(data[0]);
selectionSort(data, n);
cout << "Sorted array in Acsending Order:\n";
printArray(data, n);
}
