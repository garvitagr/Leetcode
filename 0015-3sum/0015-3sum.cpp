class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i,j,k;
        for(i=0;i<nums.size();i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            j=i+1;k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0)k--;
                else if(sum<0)j++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<nums.size() and nums[j]==nums[j-1])j++;
                    while(k>=0 and nums[k]==nums[k+1])k--;
                }
            }
        }
        return ans;
    }
};