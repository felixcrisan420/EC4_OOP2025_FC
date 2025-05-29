//
// Created by felix on 5/22/2025.
//


#pragma once
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

template<typename T>
class Graph {
private:
    unordered_map<T, vector<T>> adj;

public:
    void addEdge(const T& u, const T& v) {
        // Theta(1)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<T> getNeighbors(const T& node) const {
        // Theta(1)
        auto it = adj.find(node);
        if (it != adj.end())
            return it->second;
        return {};
    }

    vector<T> bfs(const T& start, const T& target) {
        // O(v log v + e)
        // Easier with BFS than A*
        map<T, T> parent;
        set<T> visited;
        queue<T> q;

        q.push(start);
        visited.insert(start);
        parent[start] = T();

        while (!q.empty()) {
            T current = q.front(); q.pop();
            if (current == target)
                break;

            for (const T& neighbor : getNeighbors(current)) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }

        vector<T> path;
        T step = target;
        if (parent.find(step) == parent.end())
            return {};

        while (step != T()) {
            path.push_back(step);
            step = parent[step];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
