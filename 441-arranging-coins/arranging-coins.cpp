class Solution {
private:
    long helper(int m){
        long sum = (long)m*(m+1)/2;
        return sum;
    }
public:
    int arrangeCoins(int n) {
        int l = 0;
        int r = n;
        int ans = -1;
        while(l <= r){
            int m = l+(r-l)/2;
            if(helper(m) <= n){
                ans = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return ans;
    }
};