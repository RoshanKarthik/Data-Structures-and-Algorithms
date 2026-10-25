class Solution {
    private void dfs(int i, int j, int[][] grid){
        grid[i][j] = 1;
        int[] drow = {0,-1,0,1};
        int[] dcol = {1,0,-1,0};
        for(int d=0; d<4; d++){
            int ni = drow[d] + i;
            int nj = dcol[d] + j;
            if(ni < 0 || ni >= grid.length || nj < 0 || nj >= grid[0].length) continue;
            if(grid[ni][nj] == 1) continue;
            dfs(ni,nj,grid);
        }
    }
    public int closedIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j] == 0){
                        dfs(i,j,grid);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }

        return ans;
    }
}