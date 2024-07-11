class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int i,n=nums.size(),j,gap=INT_MAX;
        map<int,int>prevends;
        for(i=n-1;i>=0;i--){
            map<int,int>newends;
            for(auto it:prevends){
                int value=it.first;
                int lastend=it.second;
                newends[value|nums[i]]=max(lastend,newends[value|nums[i]]);
            }
            newends[nums[i]]=max(i,newends[nums[i]]);
            prevends=newends;
            for(auto it:newends){
                gap=min(gap,abs(k-it.first));
            }
        }
        return gap;
    }
};