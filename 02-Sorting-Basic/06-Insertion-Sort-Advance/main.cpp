#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for(int i = 1; i < n; i++){
        //寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; //保存元素e应该插入的位置
        for(int j = i; j > 0 && arr[j - 1] > e; j--){
            
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
    return;
}

int main(){

    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n );

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}