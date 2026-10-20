class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>st(supplies.begin(),supplies.end());
        int n = recipes.size();
        vector<bool>cooked(n,false);
        vector<string>ans;
        int count = n;
        while(count--){
            for(int i=0; i<n; i++){
                if(cooked[i]) continue;
                bool flag = true;
                for(int j=0; j<ingredients[i].size(); j++){
                    if(!st.count(ingredients[i][j])){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    cooked[i] = true;
                }
            }
        }
        return ans;
    }
};