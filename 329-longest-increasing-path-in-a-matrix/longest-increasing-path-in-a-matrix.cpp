class Solution {
private:
    int dp[205][205];
    int n,m;
    int drow[4] = {1,0,-1,0};
    int dcol[4] = {0,1,0,-1};
    int rec(int i, int j, vector<vector<int>>& matrix){
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        for(int d=0; d<4; d++){
            int ni = drow[d] + i;
            int nj = dcol[d] + j;
            if(ni < 0 || nj < 0 || ni >= n || nj >= m || matrix[i][j] >= matrix[ni][nj]) continue;
            dp[i][j] = max(dp[i][j], 1+rec(ni,nj,matrix));
        }
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans,rec(i,j,matrix));
            }
        }
        return ans;
    }
};