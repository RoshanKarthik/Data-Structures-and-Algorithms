class Solution {
private:
    vector<string>ans;
    void rec(int open, int close, int n, string &t){
        //pruning
        if(open < close) return;
        if(open == n && close == n){
            ans.push_back(t);
            return;
        }
        //compute
        if(open < n){
            t += '(';
            rec(open+1,close,n,t);
            t.pop_back();
        } 
        if(close < n){
            t += ')';
            rec(open,close+1,n,t);
            t.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string t = "";
        rec(0,0,n,t);
        return ans;
    }
};