//
//  graph.cpp
//  Assignment 7
//
//  Created by Logan Heck on 7/7/25.
#include "Graph.hpp"

void AdjacencyListGraph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}

bool AdjacencyListGraph::isEdge(int u, int v) const {
    auto it = adj.find(u);
    if (it != adj.end()) {
        for (int neighbor : it->second)
            if (neighbor == v) return true;
    }
    return false;
}

std::vector<int> AdjacencyListGraph::getNeighbors(int u) const {
    auto it = adj.find(u);
    if (it != adj.end()) return it->second;
    return {};
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int n) : size(n), matrix(n, std::vector<bool>(n, false)) {}

void AdjacencyMatrixGraph::addEdge(int u, int v) {
    matrix[u][v] = true;
    matrix[v][u] = true; // undirected
}

bool AdjacencyMatrixGraph::isEdge(int u, int v) const {
    return matrix[u][v];
}

std::vector<int> AdjacencyMatrixGraph::getNeighbors(int u) const {
    std::vector<int> neighbors;
    for (int i = 0; i < size; ++i)
        if (matrix[u][i]) neighbors.push_back(i);
    return neighbors;
}
