
#include "includes.h"

/**
 * @brief LeetCode Problem 238. Product of Array Except Self
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 * 
 * @see https://leetcode.com/problems/product-of-array-except-self/
 * @date 6/14/2022
 */

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // two pass the array, once to get the product of all numbers before
        // the current index, and once to get the product of all numbers after

        int fac = 1;
        vector<int> ans(nums.size(), 1);

        // get the product of all numbers before the current index
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = fac;
            fac *= nums[i];
        }

        fac = 1;

        // get the product of all numbers after the current index
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= fac;
            fac *= nums[i];
        }

        return ans;
    }
};