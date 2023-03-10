#include <bits/stdc++.h>
using namespace std;

class Solution {
  void dfs(int node, vector<int> adj[], vector<int> &res,
           vector<int> &visited) {
    if (visited[node])
      return;
    visited[node] = true;
    res.push_back(node);
    for (int nbr : adj[node]) {
      dfs(nbr, adj, res, visited);
    }
  }

public:
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> res;
    vector<int> visited(V + 1, false);
    dfs(0, adj, res, visited);

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
