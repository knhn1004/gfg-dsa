#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

vector<int> reverseLevelOrder(Node *root) {
  vector<int> res;
  if (root == nullptr) {
    return res;
  }
  queue<Node *> q;
  q.push(root);
  Node *cur;
  while (!q.empty()) {
    cur = q.front();
    res.insert(res.begin(), cur->data);
    q.pop();
    if (cur->right)
      q.push(cur->right);
    if (cur->left)
      q.push(cur->left);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
