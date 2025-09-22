#include <iostream>
#include <iomanip>
long long factorial(int n) {
    if (n == 0) return 1;
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}
void init(long long** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = factorial(i + j);
        }
    }
}
void print2D(long long** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(8) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void print1D(long long* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(8) << arr[i];
    }
    std::cout << std::endl;
}
long long* transform(long long** matrix, int size, int& out_size) {
    out_size = size * size;
    long long* arr = new long long[out_size];
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[k] = matrix[i][j];
            k++;
        }
    }
    return arr;
}
int main() {
    std::setlocale(LC_ALL, "Russian");
    int size = 5;
    long long** matrix = new long long* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new long long[size];
    }
    init(matrix, size);
    std::cout << "2D массив:" << std::endl;
    print2D(matrix, size);
    int out_size;
    long long* oneD = transform(matrix, size, out_size);
    std::cout << "1D массив:" << std::endl;
    print1D(oneD, out_size);
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] oneD;
    return 0;
}