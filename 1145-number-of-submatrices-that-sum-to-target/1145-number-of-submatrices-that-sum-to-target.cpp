class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans=0,n=matrix.size(),m=matrix[0].size();

        vector<vector<int>>prefix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)prefix[i][j]+=(j==0?0:prefix[i][j-1])+matrix[i][j];
        }

        for(int colstart=0;colstart<m;colstart++){
            for(int colend=colstart;colend<m;colend++){
                unordered_map<int,int>mp;
                int prev=0;
                mp[0]=1;
                for(int row=0;row<n;row++){
                    int colsum=(colstart==0)?prefix[row][colend]:prefix[row][colend]-prefix[row][colstart-1];
                    int totalsum=colsum+prev;
                    if(mp.find(totalsum-target)!=mp.end())ans+=mp[totalsum-target];
                    mp[totalsum]++;
                    prev=totalsum;
                }
            }
        }        
        return ans;
    }
};