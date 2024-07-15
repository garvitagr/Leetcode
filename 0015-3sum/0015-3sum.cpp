class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        vector<vector<int>>ans,result;
        for(int i=0;i<nums.size();i++)mp[nums[i]]=i;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int thirdval=-(nums[i]+nums[j]);
                if(mp.find(thirdval)!=mp.end() and mp[thirdval]>j)ans.push_back({nums[i],nums[j],thirdval});
            }
        }
        sort(ans.begin(),ans.end());
        for(auto it:ans){
            if(result.size() and result.back()==it)continue;
            result.push_back(it);
        }
        return result;
    }
};