#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap{
private:
    T* data;
    int count;

public:
    MaxHeap(int capacity){
        data = new T[capacity + 1];
        count = 0;
    }

    ~MaxHeap(){
        delete [] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
};



int main(){

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.size()<<endl;

    return 0;
}