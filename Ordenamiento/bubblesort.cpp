#include<iostream>
using namespace std;

int main () {
    int n = 10;
    int arr[n] = {2,5,1,5,2,6,7,1,0,1};
    // Metodo bubblesort
    for (int i = 0; i < n - 1; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (arr[i] > arr[j]) {
                // Intercambiar
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Imprimir el arreglo ordenado
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
    return 0;
}