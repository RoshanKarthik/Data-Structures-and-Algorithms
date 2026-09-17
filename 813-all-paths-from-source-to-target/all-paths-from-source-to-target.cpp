class Solution {
private:
    void dfs(int node, vector<int>&path, vector<vector<int>>&ans, vector<vector<int>>&graph){
        if(node == graph.size()-1){
            ans.push_back(path);
            return;
        }

        for(auto it : graph[node]){
            path.push_back(it);
            dfs(it,path,ans,graph);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path = {0};
        dfs(0,path,ans,graph);
        return ans;
    }
};