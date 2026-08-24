class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        if (length >= 1e4 || width >= 1e4 || height >= 1e4 ||
            1LL * length * width * height >= 1e9) {
            if (mass >= 100) {
                return "Both";
            }
            return "Bulky";
        } else if (mass >= 100) {
            return "Heavy";
        }
        return "Neither";
    }
};