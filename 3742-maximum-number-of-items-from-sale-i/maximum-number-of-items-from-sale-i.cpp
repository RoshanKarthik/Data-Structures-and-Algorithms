class Solution {
private:
    int n;
    int dp[1005][1505];
    int rec(int idx, int budget, vector<vector<int>>& items, vector<int>& copies, int minPrice){
        if(idx == n){
            return budget/minPrice;
        }
        if(dp[idx][budget] != -1) return dp[idx][budget];
        int take = 0;
        int skip = 0;
        int price = items[idx][1];
        if(price <= budget){
            take = 1 + copies[idx] + rec(idx+1,budget-price,items,copies,minPrice);
        }
        skip = rec(idx+1,budget,items,copies,minPrice);
        return dp[idx][budget] = max(take,skip);
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        vector<int>copies(n,0);
        int minPrice = INT_MAX;
        for(int i=0; i<n; i++){
            minPrice = min(minPrice,items[i][1]);
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(items[j][0] % items[i][0] == 0){
                    copies[i]++;;
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,budget,items,copies,minPrice);
        
    }
};