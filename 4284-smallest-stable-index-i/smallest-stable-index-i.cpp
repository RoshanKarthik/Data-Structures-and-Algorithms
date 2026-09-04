class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>a(n),b(n);

        a[0] = nums[0];
        for(int i=1; i<n; i++){
            a[i] = max(nums[i],a[i-1]);
        }
        b[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            b[i] = min(b[i+1],nums[i]);
        }
        for(int i=0; i<n; i++){
            int score = a[i]-b[i];
            if(score <= k) return i;
        }
        return -1;
    }
};