class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>st(supplies.begin(),supplies.end());
        int n = recipes.size();
        unordered_map<string,vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto &it : ingredients[i]){
                if(!st.count(it)){
                    adj[it].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<string>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            string recipe = recipes[node];
            ans.push_back(recipe);
            for(auto &it : adj[recipe]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return ans;
    }
};