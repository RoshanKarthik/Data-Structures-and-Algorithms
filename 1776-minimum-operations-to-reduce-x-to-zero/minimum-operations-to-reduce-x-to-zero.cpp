using ll = long long;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        ll s= accumulate(nums.begin(),nums.end(),0LL);
        int k = s-x;
        if(k<0) return -1;
        if(k==0) return n;
        int l=0,r=0;
        int maxLen = -1;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            if(sum == k){
                maxLen = max(maxLen,r-l+1);
            }
            r++;
        }
        return (maxLen == -1 ? -1 : n-maxLen);
    }
};