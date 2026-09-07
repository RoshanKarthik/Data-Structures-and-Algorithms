class Solution {
private:
    bool possible(vector<int>& weights, int mid, int days){
        int d = 1;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            if(weights[i] > mid) return false;
            if(sum + weights[i] > mid){
                d++;
                sum = 0;
            }
            sum += weights[i];
        }
        return d<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid = low+(high-low)/2;
            if(possible(weights,mid,days)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};