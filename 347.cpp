
#include "includes.h"

/**
 * @brief LeetCode Problem 347. Top K Frequent Elements
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 * @see https://leetcode.com/problems/
 * @date 6/14/2022
 */

class Solution {
  // Time Complexity: O(n)
  // Space Complexity: O(n)
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // track frequencies of each number
    unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }

    // sort pairs by frequency (second element)
    auto comp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second < b.second;
    };

    // create a max heap of the top k frequent numbers
    vector<pair<int, int>> heap;
    for (auto& p : freq) {
      heap.push_back(p);
    }
    make_heap(heap.begin(), heap.end(), comp);

    // extract the top k frequent numbers
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      pop_heap(heap.begin(), heap.end(), comp);
      ans.push_back(heap.back().first);
      heap.pop_back();
    }

    return ans;
  }
};