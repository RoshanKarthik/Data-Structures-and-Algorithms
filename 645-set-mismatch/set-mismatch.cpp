class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int x : nums){
            mpp[x]++;
        }
        vector<int>ans;
        for(int i=1; i<=n; i++){
            if(mpp[i] == 2){
                ans.push_back(i);
            }
        }
        for(int i=1; i<=n; i++){
            if(mpp[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};