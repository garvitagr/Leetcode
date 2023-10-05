class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int i;
        vector<int>ans;
        for(i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second > nums.size()/3)ans.push_back(it.first);
        }
        return ans;
    }
};