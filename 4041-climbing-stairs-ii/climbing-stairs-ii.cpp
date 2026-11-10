class Solution {
private:
    int dp[100005];

    int rec(int idx, int n, vector<int>& costs) {

        if(idx == n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = 1e9;

        for(int jump = 1; jump <= 3; jump++) {
            if(idx + jump <= n) {
                ans = min(ans, costs[idx + jump - 1] + jump * jump + rec(idx + jump, n, costs));
            }
        }

        return dp[idx] = ans;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return rec(0, n, costs);
    }
};