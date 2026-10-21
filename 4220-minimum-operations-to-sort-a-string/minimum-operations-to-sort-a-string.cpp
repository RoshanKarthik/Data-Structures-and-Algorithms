class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end())) return 0; 
        int n =s.size();  
        if(n == 2) return -1;
        int mx = 'a';
        int mn = 'z';
        for(char c : s){
            if(c>mx)mx=c;
            if(c<mn)mn=c;
        }

        if(s[0]==mn || s[n-1]==mx) return 1;
        for(int i=1; i<n-1; i++){
            if(s[i]==mn || s[i]==mx) return 2;
        }
        return 3;
    }
};



 