#include<bits/stdc++.h>
using namespace std;
class DisJointSet{
public:
    vector<int> parent,rank,Size;
    int Components;
    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        Size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        Components = n;
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
        Components--;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet du(n);
        int extra_edges = 0;
        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];
            if(du.find_set(u) == du.find_set(v)){
                extra_edges++;
            }
            else{
                du.union_set_Size(u,v);
            }
        }
        
        int ans = du.Components-1;
        if(extra_edges >= ans) return ans;
        return -1;

    }
};