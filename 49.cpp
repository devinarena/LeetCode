
#include "includes.h"

/**
 * @brief LeetCode Problem 49. Group Anagrams
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 * @see https://leetcode.com/problems/group-anagrams/
 * @date 6/14/2022
 */

class Solution {
 public:
  // Time Complexity: O(n * klogk) (n = # of words, k = avg length of word)
  // Space Complexity: O(n * k) (n = # of words, k = avg length of word)
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // all strings will have the same key when sorted, store it in a map
    map<string, vector<string>> anagrams;

    for (string& s : strs) {
      // create a sorted key from the string
      string key = s;
      sort(key.begin(), key.end(), [](char& a, char& b) { return a < b; });
      // insert the string into the corresponding key's vector
      anagrams[key].push_back(s);
    }

    // convert the map to a vector
    vector<vector<string>> ans;
    for (pair<string, vector<string>> p : anagrams) {
      ans.push_back(p.second);
    }

    return ans;
  }
};