#include <bits/stdc++.h>
using namespace std;

class Solution {
  const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
  const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

public:
  int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos,
                           int N) {
    queue<pair<int, int>> q;
    q.push({KnightPos[0] - 1, KnightPos[1] - 1});

    vector<vector<bool>> visited(N, vector<bool>(N, false)); // visited array
    visited[KnightPos[0] - 1][KnightPos[1] - 1] =
        true; // mark starting cell as visited

    int level = 0, levelSize = 1, nextLevelSize = 0;
    while (!q.empty()) {
      for (int i = 0; i < levelSize; i++) {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (x == TargetPos[0] - 1 && y == TargetPos[1] - 1)
          return level; // found
        for (int k = 0; k < 8; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
              !visited[nx][ny]) { // check if cell is not visited
            q.push({nx, ny});
            visited[nx][ny] = true; // mark cell as visited
            nextLevelSize++;
          }
        }
      }

      levelSize = nextLevelSize;
      nextLevelSize = 0;
      level++;
    }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
