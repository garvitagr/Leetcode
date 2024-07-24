class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.first!=p2.first)return p1.first<p2.first;
        else return p1.second<p2.second;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>v;
        // vector<pair<string,pair<int,int>>>v;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            for(int j=0;j<s.size();j++){
                s[j]=mapping[s[j]-'0']+'0';
            }
            int val=stoi(s);
            v.push_back({val,i});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<nums.size();i++)ans.push_back(nums[v[i].second]);
        return ans;   
    }
};