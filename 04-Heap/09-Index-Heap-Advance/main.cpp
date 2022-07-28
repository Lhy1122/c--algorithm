#include <iostream>
#include <cassert>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
class IndexMaxHeap{
private:
    T* data;
    int* indexes;
    int* reverse;
    int count;
    int capacity;

    void shiftUp(int k){
        while(k > 1 && data[indexes[k / 2]] < data[indexes[k]]){
            swap(indexes[k / 2] , indexes[k]);
            reverse[indexes[k / 2]] = k / 2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k){

        while(2*k <= count){
            int j = 2*k;
            if(j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]]){
                j += 1;
            }

            if(data[indexes[k]] >= data[indexes[j]])
                break;

            swap(indexes[k] , indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity){
        data = new T[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for(int i = 0; i <= capacity; i++){
            reverse[i] = 0;
        }

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }


    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(int i, T t){

        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);
        assert(!contain(i));

        i += 1;
        data[i] = t;
        indexes[count + 1] = i;
        reverse[i] = count + 1;
        count ++;
        shiftUp(count);
    }

    T extractMax(){
        assert(count > 0);

        T ret = data[indexes[1]];

        swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        count--;
        if(count){
            reverse[indexes[1]] = 1;
            shiftDown(1);
        }
        
        return ret;
    }

    int extractMaxIndex(){
        assert(count > 0);

        int ret = indexes[1] - 1;

        swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        count--;

        if(count){
            reverse[indexes[1]] = 1;
            shiftDown(1);
        }
        
        return ret;
    }

    T getMax(){
        assert(count > 0);
        return data[indexes[1]];
    }

    int getMaxIndex(){
        assert(count > 0);
        return indexes[1] - 1;
    }

    bool contain(int i){
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return reverse[i + 1] != 0;
    }

    T getT(int i){
        return data[i + 1];
    }

    void change(int i, T newT){

        assert(contain(i));
        i += 1;
        data[i] = newT;

        shiftUp(reverse[i]);
        shiftDown(reverse[i]);
    }

    bool testIndexesAndReverseIndexes(){

        int *copyIndexes = new int[count+1];
        int *copyReverseIndexes = new int[count+1];

        for( int i = 0 ; i <= count ; i ++ ){
            copyIndexes[i] = indexes[i];
            copyReverseIndexes[i] = reverse[i];
        }

        copyIndexes[0] = copyReverseIndexes[0] = 0;
        std::sort(copyIndexes, copyIndexes + count + 1);
        std::sort(copyReverseIndexes, copyReverseIndexes + count + 1);

        bool res = true;
        for( int i = 1 ; i <= count ; i ++ )
            if( copyIndexes[i-1] + 1 != copyIndexes[i] ||
                    copyReverseIndexes[i-1] + 1 != copyReverseIndexes[i] ){
                res = false;
                break;
            }

        delete[] copyIndexes;
        delete[] copyReverseIndexes;

        if( !res ){
            cout<<"Error!"<<endl;
            return false;
        }

        for( int i = 1 ; i <= count ; i ++ )
            if( reverse[ indexes[i] ] != i ){
                cout<<"Error 2"<<endl;
                return false;
            }

        return true;
    }

};

template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n){

    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMaxHeap.insert( i , arr[i] );
    assert( indexMaxHeap.testIndexesAndReverseIndexes() );

    for( int i = n-1 ; i >= 0 ; i -- )
        arr[i] = indexMaxHeap.extractMax();
}

int main() {

    int n = 1000000;

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);
    delete[] arr;

    return 0;
}