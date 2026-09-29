class Solution {
private:
    int n,m;
    int dp[101][101][201];
    bool rec(int i, int j, int balance, vector<vector<char>>& grid){
        //pruning
        if(i==n || j==m) return false;
        //current cell
        if(grid[i][j] == '(') balance++;
        else balance--;
        if(balance < 0) return false;
        //basecase
        if(i==n-1 && j==m-1) return balance == 0;
        //cache check
        if(dp[i][j][balance] != -1) return dp[i][j][balance];
        //compute 
        bool ans = rec(i+1,j,balance,grid) || rec(i,j+1,balance,grid);
        //save and return 
        return dp[i][j][balance] = ans;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;
        if((n+m-1)%2 != 0) return false;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,grid);
    }
};