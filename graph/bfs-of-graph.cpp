#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // BFS starting from 0
    // V - max number
    // numbers from 0 - V
    vector<bool> visited(V + 1, false);
    vector<int> res;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int cur;
    while (!q.empty()) {
      cur = q.front();
      q.pop();
      res.push_back(cur);
      for (int nbr : adj[cur]) {
        if (!visited[nbr]) {
          visited[nbr] = true;
          q.push(nbr);
        }
      }
    }

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
