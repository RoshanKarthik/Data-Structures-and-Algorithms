using t = tuple<int,int,int,int,int>;
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<vector<int>>>>cost(n,vector<vector<vector<int>>>(m,vector<vector<int>>(5,vector<int>(k+1,1e9))));
        priority_queue<t,vector<t>,greater<t>>q;

        q.push({grid[0][0],0,0,0,0});
        cost[0][0][0][0] = grid[0][0];

        int drow[] = {0,0,-1,1};
        int dcol[] = {1,-1,0,0};

        while(!q.empty()){
            auto [c,x,y,d,t] = q.top();
            q.pop();
            if(cost[x][y][d][t] != c) continue;
            for(int j=0; j<4; j++){
                int nx = x + drow[j];
                int ny = y + dcol[j];
                int nt = t;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(d!=0 && d!=j+1){
                    nt++;
                }
                if(nt > k) continue;
                int cos = grid[nx][ny] + c;
                if(cost[nx][ny][j+1][nt] > grid[nx][ny]+c){
                    cost[nx][ny][j+1][nt] = grid[nx][ny]+c;
                    q.push({cost[nx][ny][j+1][nt],nx,ny,j+1,nt});
                }
            }
        }

        int ans = 1e9;
        for(int i=0; i<5; i++){
            for(int j=0; j<=k; j++){
                ans = min(ans,cost[n-1][m-1][i][j]);
            }
        }

        return (ans == 1e9 ? -1 : ans);
    }
};