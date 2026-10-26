class Solution {
    private void dfs(int i, int j, int[][] grid, int[][] vis, long[] ans, int n, int m){
        vis[i][j] = 1;
        ans[0] += grid[i][j];
        int[] drow = {-1,0,1,0};
        int[] dcol = {0,1,0,-1};
        for(int d=0; d<4; d++){
            int ni = drow[d] + i;
            int nj = dcol[d] + j;
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] != 0 && vis[ni][nj] == 0){
                dfs(ni,nj,grid,vis,ans,n,m);
            }
        }
    }
    public int countIslands(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0 && vis[i][j] == 0){
                    long[] ans = new long[1];
                    dfs(i,j,grid,vis,ans,n,m);
                    System.out.println(ans);
                    if(ans[0]%k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
}