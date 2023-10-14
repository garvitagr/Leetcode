class Solution {
public:
    void f(vector<int>temp,vector<vector<int>>&ans,int i,vector<int>&nums){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        // number pick karte hai
        temp.push_back(nums[i]);
        f(temp,ans,i+1,nums);
        // number skip karte hai
        temp.pop_back();
        f(temp,ans,i+1,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(temp,ans,0,nums);
        return ans;
    }
};