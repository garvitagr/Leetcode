class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.second!=p2.second)return p1.second<p2.second;
        return p1.first>p2.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        for(auto it:v){
            int val=it.first;
            int times=it.second;
            while(times--)ans.push_back(val);
        }
        return ans;
    }
};