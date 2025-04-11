#include<iostream>
using namespace std;
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i ++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = key;
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
int main () {
    int n = 6;
    int arr[n] = {85,12,59,45,72,51};
    // Metodo insertion sort
    insertionSort(arr, n);
    // Imprimir el arreglo ordenado
    print(arr, n);
    return 0;
}