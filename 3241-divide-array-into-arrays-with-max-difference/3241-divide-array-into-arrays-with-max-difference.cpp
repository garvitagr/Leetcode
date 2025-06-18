class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>v,empty;
        sort(nums.begin(),nums.end());
        int i,j;
       
        for(i=0;i<nums.size();){
            vector<int>g;
            for(j=i;j<i+3;j++)g.push_back(nums[j]);
            i=j;
            if(g[2]-g[1] >k)return empty;
            if(g[1]-g[0] >k)return empty;
            if(g[2]-g[0] >k)return empty;
            v.push_back(g);
        }
        return v;
    }
};