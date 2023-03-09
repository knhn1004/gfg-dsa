#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

class Solution {
public:
  int height(struct Node *root) {
    if (root == nullptr)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
