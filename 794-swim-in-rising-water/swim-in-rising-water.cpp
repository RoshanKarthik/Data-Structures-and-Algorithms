class Solution {
private:
    int drow[4] = {1,0,-1,0};
    int dcol[4] = {0,1,0,-1};
    bool isValid(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    bool dfs(int threshold, int i, int j, int n, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[i][j] = 1;
        if (i == n-1 && j == n-1) return true;
        for(int d=0; d<4; d++){
            int ni = i + drow[d];
            int nj = j + dcol[d];
            if(isValid(ni,nj,n) && vis[ni][nj] == 0 && grid[ni][nj] <= threshold){
                if(dfs(threshold, ni, nj, n, vis, grid)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0];
        int high = n*n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(dfs(mid,0,0,n,vis,grid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};