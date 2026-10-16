class Solution {
private:
    bool dfs(int node, int col, vector<int>&color, vector<vector<int>>& graph){
        color[node] = col;
        for(int v : graph[node]){
            if(color[v] == -1){
                if(dfs(v,!col,color,graph)==false) return false;
            }
            else if(color[node] == color[v]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V,-1);
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};