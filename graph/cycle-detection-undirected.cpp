#include <bits/stdc++.h>
using namespace std;

/* class Solution {
  bool dfs(int node, vector<int> adj[], int parent, vector<bool> &visited) {
    if (visited[node])
      return true;
    visited[node] = true;
    for (int nbr : adj[node]) {
      if (nbr == parent)
        continue;
      if (dfs(nbr, adj, parent, visited))
        return true;
    }
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[]) {
    // nodes from 0-V-1
    vector<bool> visited(V, false);
    return dfs(0, adj, -1, visited);
  }
}; */
class Solution {
  bool dfs(int node, vector<int> adj[], int parent, vector<bool> &visited) {
    visited[node] = true;
    for (int nbr : adj[node]) {
      if (visited[nbr] && nbr != parent) // cycle detected
        return true;
      if (!visited[nbr] && dfs(nbr, adj, node, visited))
        return true;
    }
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
      if (!visited[i] && dfs(i, adj, -1, visited))
        return true;
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
