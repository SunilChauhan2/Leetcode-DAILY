// Problem : (LC 2033)Minimum Operation to Make a Uni-Valued Grid
// Approach : Array / Quickselect / Greedy
// Time Complexity : (n log n)

#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(auto &row : grid){
            for(int val : row){
                nums.push_back(val);
            }
        }

        int base = nums[0];
        for(int val : nums){
            if((val - base) % x != 0)
                return -1;
        }

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];

        int ops = 0;
        for(int val : nums){
            ops += abs(val - median) / x;
        }

        return ops;
    }
};

