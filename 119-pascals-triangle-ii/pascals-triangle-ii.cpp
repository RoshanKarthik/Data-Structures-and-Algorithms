class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector<int>ans;
        ans.push_back(1);
        long long x = 1;
        for(int i=1; i<n; i++){
            x *= (n-i);
            x /= i;
            ans.push_back(x);
        }
        return ans;
    }
};