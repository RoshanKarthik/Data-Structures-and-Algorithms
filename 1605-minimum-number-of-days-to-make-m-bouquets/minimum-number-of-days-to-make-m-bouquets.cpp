using ll = long long;
class Solution {
private:
    bool func(vector<int>& bloomDay, int mid, int m, int k){
        int n = bloomDay.size();
        int count = 0;
        int b = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=mid){
                count++;
                if(count==k){
                    b++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return b>=m;
        
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll val = m * 1LL * k * 1LL;
        if(bloomDay.size() < val) return -1;
        ll low = *min_element(bloomDay.begin(),bloomDay.end());
        ll high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low <= high){
            ll mid = low+(high-low)/2;
            if(func(bloomDay,mid,m,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;

    }
};
