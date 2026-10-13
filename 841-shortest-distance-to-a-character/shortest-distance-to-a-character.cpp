
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, INT_MAX);
        int j = -n;

        // Left to right
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                j = i;
            }
            ans[i] = i - j;
        }

        j = 2 * n;

        // Right to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                j = i;
            }
            ans[i] = min(ans[i], j - i);
        }

        return ans;
    }
};
