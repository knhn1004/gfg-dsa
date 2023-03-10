#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool dfs(int node, vector<int> adj[], vector<int> &visited,
           unordered_set<int> &in_stack) {
    visited[node] = true;
    in_stack.insert(node);
    for (int nbr : adj[node]) {
      if (in_stack.find(nbr) != in_stack.end())
        return true;
      if (!visited[nbr]) {
        if (dfs(nbr, adj, visited, in_stack))
          return true;
      }
    }

    in_stack.erase(node);
    return false;
  }

public:
  bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, false);
    unordered_set<int> in_stack;

    for (int i = 0; i < V; i++) {
      if (!visited[i] && dfs(i, adj, visited, in_stack)) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
