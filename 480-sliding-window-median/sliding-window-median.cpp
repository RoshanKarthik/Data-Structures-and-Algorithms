class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int>left,right;
        vector<double>ans;
        int i=0,j=0;
        while(j<n){
            if(left.size() <= right.size()){
                left.insert(nums[j]);
            }
            else{
                right.insert(nums[j]);
            }

            if(!left.empty() && !right.empty()) {
                int maxLeft  = *left.rbegin();
                int minRight = *right.begin();
                if(maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));
                    left.insert(minRight);
                    right.insert(maxLeft);
                }
            }

            if(j-i+1 == k){
                int l = *left.rbegin();
                int r = *right.begin();
                if(k&1){
                    ans.push_back((double)l);
                }
                else{
                    double m = ((double)l+(double)r)/2.0;
                    ans.push_back(m);
                }

                if(left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                }
                else {
                    right.erase(right.find(nums[i]));
                }
                i++;
            }
            j++;

        }
        return ans;
    }
};