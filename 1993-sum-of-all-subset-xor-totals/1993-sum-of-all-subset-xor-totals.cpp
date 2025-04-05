class Solution {
public:
    int helper(int i,vector<int>&nums,int val){
        if(i==nums.size())return val;

        int ans=0;
        // take
        ans+=helper(i+1,nums,val^nums[i]);
        // not take
        ans+=helper(i+1,nums,val);
        return ans;

    }

    int subsetXORSum(vector<int>& nums) {
        return helper(0,nums,0);
    }
};