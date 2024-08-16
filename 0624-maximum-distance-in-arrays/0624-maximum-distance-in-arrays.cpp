class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        vector<vector<int>>minimum,maximum;
        for(int i=0;i<arrays.size();i++){
            int mini=INT_MAX,maxi=INT_MIN;
            for(int j=0;j<arrays[i].size();j++){
                mini=min(mini,arrays[i][j]);
                maxi=max(maxi,arrays[i][j]);
            }
            maximum.push_back({maxi,i});
            minimum.push_back({mini,i});
        }
        sort(minimum.begin(),minimum.end());
        sort(maximum.begin(),maximum.end());        
        
        if(maximum[m-1][1]==minimum[0][1]){
            int ans1=maximum[m-1][0]-minimum[1][0];
            int ans2=maximum[m-2][0]-minimum[0][0];
            return max(ans1,ans2);
        }
        return maximum[m-1][0]-minimum[0][0];
    }
};