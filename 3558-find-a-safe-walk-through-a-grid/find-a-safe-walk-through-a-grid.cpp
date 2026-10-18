class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = grid[0][0];
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>pq;
        pq.push({dist[0][0],0,0});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!pq.empty()){
            auto [dt,r,c] = pq.top();
            pq.pop();
            if (dt > dist[r][c]) continue;
            for(int d=0; d<4; d++){
                int nr = r + drow[d];
                int nc = c + dcol[d];
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(dist[nr][nc] > dt + grid[nr][nc]){
                    dist[nr][nc] = dt + grid[nr][nc];
                    pq.push({dist[nr][nc],nr,nc});
                }
            }
        }
        return dist[n-1][m-1] < health;
    }
};