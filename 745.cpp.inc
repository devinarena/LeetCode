
#include "includes.h"

/**
 * @brief LeetCode Problem 745. Prefix and Suffix Search
 *
 * Design a special dictionary with some words that searchs the words in it by a
 * prefix and a suffix.
 *
 * Implement the WordFilter class:
 *
 * WordFilter(string[] words) Initializes the object with the words in the
 * dictionary. f(string prefix, string suffix) Returns the index of the word in
 * the dictionary, which has the prefix prefix and the suffix suffix. If there
 * is more than one valid index, return the largest of them. If there is no such
 * word in the dictionary, return -1.
 *
 * @see https://leetcode.com/problems/prefix-and-suffix-search/
 * @date 6/18/2022
 */

class Trie {
 public:
  Trie* children[26];
  int index;
  bool is_end;

  Trie() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    index = -1;
    is_end = false;
  }

  void insert(string& word) {
    Trie* curr = this;
    for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        if (curr->children[c - 'a'] == nullptr) {
            curr->children[c - 'a'] = new Trie();
        }
        curr = curr->children[c - 'a'];
    }
  }
};

class WordFilter {
 public:
  WordFilter(vector<string>& words) {
    Trie prefix;
    Trie suffix;
  }

  int f(string prefix, string suffix) {}
};