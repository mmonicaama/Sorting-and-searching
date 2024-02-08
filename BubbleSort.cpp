#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr)
{
    bool sorted = false;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        sorted = false;
        for (int j = 0; j < arr.size() - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                sorted = true;
            }
        }
        if (!sorted) {
            break;
        }
    }
}

int main()
{
    std::vector<int> vec {5, 74, -1, 0, 655};
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    bubbleSort(vec);
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}