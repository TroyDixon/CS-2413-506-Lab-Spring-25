#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool mirrorCheck(struct TreeNode *tree1, struct TreeNode *tree2) {
  if (tree1 == NULL && tree2 == NULL) {
    return true;
  }
  if (tree1 == NULL || tree2 == NULL) {
    return false;
  }
  if (tree1->val != tree2->val) {
    return false;
  }
  return mirrorCheck(tree1->left, tree2->right) &&
         mirrorCheck(tree1->right, tree2->left);
}
bool isSymmetric(struct TreeNode *root) {
  if (root == NULL) {
    return true;
  }
  return mirrorCheck(root->left, root->right);
}
