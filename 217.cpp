
#include "includes.h"

/**
 * @brief LeetCode Problem 217. Contains Duplicate
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 * @see https://leetcode.com/problems/contains-duplicate/
 * @date 6/14/2022
 */

class Solution {
 public:
  // Time Complexity: O(n)
  // Space Complexity: O(n) (set)
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int i : nums) {
      // attempt to insert if we fail we've already seen this number
      if (!seen.insert(i).second)
        return true;
    }

    // base case
    return false;
  }
};