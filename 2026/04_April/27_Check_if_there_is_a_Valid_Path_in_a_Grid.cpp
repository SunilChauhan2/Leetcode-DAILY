// Problem : (LC 1391)Check if there is a Valid Path in a Grid
// Approach : Breadth First Search / Queue / Array
// Time Complexity : O(M * N)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<int,int>>> dir = {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n,false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();

            if(r == m-1 && c == n-1)
                return true;

            for(auto [dr,dc] : dir[grid[r][c]]){
                int nr = r + dr, nc = c + dc;

                if(nr<0 || nc<0 || nr>=m || nc>=n)
                    continue;

                if(vis[nr][nc])
                    continue;
                    
                for(auto [rdr,rdc] : dir[grid[nr][nc]]){
                    if(nr + rdr == r && nc + rdc == c){
                        vis[nr][nc] = true;
                        q.push({nr,nc});
                        break;
                    }
                }
            }
        }

        return false;
    }
};