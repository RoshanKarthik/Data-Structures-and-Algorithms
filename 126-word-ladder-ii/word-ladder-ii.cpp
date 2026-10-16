class Solution {
private:
    void dfs(string word, vector<string>&seq, string &beginWord, unordered_map<string,int>&mpp, vector<vector<string>>&ans){
        if(word == beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i=0; i<word.size(); i++){
            char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(mpp.find(word) != mpp.end() && mpp[word] == steps-1){
                        seq.push_back(word);
                        dfs(word,seq,beginWord,mpp,ans);
                        seq.pop_back();
                    }
                }
                word[i] = original; 
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>ans;
        unordered_map<string,int>mpp;
        queue<string>q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int level = mpp[word];
            if(word == endWord) break;
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        mpp[word] = level + 1;
                        st.erase(word);
                        q.push(word);
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.find(endWord) != mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord, mpp, ans);
        }
        return ans;
    }
};