class Solution {
private:
    int n,m;
    int dp[1005][1005];
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    const int mod = 1e9+7;
    int rec(int i, int j, vector<vector<int>>& grid){
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        for(int d=0; d<4; d++){
            int ni = drow[d] + i;
            int nj = dcol[d] + j;
            if(ni < 0 || nj < 0 || ni >= n || nj >= m || grid[i][j] >= grid[ni][nj]) continue;
            dp[i][j] = (dp[i][j] + rec(ni,nj,grid))%mod;
        }
        return dp[i][j]%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = (ans + rec(i,j,grid))%mod;
            }
        }
        return ans%mod;
    }
};