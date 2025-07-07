// main.cpp
#include "Graph.hpp"
#include "GraphUtils.hpp"
#include <iostream>

void testWithAdjacencyList() {
    AdjacencyListGraph g;

    // IDs: 0 = You, 19 = Kevin Bacon
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.addEdge(5, 19);
    g.addEdge(3, 4); // disconnected group

    std::vector<int> path;
    std::cout << "[Adjacency List Graph Test]\n";
    if (findKevinBaconPath(g, 0, 19, path)) {
        std::cout << "Connected to Kevin Bacon! Path: ";
        for (int id : path) std::cout << id << " ";
        std::cout << "\nKevin Bacon number: " << path.size() - 1 << "\n";
    } else {
        std::cout << "Not connected to Kevin Bacon.\n";
    }

    std::vector<int> cycle = {1, 2, 5, 1};
    std::cout << (isSimpleCycle(g, cycle) ? "Valid simple cycle\n" : "Not a simple cycle\n");
}

void testWithAdjacencyMatrix() {
    AdjacencyMatrixGraph g(20);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.addEdge(5, 19);
    g.addEdge(3, 4); // disconnected group

    std::vector<int> path;
    std::cout << "\n[Adjacency Matrix Graph Test]\n";
    if (findKevinBaconPath(g, 0, 19, path)) {
        std::cout << "Connected to Kevin Bacon! Path: ";
        for (int id : path) std::cout << id << " ";
        std::cout << "\nKevin Bacon number: " << path.size() - 1 << "\n";
    } else {
        std::cout << "Not connected to Kevin Bacon.\n";
    }

    std::vector<int> cycle = {1, 2, 5, 1};
    std::cout << (isSimpleCycle(g, cycle) ? "Valid simple cycle\n" : "Not a simple cycle\n");
}

int main() {
    testWithAdjacencyList();
    testWithAdjacencyMatrix();
    return 0;
}
