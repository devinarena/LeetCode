
#include "includes.h"

/**
 * @brief LeetCode Problem 3. Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * @see
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @date 6/16/2022
 */

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0)
      return 0;

    unordered_set<char> set;
    int left = 0;
    int right = 1;
    int longest = 1;

    set.insert(s[0]);

    while (right < s.size()) {
        if (set.insert(s[right]).second) {
            right++;
            longest = max(longest, right - left);
        } else {
            set.erase(s[left]);
            left++;
        }
    }

    return longest;
  }
};