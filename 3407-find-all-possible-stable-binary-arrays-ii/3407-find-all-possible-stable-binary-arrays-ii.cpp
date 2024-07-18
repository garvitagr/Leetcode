class Solution {
public:
    int mod=1000000007;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>>dp(zero+1,vector<vector<int>>(one+1,vector<int>(2,0)));
        int i,j;
        for(i=1;i<=min(zero,limit);i++)dp[i][0][0]=1;
        for(i=1;i<=min(one,limit);i++)dp[0][i][1]=1;
        
        for(i=1;i<=zero;i++){
            for(j=1;j<=one;j++){
                dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%mod;
                if(i>limit){
                    dp[i][j][0]=(dp[i][j][0]-dp[i-(limit+1)][j][1]+mod)%mod;
                }
                dp[i][j][1]=(dp[i][j-1][0]+dp[i][j-1][1])%mod;
                if(j>limit){
                    dp[i][j][1]=(dp[i][j][1]-dp[i][j-(limit+1)][0]+mod)%mod;
                }
            }   
        }
        return (dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};