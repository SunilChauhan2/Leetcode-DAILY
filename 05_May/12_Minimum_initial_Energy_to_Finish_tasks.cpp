// Problem : (LC 1665)Minimum initial Energy to finish task
// Approach : Greedy / Sorting
// Time Complexity : O(nlogn)

#include<vector>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        int ans = 0;
        for (auto task : tasks) {
            ans = max(ans + task[0], task[1]);
        }
        return ans;
    }
};