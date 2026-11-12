class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int cnt = 1;
        int maxi = 1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) cnt++;
            else cnt = 1;
            maxi = max(maxi,cnt);
        }
        cnt = 1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] > nums[i+1]) cnt++;
            else cnt = 1;
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};