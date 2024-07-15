class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>tempans;
        int i,j;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++){
            for(j=i+1;j<nums.size();j++){
                int ele=nums[i]+nums[j];
                ele*=-1;
                int ind=lower_bound(nums.begin()+j+1,nums.end(),ele)-nums.begin();
                if(ind!=nums.size() and nums[ind]==ele){
                    vector<int>temp={nums[i],nums[j],nums[ind]};
                    tempans.insert(temp);
                }
            }
        }
        for(auto it:tempans){
            ans.push_back(it);
        }
        return ans;
    }
};