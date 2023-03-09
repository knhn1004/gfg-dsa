#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  vector<int> levelOrder(Node *root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    queue<Node *> q;
    q.push(root);
    Node *cur;
    while (!q.empty()) {
      cur = q.front();
      res.push_back(cur->data);
      q.pop();
      if (cur->left)
        q.push(cur->left);
      if (cur->right)
        q.push(cur->right);
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
