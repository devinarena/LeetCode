

#include "includes.h"

/**
 * @brief LeetCode Problem 128. Longest Consecutive Sequence
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 * @see https://leetcode.com/problems/longest-consecutive-sequence/
 * @date 6/15/2022
 */

class Solution {
 public:
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  int longestConsecutive(vector<int>& nums) {
    // use a set to avoid duplicates
    unordered_set<int> set;
    int ans = 0;

    for (int i : nums)
      set.insert(i);

    for (int i : set) {
      // smart sequence building, only start from elements that don't have a
      // predecessor in the set
      if (set.find(i - 1) != set.end())
        continue;

      // current best streak
      int curr = 1;
      // if the set has the next element in the sequence, increment the streak
      while (set.find(i + 1) != set.end()) {
        i++;
        curr++;
      }
      // highest streak so far
      ans = max(ans, curr);
    }

    return ans;
  }
};