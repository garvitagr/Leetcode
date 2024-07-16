class Solution {
public:
    
    int helper(string &s,int ind,int laststage,vector<vector<int>>&dp){
        if(ind==s.size())return 0;
        if(dp[ind][laststage]!=-1)return dp[ind][laststage];
        if(laststage==0){
            if(s[ind]=='0'){
                int zero=1+helper(s,ind+1,0,dp);
                int one=helper(s,ind+1,1,dp);
                return dp[ind][laststage]=min(zero,one);
            }
            else{
                int zero=1+helper(s,ind+1,0,dp);
                int one=2+helper(s,ind+1,1,dp);
                return dp[ind][laststage]=min(zero,one);
            }
        }
        else if(laststage==1){
            if(s[ind]=='0'){
                int one=helper(s,ind+1,1,dp);
                int two=1+helper(s,ind+1,2,dp);
                return dp[ind][laststage]=min(two,one);
            }
            else{
                int one=2+helper(s,ind+1,1,dp);
                int two=1+helper(s,ind+1,2,dp);
                return dp[ind][laststage]=min(two,one);
            }
        }
        else{
            if(s[ind]=='0'){
                return dp[ind][laststage]=1+helper(s,ind+1,2,dp);
            }
            else{
                return dp[ind][laststage]=1+helper(s,ind+1,2,dp);
            }
        }
    }

    int minimumTime(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(3,-1));
        return helper(s,0,0,dp);
    }
};