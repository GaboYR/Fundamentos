#include<iostream>
using namespace std;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}
// Función para obtener el dígito en la posición exp
int getDigit(int num, int exp) {
    return (num / exp) % 10;
}
// Función para realizar el conteo de dígitos
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Arreglo de salida
    int count[10] = {0}; // Inicializa el conteo a 0

    // Almacena el conteo de dígitos
    for (int i = 0; i < n; i++) {
        count[getDigit(arr[i], exp)]++;
    }

    // Cambia el conteo para que contenga la posición real
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construye el arreglo de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[getDigit(arr[i], exp)] - 1] = arr[i];
        count[getDigit(arr[i], exp)]--;
    }

    // Copia el arreglo de salida al arreglo original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
// Función principal de Radix Sort
void radixSort(int arr[],int n) {
    // Encuentra el número máximo para saber el número de dígitos
    int maxNum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    // Aplica Counting Sort para cada dígito
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
    // El arreglo ahora está ordenado
}
int main () {
    int n = 10;
    int arr[n] = {3,123,21,3412,213,456,789,12300,0,1};
    printArray(arr, n);
    // Radix Sort
    radixSort(arr, n);
    cout << "Arreglo ordenado: \n";
    printArray(arr, n);
    return 0;
}