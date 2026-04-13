// Problem : (LC 1848) Minimum Distance to the target Element
// Approach : Simulation
// Time Complexity : O(n)

#include<vector>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
            }
        }
        return res;
    }
};