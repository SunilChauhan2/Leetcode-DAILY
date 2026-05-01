// Problem : (LC 2078)Two Furthest Houses With Different Colors
// Approach : two pointer/ Greeddy
// Time Complexity : O(N^2)

#include<vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int res = 0;  
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    res = max(res, j - i);
                }
            }
        }
        return res;
    }
};