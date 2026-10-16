class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        //row, col
        queue<pair<int,int>>q;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        q.push({0,0});
        int dis = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [r,c] = q.front();
                q.pop();
                if(r == n-1 && c == n-1) return dis;
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        int nr = r + i;
                        int nc = c + j;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                            grid[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};