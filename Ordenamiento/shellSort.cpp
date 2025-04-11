#include<iostream>
using namespace std;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}
// Función para ordenar un arreglo usando el método de Shell Sort
void shellSort(int a[], int n) {
    // Comenzamos con un gran intervalo y lo reducimos
    // Ciclo for de complejidad O(log n)
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realizamos una inserción de Shell para el intervalo actual
        // Ciclo for de complejidad O(n)
        cout << "Intervalo: " << gap << '\n';
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            cout << "Elemento a insertar: " << temp << '\n';
            // Mueve los elementos de a[0..i-gap] que son mayores que temp
            // a una posición adelante de su posición actual
            // Ciclo for de complejidad O(n)
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                cout << "Intercambiamos a[" << j << "]:" << a[j] << " y  a[" << j - gap << "]:" << a[j - gap] << '\n';
                a[j] = a[j - gap];
            }
            a[j] = temp;
            cout << "Colocamos " << temp << " en la posición " << j << '\n';
            cout << "Arreglo actual: \n";
            printArray(a, n);
        }
    }
}

int main () {
    int n = 10;
    int arr[n] = {3,1,4,1,5,9,2,6,5,4};
    printArray(arr, n);
    // Shell Sort
    shellSort(arr, n);
    cout << "Arreglo ordenado: \n";
    printArray(arr, n);
    return 0;
}