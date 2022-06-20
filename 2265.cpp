
#include "includes.h"

/**
 * @brief LeetCode Problem 2265. Count Nodes Equal to Average of Subtree
 * Given the root of a binary tree, return the number of nodes where the value
 * of the node is equal to the average of the values in its subtree.
 *
 * Note:
 * The average of n elements is the sum of the n elements divided by n and
 * rounded down to the nearest integer. A subtree of root is a tree consisting
 * of root and all of its descendants.
 * 
 * @see https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
 * @date 6/14/2022
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int ans;

  // Time Complexity: O(n)
  // Space Complexity: O(n)
  int averageOfSubtree(TreeNode* root) {
    avg(root);
    return ans;
  }

  // Trick is to return the number of nodes in the tree
  // and modify nodes of the tree to store the sum of the subtree
  // use that to find the average and see if we need to increment answer
  int avg(TreeNode* root) {
    if (!root)
      return 0;

    // get number of nodes in left and right subtrees (also update their values)
    int left = avg(root->left);
    int right = avg(root->right);

    //  modify nodes of the tree to store the sum of the subtree
    int prev = root->val;
    if (root->left)
      root->val += root->left->val;
    if (root->right)
      root->val += root->right->val;

    // use that to find the average and see if we need to increment answer
    if (prev == root->val / (left + right + 1))
      ans++;

    // return the number of nodes in the tree
    return 1 + left + right;
  }
};