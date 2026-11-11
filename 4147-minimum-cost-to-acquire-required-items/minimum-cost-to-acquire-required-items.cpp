using ll = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll ans,min,max;
        min = fmin(need1,need2);
        max = fmax(need1,need2);
        ans = (ll) need1 * cost1 + (ll) need2 * cost2;
        ans = fmin(ans,(ll)costBoth * min + (ll) (need1 - min) * cost1 + (ll) (need2 - min) * cost2);
        ans = fmin(ans,(ll)costBoth * max);
        return ans;
    }
};