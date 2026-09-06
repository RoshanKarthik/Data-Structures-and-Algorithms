class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        if(n <= 1) return n;
        vector<int>leaders;
        for(int i=0; i<n; i++){
            if(i+1<n && position[i+1]-position[i] <= distance){
                continue;
            }
            leaders.push_back(i);
        }
        int groups = 1;
        int current_leader = leaders.back();
        for(int i=leaders.size()-2; i>=0; i--){
            int u = leaders[i];
            if(speed[u] > speed[current_leader]){
                continue;
            }
            groups++;
            current_leader = u;
        }
        return groups;
    }
};