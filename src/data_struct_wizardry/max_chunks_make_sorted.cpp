/**
 * Given an integer array arr of length n that represents a permutation of the integers in the range [0,n - 1]
 * Split arr into some number of chunks/partitions, and individually sort each chunk
 * After concatenating, result should equal to the sorted arr
 * 
 * [4, 3, 2, 1, 0] -> 1
 * [1, 0, 2, 3, 4] -> 4
 */

#include <vector>
using std::vector, std::max;

// O(n)

int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0, curr_max = 0;
    for (int i = 0; i < arr.size(); ++i) {
        curr_max = max(curr_max, arr[i]);
        chunks += curr_max == i;
    }
    return chunks;
    
} // 769