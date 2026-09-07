class Solution {
private:
    const int mod = 1e9+7;
    int dp[2001];
    vector<int>prev;
    int rec(int n){
        if(n == 0){
            return 1;
        }

        if(dp[n] != -1) return dp[n];

        int total = (2*rec(n-1))%mod;

        if(prev[n] != 0){
            int duplicates = rec(prev[n]-1);
            total = (total-duplicates+mod)%mod;
        }

        return dp[n] = total;
    }
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        prev.assign(n+1,0);
        vector<int>lastSeen(26,0);
        for(int i=1; i<=n; i++){
            int idx = s[i-1]-'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (rec(n)-1+mod)%mod;
    }
};