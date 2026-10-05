class Solution {
private:
    vector<int>index;
    vector<int>count;
    void merge(vector<int> &nums, int low, int mid, int high){
        vector<int>temp;
        int i = low;
        int j = mid+1;
        int rightCount = 0;
        while(i <= mid && j <= high){
            if(nums[index[j]] < nums[index[i]]){
                rightCount++;
                temp.push_back(index[j]);
                j++;
            }
            else{
                count[index[i]] += rightCount;
                temp.push_back(index[i]);
                i++;
            }
        }
        while(i <= mid){
            count[index[i]] += rightCount;
            temp.push_back(index[i]);
            i++;
        }
        while(j <= high){
            temp.push_back(index[j]);
            j++;
        }
        for(int i=low; i<=high; i++){
            index[i] = temp[i-low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        //basecase
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.assign(n,0);
        index.resize(n);
        for(int i=0; i<n; i++){
            index[i] = i;
        }
        mergeSort(nums,0,n-1);
        return count;
    }
};