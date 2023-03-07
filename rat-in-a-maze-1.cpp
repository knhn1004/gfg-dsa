#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0};
int dy[] = {0, 1};
string dirs[] = {"R", "D"};

class Solution {
  void bt(vector<vector<int>> &m, int r, int c, vector<string> &res,
          string cur = "") {
    int n = m.size();
    if (r == n - 1 && c == n - 1) {
      res.push_back(cur);
      return;
    }

    for (int k = 0; k < 2; k++) {
      int nr = r + dx[k], nc = c + dy[k];
      if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
        if (m[nr][nc] == 1) {
          m[nr][nc] = 0;
          bt(m, nr, nc, res, cur + dirs[k]);
          m[nr][nc] = 1;
        }
      }
    }
  }

public:
  vector<string> findPath(vector<vector<int>> &m, int n) {
    // NxN matrix
    // N-1 right's & N-1 down's
    // original problem translates to
    // generate permuations of N-1 right's & N-1 down's
    // backtracking (iff the cell is route (can go))
    vector<string> res;
    bt(m, n, n, res);
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<vector<int>> maze = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1},
  };
  Solution *sl = new Solution();
  for (string s : sl->findPath(maze, maze.size())) {
    cout << s << endl;
  }
  delete sl;

  return 0;
}
