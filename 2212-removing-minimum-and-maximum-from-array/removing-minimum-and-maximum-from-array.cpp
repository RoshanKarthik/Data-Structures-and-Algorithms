class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mx = max_element(nums.begin(),nums.end())-nums.begin();
        int mn = min_element(nums.begin(),nums.end())-nums.begin();
        int a = max(mx+1,mn+1);
        int b = max(n-mx,n-mn);
        if(mx > mn) swap(mx,mn);
        int c = mx+1 + (n-mn);
        cout << a << " " << b << " " << c;
        return min({a,b,c});
    }
};