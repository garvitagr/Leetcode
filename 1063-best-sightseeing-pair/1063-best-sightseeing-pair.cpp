class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_i=values[0],ans=0;
        for(int i=1;i<values.size();i++){
            ans=max(ans,values[i]-i+max_i);
            max_i=max(values[i]+i,max_i);
        }
        return ans;
    }
};