// Problem : (LC 3753)Total Waviness of Numbers in Range II
// Approach : Digit DP with local pattern contribution
// Time Complexity : States ≈ 20 * 11 * 11 * 2 * 2

#include<iostream>
using namespace std;

class Solution {
public:

    typedef long long ll;

    string s;

    struct Node{
        ll cnt;
        ll wav;
    };

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos, int p1, int p2, bool tight, bool started){

        if(pos == s.size()){
            return {1, 0};
        }

        if(vis[pos][p1][p2][tight][started])
            return dp[pos][p1][p2][tight][started];

        vis[pos][p1][p2][tight][started] = true;

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for(int d = 0; d <= limit; d++){

            bool ntight = tight && (d == limit);
            bool nstarted = started || (d != 0);

            int np1 = p1;
            int np2 = p2;

            ll add = 0;

            if(!started && d == 0){

                auto nxt = dfs(pos + 1, 10, 10, ntight, false);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav;
            }
            else{

                if(p1 != 10 && p2 != 10){

                    // peak
                    if(p2 < p1 && p1 > d)
                        add = 1;

                    // valley
                    else if(p2 > p1 && p1 < d)
                        add = 1;
                }

                auto nxt = dfs(pos + 1, d, p1, ntight, true);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav + add * nxt.cnt;
            }
        }

        return dp[pos][p1][p2][tight][started] = ans;
    }

    long long solve(long long x){

        if(x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 1, 0).wav;
    }

    long long totalWaviness(long long num1, long long num2) {

        return solve(num2) - solve(num1 - 1);
    }
};