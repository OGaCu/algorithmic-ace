#include<vector>

using std::vector, std::sort;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // remove least number of interval = keep smallest end in interval
        
        // sort by ends in interval using lambda
        sort(intervals.begin(), intervals.end(), 
        [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; }  );

        // greedy
        int num_removal = 0;
        int prev_end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            // if overlap, remove later interval
                // overlap if intervals[i-1][1] > intervals[i][0]
                // !!! previous_end needed
            // else continue
            // if(intervals[i-1][1] > intervals[i][0]) num_removal++; // wrong
            if (prev_end > intervals[i][0]) num_removal++;
            else prev_end = intervals[i][1];

        }

        return num_removal;
    }
};