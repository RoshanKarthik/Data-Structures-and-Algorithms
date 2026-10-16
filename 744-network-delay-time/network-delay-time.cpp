class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it : times){
            graph[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>distance(n+1,1e9);
        distance[k] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto nei : graph[node]){
                int v = nei.first;
                int wt = nei.second;
                if(dis + wt < distance[v]){
                    distance[v] = dis + wt;
                    pq.push({distance[v],v});
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(distance[i] == 1e9) return -1;
        }
        int minimum = *max_element(distance.begin()+1,distance.end());
        return minimum;
    }
};