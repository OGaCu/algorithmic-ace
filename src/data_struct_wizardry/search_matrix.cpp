/**
 * You are given an m x n integer matrix matrix with the following two properties:
 * Each row is sorted in non-decreasing order.
 * The first integer of each row is greater than the last integer of the previous row.
 * Given an integer target, return true if target is in matrix or false otherwise.
 * 
 * You must write a solution in O(log(m * n)) time complexity.
 */

#include <vector>
using std::vector;

// time complexity O(m + n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        int val = matrix[i][j];
        if (val == target) return true;
        else if (val > target) j--;
        else i++;
    }
    return false;
} // 74

// time complexity O(log(m+n)) 
// use binary search; as a flattened 1d array