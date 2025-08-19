#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void dfs(const string& item,
         unordered_map<string, vector<string>>& graph,
         unordered_set<string>& visited,
         vector<string>& component) {
    visited.insert(item);
    component.push_back(item);

    for (const string& neighbor : graph[item]) {
        if (!visited.count(neighbor)) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

vector<string> largestItemAssociation(vector<vector<string>>& itemAssociation) {
    unordered_map<string, vector<string>> graph;

    // Step 1: Build the graph
    for (auto& pair : itemAssociation) {
        graph[pair[0]].push_back(pair[1]);
        graph[pair[1]].push_back(pair[0]);
    }

    unordered_set<string> visited;
    vector<string> largestGroup;

    // Step 2: Traverse all nodes using DFS
    for (const auto& entry : graph) {
        const string& item = entry.first;
        if (!visited.count(item)) {
            vector<string> component;
            dfs(item, graph, visited, component);
            sort(component.begin(), component.end());

            // Step 3: Compare sizes or lexicographic order
            if (component.size() > largestGroup.size() ||
               (component.size() == largestGroup.size() && component[0] < largestGroup[0])) {
                largestGroup = component;
            }
        }
    }

    return largestGroup;
}
