using ll = long long;
class Solution {
private:
    bool possible(vector<int>&nums, int mid, int k){
        ll sum = 0;
        int nos = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > mid) return false;
            if(nums[i] + sum > mid){
                sum = 0;
                nos++;
            }
            sum += nums[i];
        }
        return nos <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        ll low = *max_element(nums.begin(),nums.end());
        ll high = accumulate(nums.begin(),nums.end(),0LL);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(nums,mid,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};