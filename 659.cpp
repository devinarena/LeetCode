
#include "includes.h"

/**
 * @brief LeetCode Problem 659. Encode and Decode Strings
 *
 * Design an algorithm to encode a list of strings to a string. The encoded
 * string is then sent over the network and is decoded back to the original list
 * of strings.
 *
 * Please implement encode and decode
 *
 * @see https://leetcode.com/problems/encode-and-decode-strings/
 * @see https://www.lintcode.com/problem/659/
 * @date 6/15/2022
 */

class Solution {
 public:
  string encode(vector<string>& strs) {
    string ans{""};

    // use a character to represent word breaks
    // but we have to denote the character as a special character if it appears
    // in the word
    for (string& str : strs) {
      for (int i = 0; i < str.size(); i++) {
        // :; are the characters we use to denote word breaks, so : is a special
        // case
        if (str[i] == ':') {
          ans += "::";
        } else {
          // otherwise add the word
          ans += str[i];
        }
        // :; represents a word break
        if (i != strs.size() - 1)
          ans += ":;";
      }
    }
  }

  vector<string> decode(string& str) {
    vector<string> ans;
    string curr{""};

    for (int i = 0; i < str.size(); i++) {
      // if we see a : its a special character, so we need to check it
      if (str[i] == ':') {
        // at the end of a string its a normal character
        if (i == str.size()) {
          ans.push_back("" + str[i]);
          break;
        }
        // if its followed by a :, its a special character
        if (str[i + 1] == ':') {
          curr.push_back(':');
          i++;
        }
        // if its followed by a ;, its a word break
        else if (str[i + 1] == ';') {
          ans.push_back(curr);
          i++;
        }
        // Otherwise its normal
        else
          curr.push_back(str[i]);
      }
      // all other characters are normal
      else
        curr.push_back(str[i]);
    }
    return ans;
  }
};