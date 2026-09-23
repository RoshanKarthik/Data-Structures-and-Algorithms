class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        //dp[target] = no of digits i can accomodate with cost = target;
        vector<int>dp(target+1,-1);
        dp[0] = 0;
        for(int t=1; t<=target; t++){
            for(int digit=1; digit<=9; digit++){
                if(t>=cost[digit-1] && dp[t-cost[digit-1]] != -1){
                    dp[t] = max(dp[t],1+dp[t-cost[digit-1]]);
                }
            }
        }
        if(dp[target] == -1){
            return "0";
        }
        string ans = "";
        for(int digit=9; digit>=1; digit--){
            while(target>=cost[digit-1] && dp[target] == 1 + dp[target-cost[digit-1]]){
                ans += ('0'+digit);
                target -= cost[digit-1];
            }
        }
        return ans;
    }
};