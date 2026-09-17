class Solution {
private:
    int reverse(int n){
        int ans = 0;
        while(n!=0){
            int digit = n%10;
            n /= 10;
            ans = ans*10+digit;
        }
        return ans;
    }
public:
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int l = min(n,rev);
        int r = max(n,rev);

        vector<int>is_prime(1001,1);
        is_prime[0] = 0;
        is_prime[1] = 0;
        for (int i = 2; i * i < 1001; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j < 1001; j += i) {
                    is_prime[j] = 0;
                }
            }
        }

        int sum = 0;
        for(int i=l; i<=r; i++){
            if(is_prime[i]){
                sum += i;
            }
        }
        return sum;

    }
};