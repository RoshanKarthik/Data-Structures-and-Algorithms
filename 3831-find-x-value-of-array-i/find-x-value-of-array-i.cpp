using ll = long long;
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>ans(k,0);
        vector<ll>prevCount(k,0);
        for(int i=0; i<n; i++){
            vector<ll>currCount(k,0);
            currCount[nums[i] % k]++;
            for(int oldRem=0; oldRem<=k-1; oldRem++){
                int newRem = ((ll)oldRem * nums[i]%k)%k;
                currCount[newRem] += prevCount[oldRem];
            }
            prevCount = currCount;
            for(int x=0; x<=k-1; x++){
                ans[x] += prevCount[x];
            }
        }
        return ans;
    }
};