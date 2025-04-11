#include<iostream>
using namespace std;
int main () {
    int n = 10;
    int arr[n] = {2,5,1,5,2,6,7,1,0,1};
    // Metodo selectionsort
    for (int i = 0; i < n - 1; i ++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j ++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Intercambiar
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    // Imprimir el arreglo ordenado
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
    return 0;
}