#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

class Solution {
  int height(Node *root) {
    if (root == nullptr)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }

public:
  int diameter(Node *root) {
    if (root == nullptr)
      return 0;
    return max(diameter(root->left),
               1 + height(root->left) + height(root->right));
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
