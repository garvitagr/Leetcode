class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>mp;
        map<int,int>extracanadd;
        int i,n=nums.size(),j;
        for(i=0;i<n;i++)mp[nums[i]]++;

        for(i=0;i<n;i++){
            if(mp[nums[i]]==0)continue;
            if(extracanadd[nums[i]]){
                mp[nums[i]]--;
                extracanadd[nums[i]]--;
                extracanadd[nums[i]+1]++;
            }
            else{
                if(mp[nums[i]] and mp[nums[i]+1] and mp[nums[i]+2]){
                    mp[nums[i]]--;
                    mp[nums[i]+1]--;
                    mp[nums[i]+2]--;
                    extracanadd[nums[i]+3]++;
                }
                else return false;
            }
        }
        return true;
    }
};