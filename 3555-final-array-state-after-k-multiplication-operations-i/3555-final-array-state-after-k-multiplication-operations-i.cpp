class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0;i<k;i++){
            int ind=min_element(nums.begin(),nums.end())-nums.begin();
            nums[ind]*=multiplier;
        }
        return nums;
    }
};