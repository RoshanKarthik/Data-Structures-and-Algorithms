class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int moreneeded = target - num;
            if(mpp.find(moreneeded)!=mpp.end()){
                return{mpp[moreneeded],i};
            }
            mpp[num] = i;
        }
        return{};
    }
};