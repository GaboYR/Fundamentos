#include<iostream>
using namespace std;
void print(int a[], int n) {
    for (int i = 0; i < n; i ++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
// a, b, ... p,    q ...
// a' , b' c ' .. p q' ...  
void quickSort(int a[], int n) {
    if (n <= 1) return;
    // El pivote es el último elemento
    int pivot = a[n - 1];
    cout << "Pivote: " << pivot << '\n';
    int i = 0;
    // Recorre el arreglo y coloca los elementos menores que el pivote a la izquierda
    // y los mayores a la derecha
    for (int j = 0; j < n - 1; j ++) {
        cout << "Valores de i y j: " << i << " , " << j << '\n';
        if (a[j] < pivot) {
            cout << "a[" << j << "] = " << a[j] << " < " << pivot << '\n';
            cout << "\nIntercambiamos a[" << i << "]:" << a[i] << " y  a[" << j << "]: " << a[j] << '\n';
            swap(a[i], a[j]);
            i ++;
        }
        else {
            cout << "a[" << j << "] = " << a[j] << " < " << pivot << "  (No cumple)\n";
            cout << "\nNo hay intercambio, j incrementa, i se queda igual\n";
        }
        print(a, n);
    }
    cout << "Intercambiamos a[" << i << "]:" << a[i] << " y  a[" << n - 1 << "]:" << a[n - 1] << '\n';
    swap(a[i], a[n - 1]);
    print(a, n);
    quickSort(a, i);
    quickSort(a + i + 1, n - i - 1);
}
int main () {
    int n = 10;
    int arr[n] = {3,1,4,1,5,9,2,6,5,4};
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
    quickSort(arr, n);
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
    return 0;
}