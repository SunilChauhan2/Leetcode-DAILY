// Problem : (LC 1306)Jump Game III
// Approach : BFS / DFS
// Time Complexity : O(N)

#include<vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>& arr, int i, vector<bool>& vis) {
        int n = arr.size();

        if(i < 0 || i >= n || vis[i])
            return false;

        if(arr[i] == 0)
            return true;

        vis[i] = true;

        return dfs(arr, i + arr[i], vis) ||
               dfs(arr, i - arr[i], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return dfs(arr, start, vis);
    }
};