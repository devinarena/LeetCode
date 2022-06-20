
#include "includes.h"

/**
 * @brief LeetCode Problem 1048. Longest String Chain
 *
 * You are given an array of words where each word consists of lowercase English
 * letters.
 *
 * wordA is a predecessor of wordB if and only if we can insert exactly one
 * letter anywhere in wordA without changing the order of the other characters
 * to make it equal to wordB.
 *
 * For example, "abc" is a predecessor of "abac", while "cba" is not a
 * predecessor of "bcad". A word chain is a sequence of words [word1, word2,
 * ..., wordk] with k
 * >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3,
 * and so on. A single word is trivially a word chain with k == 1.
 *
 * Return the length of the longest possible word chain with words chosen from
 * the given list of words.
 *
 * @see https://leetcode.com/problems/
 * @date 6/14/2022
 */

class Solution {
 public:
  // Time Complexity: O(nlogn) (sort)
  // Space Complexity: O(n) (map)
  int longestStrChain(vector<string>& words) {
    // sort to try shortest words first
    sort(words.begin(), words.end(),
         [](const string& a, const string& b) { return a.size() < b.size(); });
    unordered_map<string, int> longest;
    int m = 1;

    // smallest word chain is one word
    for (string& word : words) {
      longest[word] = 1;
    }

    for (string& word : words) {
      for (int i = 0; i < word.size(); i++) {
        // try erasing every character
        string candidate = word;
        candidate.erase(i, 1);
        // see if this candidate is a predecessor
        if (longest.find(candidate) != longest.end()) {
          // take the larger of the current word chain and the candidate's
          longest[word] = max(longest[word], longest[candidate] + 1);
          // update the global max
          m = max(m, longest[word]);
        }
      }
    }

    return m;
  }
};