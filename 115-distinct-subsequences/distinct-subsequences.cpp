class Solution {
private:
    int dp[1001][1001];
    int rec(int i, int j, string &s, string &t){
        //basecase
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        //cache check
        if(dp[i][j] != -1) return dp[i][j];

        //compute
        if(s[i] == t[j]){
            int take = rec(i+1,j+1,s,t);
            int not_take = rec(i+1,j,s,t);
            return dp[i][j] = take + not_take;
        }
        else{
            return dp[i][j] = rec(i+1,j,s,t);
        }
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,t);
    }
};