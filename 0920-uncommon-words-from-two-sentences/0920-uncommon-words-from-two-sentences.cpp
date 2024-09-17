class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp1,mp2;
        vector<string>ans;
        string s;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                mp1[s]++;
                s="";
            }
            else s+=s1[i];
        }
        mp1[s]++;
        s="";
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                mp2[s]++;
                s="";
            }
            else s+=s2[i];
        }
        mp2[s]++;
        for(auto it:mp1){
            if(it.second==1 and mp2[it.first]==0)ans.push_back(it.first);
        }
        for(auto it:mp2){
            if(it.second==1 and mp1[it.first]==0)ans.push_back(it.first);
        }
        return ans;
    }
};