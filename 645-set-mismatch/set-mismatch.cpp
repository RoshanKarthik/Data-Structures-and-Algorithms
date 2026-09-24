class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int x : nums){
            mpp[x]++;
        }
        int dup = 0;
        int mis = 0;
        for(int i=1; i<=n; i++){
           if(mpp[i] == 2){
            dup = i;
           }
           if(mpp[i] == 0){
            mis = i;
           }
        }
        return {dup,mis};
    }
};