
#include "includes.h"

/**
 * @brief LeetCode Problem 1346. Check If N and Its Double Exist
 *
 * Given an array arr of integers, check if there exists two integers N and M
 * such that N is the double of M ( i.e. N = 2 * M).
 *
 * More formally check if there exists two indices i and j such that :
 *
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 *
 * @see https://leetcode.com/problems/check-if-n-and-its-double-exist/
 * @date 6/14/2022
 */

class Solution {
 public:
  // Use a set to track seen values
  // Zero is a special case, since the double of zero is zero
  // Time Complexity: O(n)
  // Space Complexity: O(n) (for the set)
  bool checkIfExist(vector<int>& arr) {
    // track seen values to search for a double
    set<int> seen;
    // track zeroes
    int z = 0;

    for (int i : arr) {
      seen.insert(i);
      if (i == 0)
        z++;
    }

    // if we find more than one zero, we already know the arr has a double
    // since zero doubled is zero
    if (z > 1)
      return true;

    for (int i : seen) {
      // look through seen numbers for a double (ignore 0)
      if (i != 0 && seen.find(i * 2) != seen.end())
        return true;
    }

    return false;
  }
};