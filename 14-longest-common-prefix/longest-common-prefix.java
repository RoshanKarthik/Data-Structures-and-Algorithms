class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";
        Arrays.sort(strs);
        int n = strs.length;
        String first = strs[0];
        String last = strs[n-1];
        StringBuilder res = new StringBuilder();
        for(int i=0; i<Math.min(first.length(),last.length()); i++){
            if(first.charAt(i) != last.charAt(i)) break;
            res.append(first.charAt(i));
        }
        return res.toString();
    }
}