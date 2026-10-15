class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(topo.size()==n){
            return topo;
        }

        return {};
    }
};