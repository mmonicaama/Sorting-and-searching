#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr)
{
    for (int unsorted = 1; unsorted < arr.size(); ++unsorted) {
        int current = arr[unsorted];
        int sorted = unsorted - 1;
        while (sorted >= 0 && current < arr[sorted]) {
            arr[sorted + 1] = arr[sorted];
            --sorted;
        }
        arr[sorted + 1] = current;
    }
}

int main()
{
    std::vector<int> vec {5, 74, -1, 0, 655};
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    insertionSort(vec);
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}