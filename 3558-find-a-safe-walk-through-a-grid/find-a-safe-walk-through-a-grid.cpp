class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = grid[0][0];
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!dq.empty()){
            auto [r,c] = dq.front();
            dq.pop_front();
            for(int d=0; d<4; d++){
                int nr = r + drow[d];
                int nc = c + dcol[d];
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(dist[nr][nc] > dist[r][c] + grid[nr][nc]){
                    dist[nr][nc] = dist[r][c] + grid[nr][nc];
                    if(grid[nr][nc] == 0){
                        dq.push_front({nr,nc});
                    }
                    else{
                        dq.push_back({nr,nc});
                    }
                }
            }
        }
        return dist[n-1][m-1] < health;
    }
};