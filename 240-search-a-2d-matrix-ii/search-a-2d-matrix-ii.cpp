class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0;
        int c = m-1;
        while(r < n && c > -1){
            int curr = matrix[r][c];
            if(curr == target) return true;
            if(curr < target) r++;
            else c--;
        }
        return false;
    }
};