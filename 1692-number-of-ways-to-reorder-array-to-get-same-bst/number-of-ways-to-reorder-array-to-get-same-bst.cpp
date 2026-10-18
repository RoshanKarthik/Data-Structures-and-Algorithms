using ll = long long;
class Solution {
private:
    const ll mod = 1e9+7;
    vector<vector<ll>>PT;
    ll solve(vector<int>& nums){
        int n = nums.size();
        if(n<3) return 1;
        vector<int>left_array,right_array;
        int root = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] < root){
                left_array.push_back(nums[i]);
            }
            else{
                right_array.push_back(nums[i]);
            }
        }

        ll x = solve(left_array);
        ll y = solve(right_array);
        ll z = PT[n-1][left_array.size()];
        return ((x*y)%mod*z)%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        PT.resize(n+1);
        for(int i=0; i<=n; i++){
            PT[i] = vector<ll>(i+1,1);
            for(int j=1; j<i; j++){
                PT[i][j] = (PT[i-1][j] + PT[i-1][j-1])%mod; 
            }
        }
        return ((solve(nums)-1)+mod)%mod;
    }
};