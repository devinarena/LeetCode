
#include "includes.h"

/**
 * @brief LeetCode Problem 121. Best Time to Buy and Sell Stock
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the ith day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 * @see https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @date 6/16/2022
 */

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int maxProfit(vector<int>& prices) {
        // track the current cheapest stock
        int cmin = prices[0];
        // track the current highest profit
        int cmax = 0;

        for (int i = 1; i < prices.size(); i++) {
            // update the current highest profit
            cmax = max(cmax, prices[i] - cmin);
            // update the current day to buy
            cmin = min(cmin, prices[i]);
        }

        return cmax;
    }
};