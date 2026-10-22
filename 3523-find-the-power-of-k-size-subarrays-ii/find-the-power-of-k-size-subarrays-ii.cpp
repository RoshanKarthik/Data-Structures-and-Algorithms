class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>result;
        deque<int>d;
        for(int i=0; i<n; i++){
            if(d.size() == k){
                d.pop_front();
            }
            if(!d.empty() && d.back() != nums[i]-1){
                d.clear();
            }
            d.push_back(nums[i]);
            if(i>=k-1){
                if(d.size() == k){
                    result.push_back(d.back());
                }
                else{
                    result.push_back(-1);
                }
            }
        }
        return result;
    }
};