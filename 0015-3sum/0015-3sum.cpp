class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        set<vector<int>>ans;
        int i,j,ind,thirdval;
        for(i=0;i<nums.size();i++){
            for(j=i+1;j<nums.size();j++){
                thirdval=-(nums[i]+nums[j]);
                ind=lower_bound(nums.begin()+j+1,nums.end(),thirdval)-nums.begin();
                if(ind!=nums.size() and nums[ind]==thirdval)ans.insert({nums[i],nums[j],thirdval});
            }
        }
        for(auto it:ans){
            result.push_back(it);
        }
        return result;
    }
};