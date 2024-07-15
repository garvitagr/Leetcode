class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int i;
        for(i=0;i<nums.size();i++){
            int index=abs(nums[i])-1;
            if(nums[index]<0)ans.push_back(abs(nums[i]));
            else nums[index]*=-1;
        }
        return ans;
    }
};