class Solution {
    private void rec(StringBuilder s, int open, int close, int n, List<String> ans){
        if(s.length() == 2*n){
            ans.add(s.toString());
            return;
        }

        if(open < n){
            s.append('(');
            rec(s,open+1,close,n,ans);
            s.deleteCharAt(s.length()-1);
        }

        if(close < open){
            s.append(')');
            rec(s,open,close+1,n,ans);
            s.deleteCharAt(s.length()-1);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        StringBuilder s = new StringBuilder(2*n);
        rec(s,0,0,n,ans);
        return ans;
    }
}