#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <fstream>

#include "FenwickTree.h"

int main()
{
    std::srand(std::time(nullptr));
    std::cout << std::fixed << std::setprecision(14);

    std::ofstream file("C:\\Users\\Igor\\Desktop\\a.txt");

    for (long long n = 4; n < 40000; n += 10) {
        int* arr = new int[n];

        for (long long i = 0; i < n; i++) {
            arr[i] = std::rand();
        }

        FenwickTree<int> ft(arr, n);

        auto start = std::chrono::system_clock::now();
        auto end = std::chrono::system_clock::now();
        double result = 0.0;

        for (size_t _j = 0; _j < 4000; _j++) {
            int mode = abs(std::rand()) % 3;

            int i, j;
            i = abs(std::rand()) % n;
            j = abs(std::rand()) % n;
            if (i > j) std::swap(i, j);

            switch (mode) {
            case 0:
                start = std::chrono::system_clock::now();
                ft.sum(i, j);
                end = std::chrono::system_clock::now();
                break;
            case 1:
                start = std::chrono::system_clock::now();
                ft.modify(i, j);
                end = std::chrono::system_clock::now();
                break;
            case 2:
                start = std::chrono::system_clock::now();
                ft.set(i, j);
                end = std::chrono::system_clock::now();
                break;
            }

            result += std::chrono::duration<double>(end - start).count() / 4000;
            
        }

        file << n << " " << result << std::endl;

        delete[] arr;
    }

    return 0;
}