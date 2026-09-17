class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int result = INT_MAX;
        int minLen = INT_MAX;
        vector<int>dp(n,INT_MAX);
        while(r < n){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            if(sum == target){
                int len = r-l+1;
                if(l > 0 && dp[l-1] != INT_MAX){
                    result = min(result,len+dp[l-1]);
                }
                minLen = min(minLen,len);
            }

            dp[r] = minLen;
            r++;

        }
        return (result == INT_MAX ? -1 : result);
    }
};