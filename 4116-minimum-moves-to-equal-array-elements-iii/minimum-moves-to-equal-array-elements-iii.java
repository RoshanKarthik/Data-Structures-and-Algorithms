class Solution {
    public int minMoves(int[] nums) {
        int n = nums.length;
        int mx = Integer.MIN_VALUE;
        int sum = 0;
        for(int num : nums){
            sum += num;
            mx = Math.max(mx,num);
        }
        return mx*n-sum;
    }
}