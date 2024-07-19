class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int i,j;
        vector<int>row(n),col(m),ans;
        for(i=0;i<n;i++){
            int temp=INT_MAX;
            for(j=0;j<m;j++)temp=min(temp,matrix[i][j]);
            row[i]=temp;
        }
        for(j=0;j<m;j++){
            int temp=INT_MIN;
            for(i=0;i<n;i++)temp=max(temp,matrix[i][j]);
            col[j]=temp;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(row[i]==matrix[i][j] and col[j]==matrix[i][j])ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};