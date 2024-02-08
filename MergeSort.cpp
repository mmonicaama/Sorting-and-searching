#include <iostream>
#include <vector>

void merge (std::vector<int>& arr, int first, int mid, int last) 
{
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    std::vector<int> tmp(arr.size());

    int index = first1;
    while((first1 <= last1) && (first2 <= last2)) {
        if (arr[first1] <= arr[first2]) {
            tmp[index] = arr[first1];
            ++first1;
        } else {
            tmp[index] = arr[first2];
            ++first2;
        }
        ++index;
    }

    while (first1 <= last1) {
        tmp[index] = arr[first1];
        ++first1;
        ++index;
    }
    while (first2 <= last2) {
        tmp[index] = arr[first2];
        ++first2;
        ++index;
    }

    for (index = first; index <= last; ++index) {
        arr[index] = tmp[index];
    }
}

void mergeSort(std::vector<int>& arr, int first, int last)
{
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main()
{
    std::vector<int> vec {5, 74, -1, 0, 655};
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    mergeSort(vec, 0, 4);
    for (const int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}