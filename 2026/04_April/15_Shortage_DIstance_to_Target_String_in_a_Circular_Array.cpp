// Problem : (LC 2515)Shortest Distance to Target String in a Circular Array
// Approach : Enumeration/ Brute Force
// Time Complexity : O(N * M)

#include<vector>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = words.size();
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                ans = min(ans, min(dist, n - dist));
            }
        }

        return ans < n ? ans : -1;
    }
};