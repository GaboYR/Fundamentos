#include<iostream>
using namespace std;
void merge(int a[], int b[],int sza, int szb, int c[]){
    int i = 0, j = 0, k = 0;

    while (i < sza && j < szb) {
        c[k ++] = a[i] < b[j] ? a[i ++] : b[j ++];
    }
    
    while (i < sza) c[k ++] = a[i ++];
    
    while (j < szb) c[k ++] = b[j ++];
}
// Funcion recursiva
void mergeSort(int a[], int sza) {
    if (sza == 1)   return;
    
    int mid = sza / 2;
    int l[mid],r[sza - mid];
    
    for (int i = 0; i < sza; i ++) {
        if (i < mid) l[i] = a[i];
        else r[i - mid] = a[i];
    }
    
    mergeSort(l,mid);
    mergeSort(r,sza - mid);
    merge(l,r,mid,sza - mid,a);
}
void print(int a[], int sza)  {
    for (int i = 0; i < sza; i ++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
int main (){
    int n = 10;
    int arr[n] = {3,1,4,1,5,9,2,6,5,4};
    print(arr,10);
    mergeSort(arr,10);
    print(arr,10);
    return 0;
}