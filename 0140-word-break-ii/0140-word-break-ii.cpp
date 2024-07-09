class Solution {
public:
    map<int,vector<string>>dp;
    vector<string> helper(string &s,map<string,int>&mp,int ind){
        if(ind==s.size())return {""};
        if(dp.count(ind))return dp[ind];
        string temp="";
        vector<string>ans;
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(mp[temp]){                
                vector<string>stringahead=helper(s,mp,i+1);
                for(auto it:stringahead){
                    string add;
                    if(it.size())add=temp+" "+it;
                    else add=temp;                    
                    ans.push_back(add);
                }
            }
        }
        return dp[ind]=ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(int i=0;i<wordDict.size();i++)mp[wordDict[i]]++;
        vector<string>ans;
        string temp;
        return helper(s,mp,0);
    }
};