class Solution {
private:
    int dp[505][505];
    int rec(int i, int j, string& word1, string& word2){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            dp[i][j] = 1+rec(i-1,j-1,word1,word2);
        }
        else dp[i][j] = max(rec(i-1,j,word1,word2),rec(i,j-1,word1,word2));
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp,-1,sizeof(dp));
        int lcs = rec(n-1,m-1,word1,word2);
        int ans = n+m-(2*lcs);
        return ans;
    }
};