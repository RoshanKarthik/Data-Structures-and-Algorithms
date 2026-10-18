class DisJointSet{
public:
    vector<int> parent,rank,Size;
    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        Size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find_set(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find_set(parent[u]);
    }

    void union_set_Size(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if(u==v) return;
        if(Size[u]<Size[v])
            swap(u,v);
        parent[v] = u;
        Size[u] += Size[v];
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRows = -1;
        int maxCols = -1;
        for(auto &it : stones){
            maxRows = max(maxRows,it[0]);
            maxCols = max(maxCols,it[1]);
        }

        DisJointSet du(maxRows+maxCols+1);
        unordered_map<int,int>mpp;
        for(auto &it : stones){
            int row = it[0];
            int col = it[1]+maxRows+1;
            du.union_set_Size(row,col);
            mpp[row] = 1;
            mpp[col] = 1;
        }

        int count = 0;
        for(auto &it : mpp){
            if(du.find_set(it.first) == it.first){
                count++;
            }
        }

        return n-count;
    }
};