
#include "includes.h"

/**
 * @brief LeetCode Problem 167. Two Sum II - Input array is sorted
 *
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as
 * an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 * Your solution must use only constant extra space.
 *
 * @see https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * @date 6/16/2022
 */

class Solution {
 public:
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  vector<int> twoSum(vector<int>& numbers, int target) {
    // use two pointers to compare the left and right sides of the array
    int start = 0;
    int end = numbers.size() - 1;
    while (start < end) {
      // find the sum of the two numbers
      int curr = numbers[start] + numbers[end];
      // if the sum is equal to the target, return the indices (one-based)
      if (curr == target)
        return {start + 1, end + 1};
      // if the sum is less than the target, move the left pointer up
      else if (curr < target)
        start++;
      // if the sum is greater than the target, move the right pointer down
      else
        end--;
    }

    // unreachable
    return {};
  }
};