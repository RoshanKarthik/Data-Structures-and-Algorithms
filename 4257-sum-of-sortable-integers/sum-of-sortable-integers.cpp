class Solution {
private:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i=1; i<n; i++){
            if(arr[i]<arr[i-1]){
                count++;
            }
        }
        if(arr[n-1]>arr[0]){
            count++;
        }
        return count > 1? false : true;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int>divisors;
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                divisors.push_back(i);
                if(i*i != n){
                    divisors.push_back(n/i);
                }
            }    
        }
        int sum = 0;
        for(int k : divisors){
            vector<int>temp;
            bool flag = true;
            int prevMax = -1;
            int prevMin = 1e9;
            int currMin = nums[0];
            int currMax = nums[0];
            for(int i=0; i<n; i++){
                temp.push_back(nums[i]);
                currMin = min(currMin,nums[i]);
                currMax = max(currMax,nums[i]);
                if((i+1) % k == 0){
                    if(!check(temp) || currMin < prevMax){
                        flag = false;
                        temp.clear();
                        break;
                    }
                    temp.clear();
                    prevMin = currMin;
                    prevMax = currMax;
                    currMin = 1e9;
                    currMax = -1;
                }
            }
            if(flag){
                sum += k;
            }
        }
        return sum;
    }
};