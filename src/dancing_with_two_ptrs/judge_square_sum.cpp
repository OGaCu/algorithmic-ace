#include<cmath> // sqrt

/**
 * c is non-negative integer
 * return true if a^2 + b^2 = c where a and b are both integers
 * c = [0, 2^31 - 1]
 */

class Solution {
public:
    bool judgeSquareSumTwoPtrs(int c) {
        // two pointers
        // time complexity: O(sqrt(c))
        // space complexity: O(1)
        unsigned int l = 0, r = sqrt(c);
        
        while (l <= r) {
            unsigned int sum = l * l + r * r;
            if(sum == c) return true;
            if(sum < c) l++;
            else r--;
        }
        return false;
    }
    bool judgeSquareSumBinarySearch(int c) {
        // binary search
        // time complexity: O(sqrt(c)log c)
        // space complexity: O(1)
        if (c == 0) return true;
        
        // For each possible a^2, binary search for b^2
        for (long a = 0; a * a <= c; a++) {
            long remain = c - a * a;
            
            if (binarySearch(0, remain, remain)) {
                return true;
            }
        }
        return false;
        

    }
private:
    bool binarySearch(long left, long right, long target) {
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            
            if (square == target) {
                return true;
            }

            if (square < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};