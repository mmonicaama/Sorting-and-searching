#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) 
{
    auto minElement = std::min_element(arr.begin(), arr.end());
    auto maxElement = std::max_element(arr.begin(), arr.end());

    if (minElement == arr.end() || maxElement == arr.end()) {
        // Vector is empty, nothing to sort
        return;
    }

    int minVal = *minElement;
    int maxVal = *maxElement;

    const int count_size = maxVal - minVal + 1;
    std::vector<int> count(count_size, 0);
    std::vector<int> output(arr.size());

    for (const int elem : arr) {
        ++count[elem - minVal];
    }

    for (int i = 1; i < count_size; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        --count[arr[i] - minVal];
    }

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}

int main()
{
    std::vector<int> vec {5, 74, -1, 0, 655};
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    countingSort(vec);
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}