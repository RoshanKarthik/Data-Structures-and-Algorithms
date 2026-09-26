class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mpp;
        for(auto x : knowledge){
            mpp[x[0]] = x[1];
        }

        int n = s.size();
        string ans;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                int j = s.find(')',i+1);
                auto t = s.substr(i+1,j-i-1);
                ans += mpp.count(t) ? mpp[t] : "?";
                i=j;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};