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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet du(n);
        unordered_map<string,int>mail_to_node;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mail_to_node.find(mail) == mail_to_node.end()){
                    mail_to_node[mail] = i;
                }
                else{
                    du.union_set_Size(i,mail_to_node[mail]);
                }
            }
        }

        vector<vector<string>>merge_emails(n);
        for(auto &it : mail_to_node){
            string mail = it.first;
            int node = du.find_set(it.second);
            merge_emails[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0; i<n; i++){
            if(merge_emails[i].size() == 0) continue;
            sort(merge_emails[i].begin(),merge_emails[i].end());
            vector<string>tmp;
            tmp.push_back(accounts[i][0]);
            for(auto &mails : merge_emails[i]){
                tmp.push_back(mails);
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};