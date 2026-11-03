class Solution {
    public int minMoves(int[] nums) {
        int n = nums.length;
        int mx = Integer.MIN_VALUE;
        for(int i=0; i<n; i++){
            mx = Math.max(mx,nums[i]);
        }
        int ans = 0;
        for(int num : nums){
            ans += (mx-num);
        }
        return ans;
    }
}