class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(),logs.end(),[&](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int q = queries.size();

        vector<int>ans(q);

        vector<pair<int,int>>Queries(q);
        
        for(int i=0; i<q; i++){
            Queries[i] = {queries[i],i};
        }

        sort(Queries.begin(),Queries.end());

        unordered_map<int,int>mpp;

        int i=0;
        int j=0;

        for(auto [time, idx] : Queries){

            int start = time-x;
            int end = time;

            while(j<logs.size() && logs[j][1] <= end){
                mpp[logs[j][0]]++;
                j++;
            }

            while(i<logs.size() && logs[i][1] < start){
                mpp[logs[i][0]]--;
                if(mpp[logs[i][0]] == 0){
                    mpp.erase(logs[i][0]);
                }
                i++;
            }

            ans[idx] = n-mpp.size();
        }

        return ans;

    }
};