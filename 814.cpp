
#include "includes.h"

/**
 * @brief LeetCode Problem 814. Binary Tree Pruning
 *
 * Given the root of a binary tree, return the same tree where every subtree (of
 * the given tree) not containing a 1 has been removed.
 *
 * A subtree of a node node is node plus every node that is a descendant of
 * node.
 *
 * @see https://leetcode.com/problems/binary-tree-pruning/
 * @date 6/14/2022
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
 // Use a helper function to check if a node has a one in its subtree
 // if it does, return it, otherwise return null
 // use the return value to modify the tree in place
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  TreeNode* pruneTree(TreeNode* root) {
    // if there is no one, return null
    if (!hasOne(root))
      return NULL;
    // modify the tree in place (or do nothing if theres a one)
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    // return the root if there is a one
    return root;
  }

  bool hasOne(TreeNode* root) {
    if (root == NULL)
      return false;
    if (root->val == 1)
      return true;
    return hasOne(root->left) || hasOne(root->right);
  }
};