class Solution {
public:
    vector<vector<int>>adj;
    int n;
    vector<int>tin,tout,eulorTour;
    int timer;
    vector<int>t;
    vector<vector<int>>ancestor;
    int cols;
    vector<int>depth;
    void build(int idx, int l, int r, vector<int>& nums){
        if(l == r){
            t[idx] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(2*idx+1, l, mid, nums);
        build(2*idx+2, mid+1, r, nums);
        t[idx] = t[2*idx+1] ^ t[2*idx+2];
    }

    void update(int pos, int val, int idx, int l, int r){
        if(l == r){
            t[idx] = val;
            return;
        }

        int mid = l+(r-l)/2;
        if(pos <= mid){
            update(pos,val,idx*2+1,l,mid);
        }
        else{
            update(pos,val,idx*2+2,mid+1,r);
        }
        t[idx] = t[idx*2+1] ^ t[idx*2+2];
    }

    int query(int start, int end, int idx, int l, int r){
        if(l > end || r < start) return 0;
        if(l >= start && r <= end) return t[idx];
        int mid = l+(r-l)/2;
        return query(start,end,2*idx+1,l,mid)^query(start,end,idx*2+2,mid+1,r);
    }

    void dfs(int node, int parent, int d, string& s){
        depth[node] = d;
        ancestor[node][0] = parent;
        tin[node] = timer;
        eulorTour[timer] = (1 << (s[node] - 'a'));  // "a" = 001, "b" = 0101  // entering
        timer++;
        for(int &child : adj[node]){
            if(child == parent) continue;
            dfs(child,node,d+1,s);
        }
        tout[node] = timer;
        eulorTour[timer] = (1 << (s[node] - 'a')); //leaving
        timer++;
    }

    void buildAncestor(){
        for(int j=1; j<cols; j++){
            for(int node=0; node<n; node++){
                if(ancestor[node][j-1] != -1){
                    ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
                }
            }
        }
    }

    int getLCA(int u, int v){
        if(depth[u] < depth[v]){
            swap(u,v);
        }
        int diff = depth[u]-depth[v];
        for(int j=0; j<cols; j++){
            if(diff & (1 << j)){
                u = ancestor[u][j];
            }
        }

        if(u == v) return u;

        for(int j=cols-1; j>=0; j--){
            if(ancestor[u][j] == -1) continue;
            if(ancestor[u][j] != ancestor[v][j]){
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }

        return ancestor[u][0];
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.resize(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        eulorTour.assign(2 * n, 0);
        depth.assign(n, 0);
        timer = 0;
        cols = log2(n) + 1;
        ancestor.assign(n, vector<int>(cols, -1));
        dfs(0, -1, 0, s);
        int N = 2 * n;
        t.assign(4 * N, 0);
        build(0, 0, N - 1, eulorTour);
        buildAncestor();
        vector<bool>ans;
        for(string &q : queries){
            stringstream ss(q);
            string type;
            ss >> type;
            if(type == "update"){
                int node;
                char c;
                ss >> node >> c;
                int charValue = 1 << (c-'a');
                s[node] = c;
                update(tin[node], charValue, 0, 0, 2*n-1);
                update(tout[node], charValue, 0, 0, 2*n-1);
            }
            else{
                int u,v;
                ss >> u >> v;
                int lca = getLCA(u,v);
                char ch = s[lca];
                int charValue = (1 << (ch-'a'));
                int mask = query(0,tin[u],0,0,2*n-1) ^ query(0,tin[v],0,0,2*n-1) ^ charValue;
                ans.push_back((mask & (mask-1)) == 0);
            }
        }
        return ans;
    }
};