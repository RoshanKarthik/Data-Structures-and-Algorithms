class Solution {
private:
    bool canForm(vector<int>& cnt, string& target, int start){
        string maxStr = maxString(cnt);
        string currStr = target.substr(start);
        return maxStr > currStr;
    }

    string maxString(vector<int>& cnt){
        string res;
        for(int i=25; i>=0; i--){
            res.append(cnt[i],i+'a');
        }
        return res;
    }

    string minString(vector<int>& cnt){
        string res;
        for(int i=0; i<26; i++){
            res.append(cnt[i],i+'a');
        }
        return res;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        vector<int>cnt(26);
        for(char c : s){
            cnt[c-'a']++;
        }
        string res;
        for(int i=0; i<n; i++){
            int targetChar = target[i]-'a';
            if(cnt[targetChar] > 0){
                cnt[targetChar]--;
                if(canForm(cnt,target,i+1)){
                    res.push_back(target[i]);
                    continue;
                }
                cnt[targetChar]++;
            }
            for(int j=targetChar+1; j<26; j++){
                if(cnt[j] > 0){
                    cnt[j]--;
                    res.push_back(j +'a');
                    res += minString(cnt);
                    return res;
                }
            }
            return "";
        }
        return "";
    }
};