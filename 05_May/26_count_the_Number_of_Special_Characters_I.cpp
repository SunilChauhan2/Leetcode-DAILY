// Problem : (LC 3120)Count the Number of Special Characters I
// Approach : Hash table / Enumeration
// Time Complexity : O(N)

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.count(c) && s.count(c - 'a' + 'A')) {
                ans++;
            }
        }
        return ans;
    }
};