class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>minEffort(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        minEffort[0][0] = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == n-1 && c == m-1) return diff;
            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]),diff);
                    if(newEffort < minEffort[nr][nc]){
                        minEffort[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};