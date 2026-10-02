class Solution {
private:
    vector<vector<int>>ans;
    void rec(int i, int n, int k, vector<int>& t){
        if(t.size()==k){
            ans.push_back(t);
            return;
        }
        for(int j=i; j<=n; j++){
            t.push_back(j);
            rec(j+1,n,k,t);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>t;
        rec(1,n,k,t);
        return ans;
    }
};