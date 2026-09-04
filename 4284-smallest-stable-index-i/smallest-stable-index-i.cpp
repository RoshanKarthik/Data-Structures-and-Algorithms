class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>b(n);
        b[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            b[i] = min(b[i+1],nums[i]);
        }
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);
            cout << maxi << " ";
            int score = maxi-b[i];
            if(score <= k) return i;
        }
        return -1;
    }
};