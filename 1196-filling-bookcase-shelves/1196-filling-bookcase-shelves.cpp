class Solution {
public:
    int helper(int width,int ind,vector<vector<int>>&books,vector<int>&dp){
        if(ind>=books.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int width_covered=0,curmaxheight=0,ans=INT_MAX;

        for(int i=ind;i<books.size();i++){
            int w=books[i][0];
            int h=books[i][1];
            if(w+width_covered>width)return dp[ind]=ans;
            curmaxheight=max(curmaxheight,h);
            width_covered+=w;
            ans=min(ans,curmaxheight+helper(width,i+1,books,dp));
        }
        return dp[ind]=ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size()+1,-1);
        return helper(shelfWidth,0,books,dp);
    }
};