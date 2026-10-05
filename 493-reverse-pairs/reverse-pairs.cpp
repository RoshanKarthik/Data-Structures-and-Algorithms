class Solution {
private:
    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int>temp;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=high){
            temp.push_back(arr[j++]);
        }
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }
    int countPairs(vector<int>& arr, int low, int mid, int high){
        int cnt = 0;
        int right = mid+1;
        for(int left = low; left <= mid; left++){
            while(right <= high && arr[left] > 1LL*2*arr[right]){
                right++;
            }
            cnt = cnt + (right - (mid+1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid+1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};