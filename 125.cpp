
#include "includes.h"

/**
 * @brief LeetCode Problem 125. Valid Palindrome
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * @see https://leetcode.com/problems/valid-palindrome/
 * @date 6/15/2022
 */

class Solution {
 public:
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  bool isPalindrome(string s) {
    // use two pointers to compare the left and right sides of the string
    int start = 0;
    int end = s.size() - 1;

    while (start <= end) {
      // ignore non-alphanumeric characters for left
      while (start < s.size() && !isalnum(s[start]))
        start++;
      // ignore non-alphanumeric characters for right
      while (end > 0 && !isalnum(s[end]))
        end--;
      // prevent out of bounds
      if (end < start)
        break;
      // compare the left and right sides of the string
      if (tolower(s[start++]) != tolower(s[end--]))
        return false;
    }

    // base case, we've made it through the string without fail
    return true;
  }
};