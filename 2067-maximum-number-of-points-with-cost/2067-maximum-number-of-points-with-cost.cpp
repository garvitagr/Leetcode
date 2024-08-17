class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long i,j,n=points.size(),m=points[0].size();
        vector<long long>prev(points[0].begin(),points[0].end());

        for(i=1;i<n;i++){
            vector<long long>left(m),right(m);
            left[0]=prev[0];
            right[m-1]=prev[m-1];
            
            for(j=1;j<m;j++)left[j]=max(left[j-1]-1,prev[j]);
            for(j=m-2;j>=0;j--)right[j]=max(right[j+1]-1,prev[j]);
            for(j=0;j<m;j++){
                prev[j]=max(left[j],right[j])+points[i][j];
            }
        }

        return *max_element(prev.begin(),prev.end());
    }
};