using ll = long long;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        ll total_pairs = 0;
        ll good_pairs = 0;
        unordered_map<int,int>mpp;
        for(int i=0; i<n; i++){
            total_pairs += i;
            good_pairs += mpp[nums[i]-i];
            mpp[nums[i]-i]++;
        }
        return total_pairs-good_pairs;
    }
};