class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int s = 1;
        int p = 1;
        for(int i=0; i<nums.size(); i++){
            if(s == 0) s=1;
            if(p == 0) p=1;
            s *= nums[nums.size()-i-1];
            p *= nums[i];
            ans = max({ans,s,p});
        }
        return ans;
    }
};