class Solution {
private:
    int n;
    unordered_set<string>st;
    int maxLen;
    void rec(int i, string& s, string& curr, int count){
        if(count < 0) return;
        if(i == n){
            if(count == 0){
                if(curr.size() > maxLen){
                    maxLen = curr.size();
                    st.clear();
                }
                if(curr.size() == maxLen){
                    st.insert(curr);
                }
            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            rec(i+1,s,curr,count);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        rec(i+1,s,curr,count + (s[i] == '(' ? 1 : -1));
        curr.pop_back();
        rec(i+1,s,curr,count);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        st.clear();
        maxLen = 0;
        string curr = "";
        rec(0,s,curr,0);
        return vector<string>(st.begin(),st.end());
    }
};