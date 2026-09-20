class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            int x = 26 - (s[i]-'a');
            cout << x << " ";
            int y = x * (i+1);
            
            ans += y;
        }
        return ans;
    }
};