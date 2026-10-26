class Solution {
    private int ma(int[] nums){
        int mx = Integer.MIN_VALUE;
        for(int i=0; i<26; i++){
            if(nums[i] > 0){
                mx = Math.max(mx,nums[i]);
            }
        }
        return mx;
    }
    private int mi(int[] nums){
        int mn = Integer.MAX_VALUE;
        for(int i=0; i<26; i++){
            if(nums[i] > 0){
                mn = Math.min(mn,nums[i]);
            }
        }
        return mn;
    }
    public int beautySum(String s) {
        int n = s.length();
        int sum = 0;
        for(int i=0; i<n; i++){
            int[] freq = new int[26];
            for(int j=i; j<n; j++){
                freq[s.charAt(j)-'a']++;
                int beauty = ma(freq) - mi(freq);
                sum += beauty;
            }
        }
        return sum;
    }
}