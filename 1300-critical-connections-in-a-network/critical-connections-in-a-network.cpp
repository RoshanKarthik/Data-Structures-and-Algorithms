class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>&vis, vector<int>&tin, vector<int>&low, vector<vector<int>>&adj, vector<vector<int>>&bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto &it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,vis,tin,low,adj,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &connection : connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);

        vector<vector<int>>bridges;
        dfs(0,-1,vis,tin,low,adj,bridges);
        return bridges;
    }
};