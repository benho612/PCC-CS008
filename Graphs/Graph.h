//
// Created by hoben on 11/28/2023.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <cstdlib>
#include <set>
#include <queue>
#include <iostream>
template<class T>
class Graph
{
public:
    Graph();
    static const std::size_t MAX = 20;
    void add_vertex(const T& label);
    void add_edge(std::size_t source, std::size_t target);
    T& operator[](std::size_t vertex);
    T operator[](std::size_t vertex) const;
    std::set<std::size_t> neighbors(std::size_t vertex) const;
    std::size_t size() const;
    bool is_edge(std::size_t source, std::size_t target) const;
    void breadth_first();
    void breadth_first(std::size_t start);
    void depth_first();
    void depth_first(size_t vertex);
private:
    bool edges[MAX][MAX];
    //std::vector<std::vector<bool>> edges;
    T labels[MAX];
    std::size_t many_vertices = 0;
    void depth_first(bool marked[], std::size_t vertex);
    void remove_edge(size_t source, size_t target);
};



#include "Graph.cpp"

#endif //GRAPH_GRAPH_H

