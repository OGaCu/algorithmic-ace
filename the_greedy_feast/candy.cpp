#include <vector>
using std::vector;

#include <numeric>
using std::accumulate, std::max;

/**
 * You are giving candies to these children subjected to the following requirements:
 * 1. Each child must have at least one candy.
 * 2. Children with a higher rating get more candies than their neighbors.
 * 
 * ratings = [1,0,2], returns 5 because 2,1,2
 * ratings = [1,2,2], returns 4 because 1,2,1
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        // time: O(N), space: O(N)
        // init all children with 1 cookie
        // traverse from left to right 
            // if left < right, right = left + 1
        // traverse from right to left
            // if right < left, left = max(right + 1, left)
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i] ) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i] < ratings[i - 1]) {
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
}; // 135