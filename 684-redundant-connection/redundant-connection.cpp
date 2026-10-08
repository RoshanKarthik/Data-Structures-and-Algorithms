#include<bits/stdc++.h>
using namespace std;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisJointSet du(edges.size());
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            if(du.find_set(u) == du.find_set(v)){
                return {u,v};
            }
            du.union_set_Size(u,v);
        }
        return {};
    }
};