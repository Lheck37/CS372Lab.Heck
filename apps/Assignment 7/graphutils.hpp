//
//  graphutils.hpp
//  Assignment 7
//
//  Created by Logan Heck on 7/7/25.
#pragma once
#include "Graph.hpp"
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

bool isSimpleCycle(const Graph& g, const std::vector<int>& path) {
    if (path.size() < 3 || path.front() != path.back()) return false;

    std::unordered_set<int> visited;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        if (!g.isEdge(path[i], path[i+1])) return false;
        if (visited.count(path[i])) return false;
        visited.insert(path[i]);
    }
    return true;
}

bool findKevinBaconPath(const Graph& g, int start, int kevinID, std::vector<int>& path) {
    std::queue<int> q;
    std::unordered_map<int, int> prev;
    std::unordered_set<int> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int current = q.front(); q.pop();
        if (current == kevinID) break;
        for (int neighbor : g.getNeighbors(current)) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                prev[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if (!visited.count(kevinID)) return false;

    for (int at = kevinID; at != start; at = prev[at])
        path.push_back(at);
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return true;
}
