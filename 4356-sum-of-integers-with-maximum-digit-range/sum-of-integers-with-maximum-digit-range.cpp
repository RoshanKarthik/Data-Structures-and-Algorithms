class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            int x = nums[i];
            int mx = INT_MIN;
            int mn = INT_MAX;
            while(x > 0){
                int digit = x%10;
                mx = max(mx,digit);
                mn = min(mn,digit);
                x/=10;
            }
            ans[i] = mx-mn;
            maxi = max(ans[i],maxi);
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            if(ans[i] == maxi){
                sum += nums[i];
            }
        }
        return sum;
    }
};