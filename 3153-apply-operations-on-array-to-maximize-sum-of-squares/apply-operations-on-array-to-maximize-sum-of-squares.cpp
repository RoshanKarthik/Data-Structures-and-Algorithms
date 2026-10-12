class Solution {
const int mod = 1e9+7;
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>Count(32,0);
        for(int &num : nums){
            for(int i=0; i<32; i++){
                if(num & (1<<i)){
                    Count[i]++;
                }
            }
        }
        long long result = 0;
        while(k--){
            long long curr = 0;
            for(int i=0; i<32; i++){
                if(Count[i]>0){
                    Count[i]--;
                    curr = (curr | (1<<i));
                }
            }
            result = (result + (curr*curr)) % mod;
        } 
        return result;
    }
};