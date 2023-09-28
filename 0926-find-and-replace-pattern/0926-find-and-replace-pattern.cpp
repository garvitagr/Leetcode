class Solution {
public:
    string abc(string s){
        char mapping[260]={0};
        char st='a';
        for(int i=0;i<s.size();i++){
            if(mapping[s[i]]==0)mapping[s[i]]=st++;
            s[i]=mapping[s[i]];
        }
        return s;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        pattern=abc(pattern);
        int i;
        string temp;
        for(i=0;i<words.size();i++){
            temp=abc(words[i]);
            if(temp==pattern)ans.push_back(words[i]);
        }
        return ans;
    }
};