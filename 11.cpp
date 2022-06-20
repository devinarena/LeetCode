
#include "includes.h"

/**
 * @brief LeetCode Problem 11. Container With Most Water
 *
 * You are given an integer array height of length n. There are n vertical lines
 * drawn such that the two endpoints of the ith line are (i, 0) and (i,
 * height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 *
 * @see https://leetcode.com/problems/container-with-most-water/
 * @date 6/16/2022
 */

class Solution {
 public:
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  int maxArea(vector<int>& height) {
    // track the max area found
    int cmax = 0;
    // use two pointers to track the left and right endpoints of the container
    int start = 0;
    int end = height.size() - 1;

    while (start < end) {
      // calculate the area of the container
      int area = (end - start) * min(height[start], height[end]);
      // update the max area found
      cmax = max(cmax, area);

      // move the left pointer to the right if the height of the left endpoint
      // is less than the height of the right endpoint
      if (height[start] < height[end])
        start++;
      // move the right pointer to the left if the height of the right endpoint
      // is less than the height of the left endpoint
      else
        end--;
    }

    return cmax;
  }
};