class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        Map<Character,Integer> mpp = new HashMap<>();
        for(char c : s.toCharArray()){
            mpp.put(c,mpp.getOrDefault(c,0)+1);
        }
        for(char c : t.toCharArray()){
            mpp.put(c,mpp.getOrDefault(c,0)-1);
            if(mpp.get(c) < 0) return false;
        }
        return true;
    }
}