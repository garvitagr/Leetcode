class Solution {
public:

    int helper(int ind,string &s,map<string,int>&mp,vector<int>&dp){
        if(ind==s.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=0;
        string temp;
        ans=1+helper(ind+1,s,mp,dp);
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(mp.find(temp)!=mp.end())ans=min(ans,helper(i+1,s,mp,dp));
        }
        return dp[ind]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int>mp;
        vector<int>dp(s.size()+1,-1);
        for(int i=0;i<dictionary.size();i++)mp[dictionary[i]]++;
        return helper(0,s,mp,dp);
    }
};