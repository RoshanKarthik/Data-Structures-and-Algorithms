class Solution {
    public int maxFrequencyElements(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer>map = new HashMap<>();
        for(int num : nums){
            map.put(num,map.getOrDefault(num,0)+1);
        }
        int maxi = 0;
        for(int num : nums){
            if(map.get(num) > maxi){
                maxi = map.get(num);
            }
        }

        int count = 0;
        for(Map.Entry<Integer,Integer>entry : map.entrySet()){
            if(entry.getValue() == maxi){
                count += entry.getValue();
            }
        }
        return count;
    }
}