/**
 * Note: this is an iterative implementation
 * the recursive implementation breaks the input into smaller input
 */
#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map, std::max;

int find_longest_increasing_suqsequence(vector<int> input) {
   
    // iterative solution from the beginning of the list
    // time complexity O(N) for one iteration
    // space complexity O(N) for the map
   
    // 2 -> 1
    // 1 -> 1 look for 0
    // 3 -> 2 look for 2 -> found
    // map<number seen, count>
   
    unordered_map<int, int> seen;
    int longest = 0;
   
    for(const auto& num : input) {
        auto prev_num = seen.find(num - 1);
        if(prev_num == seen.end()) { // not found
            seen[num] = 1;
        } else {
            seen[num] = seen[num - 1] + 1;
            longest = max(seen[num], longest);
        }
       
    }
    return longest;
}

vector<int> input = {2, 1, 3, 2, 4, 3, 2, 5, 4, 5}; // sequence = 5
int output = find_longest_increasing_suqsequence(input);
