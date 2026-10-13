class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        sort(nums.begin(),nums.end(),[&](int a, int b){
            return abs(a) > abs(b);
        });
        for(int x : nums){
            cout << x << " ";
        }
        if(n%2==0){
            for(int i=0; i<n; i++){
                if(i<n/2) sum += (1LL*nums[i]*nums[i]);
                else sum -= (1LL*nums[i]*nums[i]);
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(i<=n/2) sum += (1LL*nums[i]*nums[i]);
                else sum -= (1LL*nums[i]*nums[i]);
            }
        }
        return sum;
    }
};