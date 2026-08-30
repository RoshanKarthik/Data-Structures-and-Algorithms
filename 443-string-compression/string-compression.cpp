class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        for (int i = 0; i < chars.size();) {
            const char letter = chars[i]; 
            int count = 1;
            while (i+1 < chars.size() && chars[i+1] == letter) {
                ++count;
                ++i;
            }
            chars[ans++] = letter;
            if (count > 1) {
                for (const char c : to_string(count)) {
                    chars[ans++] = c;
                }
            }
            i++;
        }
        return ans;
    }
};