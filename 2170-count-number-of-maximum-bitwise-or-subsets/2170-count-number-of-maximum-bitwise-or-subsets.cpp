class Solution {
public:
    void helper(int ind,vector<int>&nums,map<int,int>&mp,int curOr){
        if(ind==nums.size()){
            mp[curOr]++;
            return;
        }
        helper(ind+1,nums,mp,curOr|nums[ind]);
        helper(ind+1,nums,mp,curOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        map<int,int>mp;
        helper(0,nums,mp,0);
        auto it=mp.rbegin();
        return mp[it->first];
    }
};