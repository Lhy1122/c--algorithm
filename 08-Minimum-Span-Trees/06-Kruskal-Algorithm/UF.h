#ifndef INC_06_KRUSKAL_ALGORITHM_UF_H
#define INC_06_KRUSKAL_ALGORITHM_UF_H

#include <iostream>
#include <cassert>

using namespace std;

class UnionFind{

private:
    
    int* rank;
    int* parent;
    int count;

public:
    
    UnionFind(int count){
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for( int i = 0 ; i < count ; i ++ ){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind(){
        delete[] parent;
        delete[] rank;
    }

    int find(int p){
        assert( p >= 0 && p < count );

        while( p != parent[p] ){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;

    }

    bool isConnected( int p , int q ){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        if( rank[pRoot] < rank[qRoot] ){
            parent[pRoot] = qRoot;
        }
        else if( rank[qRoot] < rank[pRoot]){
            parent[qRoot] = pRoot;
        }
        else{
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};

#endif