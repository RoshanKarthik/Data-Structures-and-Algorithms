class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();
        int l = -1;
        for(int i=n-1; i>=0; i--){
            int d = num.charAt(i)-'0';
            if(d % 2 == 1){
                l = i;
                break;
            }
        }

        int i=0;
        while(i<n && num.charAt(i) == '0') i++;
        if(l == -1) return "";
        return num.substring(i,i+(l-i+1));
    }
}