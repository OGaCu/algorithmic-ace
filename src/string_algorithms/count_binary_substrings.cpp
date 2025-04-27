#include <string>

using std::string;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, cur = 1, count = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                ++cur;
            } else {
                prev = cur;
                cur = 1;
            }
            if (prev >= cur) {
                ++count;
            } 
        }
        return count;
    }
}; // 696