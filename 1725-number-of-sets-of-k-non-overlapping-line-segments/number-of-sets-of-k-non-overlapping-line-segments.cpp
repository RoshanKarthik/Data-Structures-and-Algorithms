class Solution {
private:
    const int mod = 1e9+7;
    int dp[1001][1001];
    // int rec(int n, int k, int idx){
    //     if(k == 0) return 1;
    //     if(idx >= n) return 0;
    //     if(t[k][idx] != -1) return t[k][idx];
    //     int skip = rec(n,k,idx+1);
    //     int take = 0;
    //     for(int j=idx+1; j<=n-1; j++){
    //         take = (take + rec(n,k-1,j))%mod;
    //     }
    //     return t[k][idx] = (take + skip)%mod;
    // }
public:
    int numberOfSets(int n, int K) {
        // memset(t,-1,sizeof(t));
        // return rec(n,k,0)%mod;
        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }

        for(int k=1; k<=K; k++){
            vector<int>prevSum(n+1,0);
            for(int x=n-1; x>=0; x--){
                prevSum[x] = (prevSum[x+1] + dp[k-1][x]) % mod;
            }
            for(int idx=n-1; idx>=0; idx--){
                int skip = dp[k][idx+1];
                int take = prevSum[idx+1];
                dp[k][idx] = (skip + take) % mod;
            }
        }
        return dp[K][0];
    }
};