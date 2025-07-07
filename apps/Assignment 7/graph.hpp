//  Created by Logan Heck on 7/7/25.
// Graph.hpp
#pragma once
#include <vector>
#include <unordered_map>

class Graph {
public:
    virtual void addEdge(int u, int v) = 0;
    virtual bool isEdge(int u, int v) const = 0;
    virtual std::vector<int> getNeighbors(int u) const = 0;
    virtual ~Graph() = default;
};

class AdjacencyListGraph : public Graph {
    std::unordered_map<int, std::vector<int>> adj;
public:
    void addEdge(int u, int v) override;
    bool isEdge(int u, int v) const override;
    std::vector<int> getNeighbors(int u) const override;
};

class AdjacencyMatrixGraph : public Graph {
    std::vector<std::vector<bool>> matrix;
    int size;
public:
    AdjacencyMatrixGraph(int n);
    void addEdge(int u, int v) override;
    bool isEdge(int u, int v) const override;
    std::vector<int> getNeighbors(int u) const override;
};
