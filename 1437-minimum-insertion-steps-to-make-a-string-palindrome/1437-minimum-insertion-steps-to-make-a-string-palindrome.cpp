class Solution {
public:
    int helper(string &s,int st,int end,vector<vector<int>>&dp){
        if(st>=end)return 0;
        if(dp[st][end]!=-1)return dp[st][end];
        if(s[st]==s[end])return dp[st][end]=helper(s,st+1,end-1,dp);
        else {
            int left=1+helper(s,st,end-1,dp);
            int right=1+helper(s,st+1,end,dp);
            return dp[st][end]=min(left,right);
        }
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return helper(s,0,s.size()-1,dp);
    }
};