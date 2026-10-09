class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int count = 0;
        int i=0;
        int ans = 0;
        while(i<n){
            if(s[i] == '(') {
                count++;
                i++;
            }
            else{
                if(count > 0){
                    count--;
                }
                else{
                    ans++;
                }
                if(i+1 < n && s[i+1] == ')'){
                    i += 2;
                }
                else{
                    ans++;
                    i++;
                }
            }
        }

        return ans + (count*2);
    }
};