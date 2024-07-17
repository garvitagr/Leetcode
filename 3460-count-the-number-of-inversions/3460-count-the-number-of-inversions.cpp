class Solution {
public:
    int mod=1000000007;
    unordered_map<int,int>mp;
    int helper(int curpos,int invbefore,int n,vector<vector<int>>&dp){
        if(mp.find(curpos-1)!=mp.end() and invbefore!=mp[curpos-1])return 0;
        if(curpos==n)return 1;
        if(dp[curpos][invbefore]!=-1)return dp[curpos][invbefore];
        int ans=0;
        for(int i=0;i<=curpos;i++){
            if(invbefore+i >400)break;
            ans+=helper(curpos+1,invbefore+i,n,dp);
            ans%=mod;
        }
        return dp[curpos][invbefore]=(ans%mod);
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        mp.clear();
        vector<vector<int>>dp(n+1,vector<int>(401,-1));
        for(int i=0;i<requirements.size();i++)mp[requirements[i][0]]=requirements[i][1];
        return helper(0,0,n,dp);
    }
};