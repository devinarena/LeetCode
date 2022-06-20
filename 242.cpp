
#include "includes.h"

/**
 * @brief LeetCode Problem 242. Valid Anagram
 *
 * Given two strings s and t, return true if t is an anagram of s, and
 * false otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 * @see https://leetcode.com/problems/valid-anagram/
 * @date 6/14/2022
 */

class Solution {
 public:
  // Time Complexity: O(m + n)
  // Space Complexity: O(26 or 1 lol) (array is constant size)
  bool isAnagram(string s, string t) {
    // can use one character array, increment for s, decrement for t
    vector<int> count(26, 0);

    // for each character in s, increment the count
    for (char c : s) {
      count[c - 'a']++;
    }

    // for each character in t, decrement the count
    for (char c : t) {
      count[c - 'a']--;
    }

    // if any of the counts are not 0, then the strings are not anagrams
    for (int i : count) {
      if (i != 0) {
        return false;
      }
    }

    // base case
    return true;
  }
};