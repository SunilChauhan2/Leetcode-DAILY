// Problem : (LC 1559)Detect Cycles in 2D grid
// Approach : Depth First Search / Recurrsion
// Time Complexity : O(MN)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<bool>> visit;

    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid){
        visit[r][c] = true;

        vector<int> dr = {0,0,1,-1};
        vector<int> dc = {1,-1,0,0};

        for(int d = 0; d < 4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if(grid[nr][nc] != grid[r][c])
                continue;

            if(nr == pr && nc == pc)
                continue;

            if(visit[nr][nc])
                return true;

            if(dfs(nr, nc, r, c, grid))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visit.assign(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visit[i][j]){
                    if(dfs(i, j, -1, -1, grid))
                        return true;
                }
            }
        }

        return false;
    }
};