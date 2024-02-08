#include <iostream>
#include <vector>

int findIndexOfLargest(const std::vector<int>& arr, int size) 
{
    int max_idx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

void selectionSort(std::vector<int>& arr)
{
    for (int i = arr.size() - 1; i >= 1; --i) {
        int largest = findIndexOfLargest(arr, i + 1);
        std::swap(arr[largest], arr[i]);
    }
}

int main()
{
    std::vector<int> vec {5, 74, -1, 0, 655};
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    selectionSort(vec);
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}