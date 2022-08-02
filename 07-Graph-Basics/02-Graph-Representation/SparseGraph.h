#ifndef INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SparseGraph{

private:
    int n, m;
    bool directed;
    vector<vector<int>> g;

public:
    
    SparseGraph( int n , bool directed ){
        assert( n >= 0 );
        this->n = n;
        this->m = 0;
        this->directed = directed;
        
        g = vector<vector<int>>(n, vector<int>());
    }

    ~SparseGraph(){ }

    int V(){ return n;}
    int E(){ return m;}

    void addEdge( int v, int w ){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        g[v].push_back(w);
        if( v != w && !directed )
            g[w].push_back(v);

        m ++;
    }

    bool hasEdge( int v , int w ){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        for( int i = 0 ; i < g[v].size() ; i ++ )
            if( g[v][i] == w )
                return true;
        return false;
    }
};

#endif