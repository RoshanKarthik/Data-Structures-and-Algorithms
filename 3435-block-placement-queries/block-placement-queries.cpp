class Solution {
private:
    int n;
    vector<int>t;
    void update(int idx, int val, int i, int l, int r){
        if(l == r){
            t[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid) update(idx, val, 2*i+1, l, mid);
        else update(idx, val, 2*i+2, mid+1, r);
        t[i] = max(t[2*i+1], t[2*i+2]);
    }
    int q(int start, int end, int i, int l, int r){
        if(l > end || r < start){
            return 0;
        }

        if(l >= start && r <= end){
            return t[i];
        }

        int mid = l + (r-l)/2;
        return max(q(start,end,2*i+1,l,mid), q(start,end,2*i+2,mid+1,r));
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        n = 50000;
        t.resize(4*n,0);
        set<int>st;
        st.insert(0);
        vector<bool> result;
        for(auto &query : queries){
            if(query[0] == 1){
                int x = query[1];
                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1;
                int pre = *prev(it);
                update(x,x-pre,0,0,n-1);
                update(nxt,nxt-x,0,0,n-1);
                st.insert(x);
            }
            else{
                int x = query[1];
                int sz = query[2];
                auto it = st.upper_bound(x);
                int pre = *prev(it);
                int maxGap = q(0,pre,0,0,n-1);
                int best = max(maxGap, x-pre);
                result.push_back(best >= sz);
            }
        }
        return result;
    }
};