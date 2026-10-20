class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>vis(n,0);
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        for(int x : restricted){
            vis[x] = -1;
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it : adj[node]){
                if(vis[it]==0 && vis[it]!=-1){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 1) count++;
        }

        return count;

    }
};