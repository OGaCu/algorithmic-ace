#include<vector>

using std::vector, std::sort;

/**
 * Remove least number of interval = keep smallest end in interval
 * intervals = [[1,2],[2,3],[3,4],[1,3]]
 * output = 1 where [1,3] is removed
 * 
 * intervals = [[1,5],[1,5],[1,5]]
 * output = 2 two of the [1,5] are removed
 * 
 * if input intervals are non-overlapping, output = 0
 */

/**
 * time complexity: O(NlogN)
 * space complexity: O(logN) - c++ introsort
 * if overlap, remove later interval
 *      overlap if intervals[i-1][1] > intervals[i][0]
 *      !! previous_end needed to track longest interval
 * else continue
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // sort by ends of interval using lambda
        sort(intervals.begin(), intervals.end(), 
        [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; }  );

        int num_removal = 0;
        int prev_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            
            if (prev_end > intervals[i][0]) num_removal++;
            else prev_end = intervals[i][1];
        }

        return num_removal;
    }
};