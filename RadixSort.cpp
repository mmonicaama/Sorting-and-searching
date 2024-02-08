#include <iostream>
#include <vector>
#include <algorithm>

//this version works for non-negative numbers
void countSort(std::vector<int>& arr, int exp)
{
    std::vector<int> output(arr.size());
    int i;
    std::vector<int> count(10, 0);

    for (i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr)
{
    auto maxElement = std::max_element(arr.begin(), arr.end());
    int m = *maxElement;

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main()
{
    std::vector<int> vec {5, 74, 12, 0, 655};
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    radixSort(vec);
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}