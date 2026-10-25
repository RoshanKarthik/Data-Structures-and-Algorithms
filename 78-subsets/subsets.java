class Solution {
    private void rec(int i, List<Integer> temp, int[] nums, List<List<Integer>> ans){
        if(i == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        rec(i+1,temp,nums,ans);
        temp.add(nums[i]);
        rec(i+1,temp,nums,ans);
        temp.remove(temp.size()-1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        List<Integer> temp = new ArrayList<>();
        rec(0,temp,nums,ans);
        return ans;
    }
}