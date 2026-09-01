class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        vector<vector<int>>litterMap(n,vector<int>(m,-1));
        int startx = -1;
        int starty = -1;
        int litterCount = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(classroom[i][j] == 'S'){
                    startx = i;
                    starty = j;
                }
                if(classroom[i][j] == 'L'){
                    litterMap[i][j] = litterCount++;
                }
            }
        }

        if(litterCount == 0) return 0;

        int targetMask = (1 << litterCount) - 1;
        queue<tuple<int,int,int,int,int>>q;
        vector<vector<vector<vector<bool>>>>vis(n,vector<vector<vector<bool>>>(m,vector<vector<bool>>(energy+1,vector<bool>(1<<litterCount,false))));
        q.push({startx,starty,energy,0,0});
        vis[startx][starty][energy][0] = true;
        while(!q.empty()){
            auto [r,c,e,mask,steps] = q.front();
            q.pop();
            if(e == 0) continue;
            for(int d=0; d<4; d++){
                int nr = drow[d] + r;
                int nc = dcol[d] + c;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && classroom[nr][nc] != 'X'){
                    int next_e = e-1;
                    int next_mask = mask;
                    if(classroom[nr][nc] == 'L'){
                        next_mask |= (1 << litterMap[nr][nc]);
                    }
                    
                    if(classroom[nr][nc] == 'R'){
                        next_e = energy;
                    }
                    if(next_mask == targetMask){
                        return steps+1;
                    }
                    if(next_e == 0 && classroom[nr][nc] != 'R') continue;
                    if(!vis[nr][nc][next_e][next_mask]){
                        vis[nr][nc][next_e][next_mask] = true;
                        q.push({nr,nc,next_e,next_mask,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};