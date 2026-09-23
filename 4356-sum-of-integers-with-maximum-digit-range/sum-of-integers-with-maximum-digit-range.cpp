class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            int x = nums[i];
            string temp = to_string(x);
            sort(temp.begin(),temp.end());
            ans[i] = (temp[temp.size()-1]-'0') - (temp[0]-'0');
            maxi = max(ans[i],maxi);
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            if(ans[i] == maxi){
                sum += nums[i];
            }
        }
        return sum;
    }
};