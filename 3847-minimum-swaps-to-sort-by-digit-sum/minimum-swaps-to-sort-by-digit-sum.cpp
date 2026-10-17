class Solution {
private:
    int digitSum(int x){
        int sum = 0;
        while(x > 0){
            int ld = x%10;
            sum += ld;
            x/=10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]] = i;
        }
        vector<int>after(nums);
        sort(after.begin(),after.end(),[&](int a, int b){
            if(digitSum(a) != digitSum(b)){
                return digitSum(a) < digitSum(b);
            }
            return a < b;
        });


        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int expected = after[i];
            int curr = nums[i];

            if(expected == curr) continue;

            int idx = mpp[expected];
            nums[i] = expected;
            nums[idx] = curr;
            cnt++;
            mpp[expected] = i;
            mpp[curr] = idx;
        }

        return cnt;
    }
};