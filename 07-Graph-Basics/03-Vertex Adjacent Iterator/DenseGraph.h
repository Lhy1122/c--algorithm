#ifndef INC_03_VERTEX_ADJACENT_ITERATOR_DENSEGRAPH_H
#define INC_03_VERTEX_ADJACENT_ITERATOR_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph{

private:
    int n, m;
    bool directed;
    vector<vector<bool>> g;

public:
    // 构造函数
    DenseGraph( int n , bool directed ){
        assert( n >= 0 );
        this->n = n;
        this->m = 0;    
        this->directed = directed;
        
        g = vector<vector<bool>>(n, vector<bool>(n, false));
    }

    ~DenseGraph(){ }

    int V(){ return n;}
    int E(){ return m;}

    void addEdge( int v , int w ){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        if( hasEdge( v , w ) )
            return;

        g[v][w] = true;
        if( !directed )
            g[w][v] = true;

        m ++;
    }

    bool hasEdge( int v , int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        return g[v][w];
    }

    class adjIterator{
    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        
        adjIterator(DenseGraph &graph, int v): G(graph){
            assert( v >= 0 && v < G.n );
            this->v = v;
            this->index = -1;
        }

        ~adjIterator(){}

        int begin(){

            index = -1;
            return next();
        }

        int next(){

            for( index += 1 ; index < G.V() ; index ++ )
                if( G.g[v][index] )
                    return index;
            
            return -1;
        }

        bool end(){
            return index >= G.V();
        }
    };
};

#endif 