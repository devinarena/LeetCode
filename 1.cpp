
#include "includes.h"

/**
 * @brief LeetCode Problem 1. Two Sum
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * @see https://leetcode.com/problems/two-sum/
 * @date 6/14/2022
 */

class Solution {
 public:
  // Time Complexity: O(n)
  // Space Complexity: O(n) (for the map)
  vector<int> twoSum(vector<int>& nums, int target) {
    // store complements in map
    unordered_map<int, int> comp;

    for (int i = 0; i < nums.size(); i++) {
      // if the complement map contains this number, we found a pair
      if (comp.find(nums[i]) != comp.end()) {
        // return the indices of the pair
        return {comp[nums[i]], i};
      }
      // store the complement's index (target - nums[i]) in a map
      comp[target - nums[i]] = i;
    }

    // base case
    return {};
  }
};