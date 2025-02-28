class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>>dp(str1.size()+10,vector<int>(str2.size()+10,0));
        int i,j,n=str1.size(),m=str2.size();
        string ans="";

        for(i=n-1;i>=0;i--){
            for(j=m-1;j>=0;j--){
                if(str1[i]==str2[j])dp[i][j]= 1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        i=0;j=0;
        
        while(i<str1.size() and j<str2.size()){
            if(str1[i]==str2[j]){
                ans.push_back(str1[i]);
                i++;j++;
            }
            else if(dp[i+1][j]>=dp[i][j+1]){
                ans.push_back(str1[i]);
                i++;
            }
            else {
                ans.push_back(str2[j]);
                j++;
            }
        }
        while(i<str1.size()){
            ans.push_back(str1[i]);
            i++;
        }
        while(j<str2.size()){
            ans.push_back(str2[j]);
            j++;
        }
        return ans;
    }
};