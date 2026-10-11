class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int>s;
        for(int x : nums){
            s.insert(x);
        }
        for(auto it : s){
            if(s.find(it-1) == s.end()){
                int x = it;
                int count = 1;
                while(s.find(x+1) != s.end()){
                    count++;
                    x++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};