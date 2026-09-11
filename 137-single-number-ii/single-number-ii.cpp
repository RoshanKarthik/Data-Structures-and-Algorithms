class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int twos = 0;
        for(int i=0; i<n; i++){
            cout << "index: " << i << " ";
            ones^=nums[i]&~twos;
            cout << "ones: " << ones << " ";
            twos^=nums[i]&~ones;
            cout << "twos: " << twos << endl;
        }
        return ones;
    }
};