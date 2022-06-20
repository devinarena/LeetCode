
#include "includes.h"

/**
 * @brief LeetCode Problem 42. Trapping Rain Water
 * 
 * Given n non-negative integers representing an elevation map where the width of
 * each bar is 1, compute how much water it is able to trap after raining.
 * 
 * @see https://leetcode.com/problems/trapping-rain-water/
 * @date 6/16/2022
 */

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int trap(vector<int>& height) {
        // not possible to trap water if there are less than 3 bars
        if (height.size() < 3) return 0;

        // track the max height of the left and right bars
        int left = 0;
        int right = height.size() - 1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;

        // use two pointers to track the left and right endpoints of the container
        while (left < right) {
            // if left is smaller than right, its our limiting bar
            if (height[left] < height[right]) {
                // update the max height of the left bar
                if (lmax < height[left])
                    lmax = height[left];
                // calculate how much rainwater we trap
                else
                    ans += lmax - height[left];
                left++;
            } else {
                // update the max height of the right bar
                if (rmax < height[right])
                    rmax = height[right];
                // calculate how much rainwater we trap
                else
                    ans += rmax - height[right];
                right--;
            }
        }

        return ans;
    }
};