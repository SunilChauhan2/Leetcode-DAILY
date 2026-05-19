// Problem : (LC 2540) Minimum Common Value
// Approach : Hash Table
// Time Complexity : O(N + M)

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());

        for (int num : nums2) {
            if (set1.find(num) != set1.end()) {
                return num;
            }
        }

        return -1;
    }
};