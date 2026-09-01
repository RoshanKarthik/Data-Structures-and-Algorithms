class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        int startx = -1;
        int starty = -1;
        int keyCount = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '@'){
                    startx = i;
                    starty = j;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    keyCount++;
                }
            }
        }
        int targetMask = (1 << keyCount) - 1;
        queue<tuple<int,int,int,int>>q;
        vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(1 << keyCount, false)));
        q.push({startx, starty, 0, 0});
        vis[startx][starty][0] = true;
        while(!q.empty()){
            auto [r,c,mask,steps] = q.front();
            q.pop();
            for(int d=0; d<4; d++){
                int nr = drow[d] + r;
                int nc = dcol[d] + c;
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != '#'){
                    int next_mask = mask;
                    if(grid[nr][nc] >= 'a' && grid[nr][nc] <= 'f'){
                        int key = grid[nr][nc] - 'a';
                        next_mask |= (1 << key);
                    }
                    if(next_mask == targetMask) return steps+1;
                    if(grid[nr][nc] >= 'A' && grid[nr][nc] <= 'F'){
                        int key = grid[nr][nc] - 'A';
                        if(!(next_mask & (1 << key))) continue;
                    }
                    if(!vis[nr][nc][next_mask]){
                        vis[nr][nc][next_mask] = true;
                        q.push({nr,nc,next_mask,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};