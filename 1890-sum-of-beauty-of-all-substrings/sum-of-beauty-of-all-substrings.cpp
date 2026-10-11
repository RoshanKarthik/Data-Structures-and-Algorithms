
class Solution {
private:
    int ma(vector<int>& arr) {
        int maxi = 0;
        for (int i = 0; i < 26; i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    int mi(vector<int>& arr) {
        int mini = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                mini = min(mini, arr[i]);
            }
        }
        return mini;
    }

public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            vector<int> arr(26, 0);

            for (int j = i; j < n; j++) {
                arr[s[j] - 'a']++;

                int beauty = ma(arr) - mi(arr);
                sum += beauty;
            }
        }

        return sum;
    }
};
