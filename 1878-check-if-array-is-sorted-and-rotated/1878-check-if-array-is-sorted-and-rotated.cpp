class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0,a=0;
        for(i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])a++;
        }
        if(nums[nums.size()-1]>nums[0])a++;
        if(a<2)return true;
        return false;
    }
};