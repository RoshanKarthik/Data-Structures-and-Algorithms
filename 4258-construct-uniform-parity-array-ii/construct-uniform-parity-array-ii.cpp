class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int small = *min_element(nums1.begin(),nums1.end());
        int ec = 0;
        for(int x : nums1){
            if(x%2==0){
                ec++;
            }
        }
        if(ec == n) return true;
        if(small & 1){
            return true;
        }
        return false;
    }
};