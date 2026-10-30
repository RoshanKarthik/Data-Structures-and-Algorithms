using State = tuple<int,int,int>;
using pii = pair<int,int>;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pii>>adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

        priority_queue<State,vector<State>,greater<State>>pq;

        vector<vector<int>>dis(n,vector<int>(k+1,INT_MAX));
        dis[0][1] = 0;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [dist,node,cnt] = pq.top();
            pq.pop();
            if(dis[node][cnt] < dist) continue;
            if(node == n-1) return dist;
            for(auto &it : adj[node]){
                int v = it.first;
                int wt = it.second;
                int ncnt = (labels[v] == labels[node]) ? cnt+1 : 1;
                if(ncnt > k) continue;
                int ndist = dist + wt;
                if(ndist < dis[v][ncnt]){
                    dis[v][ncnt] = ndist;
                    pq.push({ndist,v,ncnt});
                }
            }
        }

        return -1;
        
    }
};