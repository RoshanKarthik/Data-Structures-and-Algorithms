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
    bool isValid(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJointSet du(n*n);
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                for(int d=0; d<4; d++){
                    int ni = drow[d] + i;
                    int nj = dcol[d] + j;
                    if(isValid(ni,nj,n) && grid[ni][nj] == 1){
                        int nn = i*n+j;
                        int an = ni*n+nj;
                        if(du.find_set(nn) != du.find_set(an)){
                            du.union_set_Size(nn,an);
                        }
                    }
                }
            }
        }

        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;
                unordered_set<int>st;
                for(int d=0; d<4; d++){
                    int ni = drow[d] + i;
                    int nj = dcol[d] + j;
                    if(isValid(ni,nj,n) && grid[ni][nj] == 1){
                        int an = ni*n+nj;
                        st.insert(du.find_set(an));
                    }
                }
                int count = 0;
                for(auto it : st){
                    count += du.Size[it];
                }
                mx = max(mx,count+1);
            }
        }
        for(int i=0; i<n*n; i++){
            mx = max(mx,du.Size[du.find_set(i)]);
        }

        return mx;
    }
};