class DisJointSet{
public:
    vector<int>size;
    vector<int>rank;
    vector<int>parent;
    int components;
    DisJointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        components = n;
    }

    int find_set(int u){
        if(parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }

    void union_by_size(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if(u == v) return;
        if(size[u] < size[v]){
            swap(u,v);
        }
        parent[v] = u;
        components--;
        size[u] += size[v];
    }

    void union_by_rank(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if(u == v) return;
        if(rank[u] < rank[v]){
            swap(u,v);
        }
        parent[v] = u;
        components--;
        if(rank[u] == rank[v]){
            rank[u]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJointSet du(n);
        int components;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(isConnected[i][j] == 1){
                    du.union_by_size(i,j);
                }
            }
        }
        return du.components;
    }
};