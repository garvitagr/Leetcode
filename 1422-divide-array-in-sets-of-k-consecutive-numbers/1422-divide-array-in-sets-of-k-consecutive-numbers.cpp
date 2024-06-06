class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)return false;
        map<int,int>mp;
        int i;
        for(i=0;i<nums.size();i++)mp[nums[i]]++;

        for(auto [num,freq]:mp){
            while(freq--){
                for(i=num;i<num+k;i++){
                    if(mp[i]==0)return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};