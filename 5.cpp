

#include "includes.h"

/**
 * @brief LeetCode Problem 5. Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s.
 *
 * @see https://leetcode.com/problems/longest-palindromic-substring/
 * @date 6/16/2022
 */

class Solution {
 public:
 // Time Complexity: O(n^2)
 // Space Complexity: O(1)
  string longestPalindrome(string s) {
    // strings of length 1 or less are palindromes
    if (s.size() <= 1) return s;

    // track the longest palindrome found
    int lstreak = 0;
    string longest = "";

    for (int i = 0; i < s.size(); i++) {
        // odd case, i.e. "aba"
        pair<int, int> odd = expand(s, i, i);
        // even case, i.e. "abba"
        pair<int, int> even = expand(s, i, i + 1);
        // compare the longest palindrome found so far to the longest palindrome
        if (odd.second - odd.first + 1 > lstreak) {
            lstreak = odd.second - odd.first + 1;
            longest = s.substr(odd.first, lstreak);
        }
        // compare the longest palindrome found so far to the longest palindrome
        if (even.second - even.first + 1 > lstreak) {
            lstreak = even.second - even.first + 1;
            longest = s.substr(even.first, lstreak);
        }
    }

    return longest;
  }

  pair<int, int> expand(string& s, int l, int r) {
    // expand the palindrome around the center
    while(l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
        l--;
        r++;
    }
    return make_pair(l + 1, r - 1);
  }
};