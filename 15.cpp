
#include "includes.h"

/**
 * @brief LeetCode Problem 15. 3Sum
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 */

class Solution {
 public:
  // Time Complexity: O(n^2)
  // Space Complexity: O(n)
  vector<vector<int>> threeSum(vector<int>& nums) {
    // can't have a triplet without three numbers
    if (nums.size() < 3)
      return {};

    // sort the array to prevent duplicates and use two pointers to compare
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    // -4 -1 -1 0 1 2

    for (int i = 0; i < nums.size() - 2; i++) {
      // skip duplicates
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      if (i > nums.size() - 2)
        break;
      // use two pointers to find the other two numbers
      int start = i + 1;
      int end = nums.size() - 1;
      while (start < end) {
        int sum = nums[i] + nums[start] + nums[end];
        // if the sum is zero, we've found a triplet
        if (sum == 0)
          ans.push_back({nums[i], nums[start++], nums[end--]});
        // if the sum is less than zero, we need to look for a larger number
        else if (sum < 0)
          start++;
        // if the sum is greater than zero, we need to look for a smaller number
        else
          end--;
        // skip duplicates
        while (start > i + 1 && start < end && nums[start] == nums[start - 1])
          start++;
        while (end < nums.size() - 1 && start < end &&
               nums[end] == nums[end + 1])
          end--;
      }
    }

    return ans;
  }
};