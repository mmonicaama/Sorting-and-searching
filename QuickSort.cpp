#include <iostream>
#include <vector>

//Cormen implementation
int partition(std::vector<int>& arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}
  
int partition_first(std::vector<int>& arr, int start, int end)
{
    std::swap(arr[start], arr[end]);
    return partition(arr, start, end);
}

int partition_last(std::vector<int>& arr, int start, int end)
{
    return partition(arr, start, end);
}

void sortFirstMiddleLast(std::vector<int>& arr, int first, int mid, int last)
{
    if (arr[first] > arr[mid]) {
        std::swap(arr[first], arr[mid]);
    }
    if (arr[mid] > arr[last]) {
        std::swap(arr[mid], arr[last]);
    }
    if (arr[first] > arr[last]) {
        std::swap(arr[first], arr[last]);
    }
}

int partition_3median(std::vector<int>& arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    sortFirstMiddleLast(arr, start, mid, end);
    std::swap(arr[mid], arr[end]);
    return partition(arr, start, end);
}

void quickSort_first(std::vector<int>& arr, int start, int end)
{
    if (start < end) {
        int pivotIndex = partition_first(arr, start, end);
        quickSort_first(arr, start, pivotIndex - 1);
        quickSort_first(arr, pivotIndex + 1, end);
    }
}

void quickSort_last(std::vector<int>& arr, int start, int end)
{
    if (start < end) {
        int pivotIndex = partition_last(arr, start, end);
        quickSort_last(arr, start, pivotIndex - 1);
        quickSort_last(arr, pivotIndex + 1, end);
    }
}

void quickSort_3median(std::vector<int>& arr, int start, int end)
{
    if (start < end) {
        int pivotIndex = partition_3median(arr, start, end);
        quickSort_3median(arr, start, pivotIndex - 1);
        quickSort_3median(arr, pivotIndex + 1, end);
    }
}

int main()
{
    std::vector<int> vec {5, 74, -1, 0, 655};
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    quickSort_first(vec, 0, 4);
    std::cout << "Pivot as first:\n";
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    quickSort_last(vec, 0, 4);
    std::cout << "Pivot as last:\n";
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    quickSort_3median(vec, 0, 4);
    std::cout << "Pivot as median-of-3:\n";
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}