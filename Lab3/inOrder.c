#include <stdio.h>
#include <stdlib.h>
// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Note: The returned array must be malloced, assume caller calls free().
void inOrder(struct TreeNode *root, int *arr, int *returnSize) {
  if (root != NULL) {
    inOrder(root->left, arr, returnSize);
    arr[(*returnSize)++] = root->val;
    inOrder(root->right, arr, returnSize);
  }
}
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
  int *temp = (int *)malloc(100 * sizeof(int));
  int x = 0;
  *returnSize = x;
  inOrder(root, temp, returnSize);
  return temp;
}
