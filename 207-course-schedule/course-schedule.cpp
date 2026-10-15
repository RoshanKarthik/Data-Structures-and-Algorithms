class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int ans = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans++;
            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        return ans == n;
    }
};