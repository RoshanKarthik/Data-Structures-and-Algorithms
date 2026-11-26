class Solution {
public:
    bool canAliceWin(int n) {
        int steps = 0;
        int take = 10;
        while(n >= take){
            n -= take;
            steps++;
            take--;
        }
        return (steps&1);
    }
};