//Program-1: Program to implement BUBBLE SORT.
#include <iostream>
using namespace std;
void bubbleSort(int array[], int n) {
for (int i = 0; i<n-1; ++i) {
for (int j = 0; j< n-1; ++j) {
if (array[j] > array[j+1]) {
int temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
}
}
}
}
void printArray(int array[], int n) {
for (int i = 0; i < n; ++i) {
cout << " " << array[i];
}
cout << "\n";
}
int main() {
int data[] = {100, 55, 0, 11, -9};
int n = sizeof(data) / sizeof(data[0]);
bubbleSort(data, n);
cout << "Sorted Array in Ascending Order:\n";
printArray(data, n);
}
