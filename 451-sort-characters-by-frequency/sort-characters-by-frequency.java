class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> mpp = new HashMap<>();
        for (char c : s.toCharArray()) {
            mpp.put(c, mpp.getOrDefault(c, 0) + 1);
        }

        Character[] arr = new Character[s.length()];
        for (int i = 0; i < s.length(); i++) {
            arr[i] = s.charAt(i);
        }

        Arrays.sort(arr, (a, b) -> {
            if (mpp.get(a).equals(mpp.get(b)))
                return a.compareTo(b);
            return mpp.get(b) - mpp.get(a);
        });

        StringBuilder res = new StringBuilder();
        for (char c : arr) {
            res.append(c);
        }

        return res.toString();
    }
}