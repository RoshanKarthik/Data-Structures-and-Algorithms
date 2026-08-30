class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>indegree(n, vector<int>(m, 0));
        int drow[] = {0,-1,0,1};
        int dcol[] = {1,0,-1,0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int d=0; d<4; d++){
                    int ni = drow[d] + i;
                    int nj = dcol[d] + j;
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[i][j] < matrix[ni][nj]){
                        indegree[ni][nj]++;
                    }
                }
            }
        }

        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(indegree[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int d=0; d<4; d++){
                    int nr = drow[d] + r;
                    int nc = dcol[d] + c;
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && matrix[r][c] < matrix[nr][nc]){
                        indegree[nr][nc]--;
                        if(indegree[nr][nc] == 0){
                            q.push({nr,nc});
                        }
                    } 
                }
            }
        }

        return ans;
    }
};