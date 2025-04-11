#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}
void heapify(int arr[],int n, int i) {
    int largest = i; // Inicializa el nodo más grande como raíz
    int left = 2 * i + 1; // hijo izquierdo
    int right = 2 * i + 2; // hijo derecho

    // Si el hijo izquierdo es mayor que la raíz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // Si el hijo derecho es mayor que el más grande hasta ahora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // Si el más grande no es la raíz
    if (largest != i) {
        swap(arr[i], arr[largest]); // Intercambia la raíz con el más grande
        heapify(arr, n, largest); // Recursivamente heapifica la subárbol afectada
    }
}
void maxHeapSort(int arr[], int n) {
    // Construir el heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extraer elementos del heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Mueve la raíz actual al final
        heapify(arr, i, 0); // Llama a heapify en el heap reducido
    }
}
int main () {
    int n = 20;
    // Arreglo con valores aleatorios
    int arr[n] = {98, 23, 45, 12, 67, 89, 34, 56, 78, 90,
                   11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    printArray(arr,n);
    maxHeapSort(arr, n);
    cout << "Arreglo ordenado: \n";
    printArray(arr, n);
    return 0;
}