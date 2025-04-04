//
// Created by hoben on 11/28/2023.
//

#ifndef GRAPHS_GRAPH_CPP
#define GRAPHS_GRAPH_CPP

#include "Graph.h"

template<class T>
void Graph<T>::add_vertex(const T &label) {
    if (many_vertices < MAX) {
        labels[many_vertices] = label;
        many_vertices++;
    }
}

template<class T>
void Graph<T>::add_edge(std::size_t source, std::size_t target) {
    edges[source][target] = true;
}

template<class T>
T &Graph<T>::operator[](std::size_t vertex) {
    return labels[vertex];
}

template<class T>
T Graph<T>::operator[](std::size_t vertex) const {
    return labels[vertex];
}

template<class T>
std::set<std::size_t> Graph<T>::neighbors(std::size_t vertex) const {
    std::set<std::size_t> result;
    if (vertex < many_vertices) {
        for (std::size_t i = 0; i < many_vertices; ++i) {
            if (edges[vertex][i]) {
                result.insert(i);
            }
        }
        return result;
    }
}

template<class T>
std::size_t Graph<T>::size() const {
    return many_vertices;
}

template<class T>
bool Graph<T>::is_edge(std::size_t source, std::size_t target) const {
    return edges[source][target];
}

template<class T>
void Graph<T>::remove_edge(size_t source, size_t target) {
    edges[source][target] = false;
}


template<class T>
void Graph<T>::breadth_first() {
    std::queue<std::size_t> q;
    bool visited[MAX] = {false};

    for (std::size_t i = 0; i < many_vertices; ++i) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                std::size_t current = q.front();
                q.pop();
                std::cout << labels[current] << " ";

                for (std::size_t j = 0; j < many_vertices; ++j) {
                    if (edges[current][j] && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}

template<class T>
void Graph<T>::breadth_first(std::size_t start) {
    if (start < many_vertices) {
        std::queue<std::size_t> q;
        bool visited[MAX] = {false};

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            std::size_t current = q.front();
            q.pop();
            std::cout << labels[current] << " ";

            for (std::size_t j = 0; j < many_vertices; ++j) {
                if (edges[current][j] && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Error: Invalid starting vertex index." << std::endl;
    }
}

template<class T>
void Graph<T>::depth_first() {
    bool visited[MAX] = {false};
    for (std::size_t i = 0; i < many_vertices; ++i) {
        if (!visited[i]) {
            depth_first(visited, i);
        }
    }
    std::cout << std::endl;
}

template<class T>
void Graph<T>::depth_first(size_t vertex) {
    if (vertex < many_vertices) {
        bool visited[MAX] = {false};
        depth_first(visited, vertex);
        std::cout << std::endl;
    } else {
        std::cerr << "Error: Invalid starting vertex index." << std::endl;
    }
}

template<class T>
void Graph<T>::depth_first(bool *marked, std::size_t vertex) {
    marked[vertex] = true;
    std::cout << labels[vertex] << " ";

    for (std::size_t i = 0; i < many_vertices; ++i) {
        if (edges[vertex][i] && !marked[i]) {
            depth_first(marked, i);
        }
    }
}

template<class T>
Graph<T>::Graph() {

}

#endif //GRAPH_GRAPH_CPP

