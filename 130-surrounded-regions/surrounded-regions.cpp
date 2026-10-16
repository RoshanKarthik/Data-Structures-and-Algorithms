class Solution {
private:
    int n,m;
    int drow[4] = {0,1,0,-1};
    int dcol[4] = {1,0,-1,0};
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr,nc,board,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    if(i==0 || i == n-1 || j == 0 || j == m-1){
                        dfs(i,j,board,vis);
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] =='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};