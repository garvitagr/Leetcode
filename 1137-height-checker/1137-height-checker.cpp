class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans=0;
        vector<int>expected=heights;
        sort(expected.begin(),expected.end());
        for(int i=0;i<heights.size();i++){
            if(expected[i]!=heights[i])ans++;
        }
        return ans;
    }
};