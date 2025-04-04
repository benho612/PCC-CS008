#include <iostream>
#include "Graph.h"
int main()
{
    Graph<int> g;
    for(int i=0; i<7; i++)
    {
        g.add_vertex(i);
    }
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(2, 0);
    g.add_edge(3, 5);
    g.add_edge(3, 6);
    g.add_edge(3, 0);
    g.add_edge(6, 1);
    std::cout << "\n############ Breadth First Paths ############\n";
    for (int j = 0; j < g.size(); ++j)
    {
        std::cout << "Starting From Vertex " << j << ": ";
        g.breadth_first(j);
        std::cout << std::endl;
    }
    std::cout << "\n\n############ Depth First Paths ############\n";
    for (int j = 0; j < g.size(); ++j)
    {
        std::cout << "Starting From Vertex " << j << ": ";
        g.depth_first(j);
        std::cout << std::endl;
    }
    return 0;
}
