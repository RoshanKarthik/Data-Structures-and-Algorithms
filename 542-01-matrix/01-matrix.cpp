class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e5));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        int drow[] = {0,-1,0,1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1 && dis[nr][nc] > dis[r][c]+1){
                    q.push({nr,nc});
                    dis[nr][nc] = dis[r][c] + 1;
                }
            }
        }
        return dis;
    }
};