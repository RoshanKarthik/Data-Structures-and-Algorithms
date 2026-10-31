class Solution {
private:
    int n,m;
    int dp[505][505][3];
    const int mod = 1e9+7;
    int rec(int i, int j, int cameFrom, vector<vector<int>>& grid){
        // pruning
        if(i >= n || j >= m) return 0;
        // basecase
        if(i == n-1 && j == m-1) return 1;
        // cache check
        if(dp[i][j][cameFrom] != -1) return dp[i][j][cameFrom];
        // compute 
        int total = 0;
        if(grid[i][j] == 0){
            total = (total + rec(i,j+1,0,grid))%mod;
            total = (total + rec(i+1,j,1,grid))%mod;
        }
        else{
            if(cameFrom == 0){
                total = (total + rec(i+1,j,1,grid))%mod;
            }
            else{
                total = (total + rec(i,j+1,0,grid))%mod;
            }
        }
        // save and return
        return dp[i][j][cameFrom] = total%mod;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,2,grid)%mod;
    }
};