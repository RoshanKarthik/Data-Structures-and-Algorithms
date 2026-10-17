class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        for(int i=0; i<n; i++){
            matrix[i][i] = 0;
        }
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int cityNo = -1;
        int minCount = n;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= minCount){
                minCount = count;
                cityNo = i;
            }
        }

        return cityNo;
    }
};