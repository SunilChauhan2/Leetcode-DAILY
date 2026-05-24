// Problem : (LC 1340)Jump Game V
// Approach : DFS + Memoization on Array Graph
// Time Complexity : O(m*n)

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    int dfs(vector<int>& arr, int d, int i){

        if(dp[i] != -1)
            return dp[i];

        int n = arr.size();

        int ans = 1;

        for(int j = i + 1; j <= min(n - 1, i + d); j++){

            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(arr, d, j));
        }

        for(int j = i - 1; j >= max(0, i - d); j--){

            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(arr, d, j));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        dp.assign(n, -1);

        int res = 1;

        for(int i = 0; i < n; i++){
            res = max(res, dfs(arr, d, i));
        }

        return res;
    }
};