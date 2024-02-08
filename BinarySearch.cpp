#include <iostream>
#include <vector>

int binarySearch_iter(const std::vector<int>& arr, int low, int high, int key)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > key) {
            high = mid - 1 ;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binarySearch_recursive(const std::vector<int>&arr, int low, int high, int key) 
{
    if (high < low) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] > key) {
        return binarySearch_recursive(arr, low, mid - 1, key);
    } else if (arr[mid] < key) {
        return binarySearch_recursive(arr, mid + 1, high, key);
    } else {
        return mid;
    }
}

int main()
{
    std::vector<int> vec {1, 33, 56, 100, 738};
    std::cout << "100 is found at index: " << binarySearch_iter(vec, 0, 4, 100) << std::endl;
    std::cout << "55 is found at index: " << binarySearch_recursive(vec, 0, 4, 55) << std::endl;
    return 0;
}