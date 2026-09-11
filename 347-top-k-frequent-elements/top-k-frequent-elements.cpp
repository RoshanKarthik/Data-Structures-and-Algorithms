class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;

        for(int x : nums){
            mpp[x]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(mpp[a] == mpp[b])
                return a > b;

            return mpp[a] > mpp[b];
        });

        int count = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                ans.push_back(nums[i-1]);
                count++;
            }

            if(count == k)
                break;
        }
        // Add the last unique element
        if(count < k){
            ans.push_back(nums[n-1]);
        }

        return ans;
    }
};