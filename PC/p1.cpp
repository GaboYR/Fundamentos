#include<iostream>
using namespace std;
const int maxn = 15;
int A[maxn][maxn];
int n;
// a[i][j] = a[i-1][j-1] + a[i-1][j]

int pascal(int i, int j) {
    // Si el indica esta fuera de la matriz
    if (i < 0 || j < 0 || i >= n || j >= n || i < j) {
        return 0;
    }
    // Diagonales y primera columna
    else if (i == j || j == 0) {
        A[i][j] = 1;
    }
    else {
        A[i][j] = pascal(i-1,j-1) + pascal(i-1,j);
    }
    return A[i][j];
}
void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            pascal(i,j);
        }
    }
    print(n);
    return  0;
}