#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template<typename T>
class IndexMaxHeap{
private:
    T* data;
    int* indexes;
    int count;
    int capacity;

    void shiftUp(int k){
        while(k > 1 && data[indexes[k / 2]] < data[indexes[k]]){
            swap(indexes[k / 2] , indexes[k]);
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
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity){
        data = new T[capacity + 1];
        indexes = new int[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    ~MaxHeap(){
        delete [] data;
        delete [] indexes;
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

        i += 1;
        data[i] = t;
        indexes[count + 1] = i;
        count ++;
        shiftUp(count);
    }

    T extractMax(){
        assert(count > 0);

        T ret = data[indexes[1]];

        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex(){
        assert(count > 0);

        int ret = indexes[1] - 1;

        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }

    T getT(int i){
        return data[i + 1];
    }

    void change(int i, T newT){
        i += 1;
        data[i] = newT;

        for(int j = 1; j <= count; j++)
            if(indexes[j] == i){
                shiftUp(j);
                shiftDown(j);
                return;
            }
    }

};