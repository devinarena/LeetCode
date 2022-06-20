
#include "includes.h"

/**
 * @brief LeetCode Problem 820. Short Encoding of Words
 *
 *
 * A valid encoding of an array of words is any reference string s and array of
 * indices indices such that:
 *
 * words.length == indices.length
 * The reference string s ends with the '#' character.
 * For each index indices[i], the substring of s starting from indices[i] and up
 * to (but not including) the next '#' character is equal to words[i]. Given an
 * array of words, return the length of the shortest reference string s possible
 * of any valid encoding of words.
 *
 * @see https://leetcode.com/problems/short-encoding-of-words/
 * @date 6/20/2022
 */

class Trie {
 public:
  Trie* children[26];
  int count;
  Trie() {
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }

  Trie* get(char c) {
    if (children[c - 'a'] == NULL) {
      children[c - 'a'] = &Trie();
      count++;
    }
    return children[c - 'a'];
  }
};

class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    Trie* trie;
    unordered_map<Trie*, int> nodes;

    for (int i = 0; i < words.size(); i++) {
      string& word = words[i];
      Trie* curr = trie;
      for (int j = word.size() - 1; j >= 0; j--)
        curr = curr->get(word[j]);
      nodes[curr] = i;
    }

    int ans = 0;

    for (pair<Trie*, int> node : nodes) {
      if (node.first->count)
        ans += node.second;
    }

    return ans;
  }
};