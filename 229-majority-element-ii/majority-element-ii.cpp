class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--; cnt2--;
            }
        }
        
        vector<int>ans;
        int x = n/3;
        int c1=0,c2=0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele1) c1++;
            if(nums[i] == ele2) c2++;
        }
        if(c1 > x) ans.push_back(ele1);
        if(c2 > x) ans.push_back(ele2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};