/*
 * @Author: Lhy1122 1319628965@qq.com
 * @Date: 2022-08-02 21:26:13
 * @LastEditors: Lhy1122 1319628965@qq.com
 * @LastEditTime: 2022-08-02 21:26:54
 * @FilePath: \c++-algorithm\07-Graph-Basics\02-Graph-Representation\DenseGraph.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H
#define INC_02_GRAPH_REPRESENTATION_DENSEGRAPH_H

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
};

#endif