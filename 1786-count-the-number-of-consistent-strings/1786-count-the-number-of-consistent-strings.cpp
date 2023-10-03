class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        char hash[26]={0};
        int i,j,ans=0,ct;
        for(i=0;i<allowed.size();i++){
            hash[allowed[i]-'a']++;
        }
        for(i=0;i<words.size();i++){
            ct=0;
            for(j=0;j<words[i].size();j++){
                if(hash[words[i][j]-'a']!=0)ct++;
                else break;
            }
            if(ct==words[i].size())ans++;
        }
        return ans;
    }
};