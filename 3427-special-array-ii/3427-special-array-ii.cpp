class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int i,n=nums.size(),j;
        vector<int>v;
        vector<bool>ans;
        for(i=0;i<n-1;i++){
            if((nums[i]&1)and((nums[i+1]&1))){
                v.push_back(i);
            }
            else if(!(nums[i]&1) and !(nums[i+1]&1)){
                v.push_back(i);
            }
        }
        if(v.size()==0){
            for(i=0;i<queries.size();i++)ans.push_back(1);
            return ans;
        }
        v.push_back(n);
        for(i=0;i<queries.size();i++){
            pair<int,int>p;
            p.first=queries[i][0];
            p.second=queries[i][1];

            int ind=lower_bound(v.begin(),v.end(),p.first)-v.begin();
            if(v[ind]>=p.first and v[ind]+1<=p.second){
                ans.push_back(0);
            }
            else ans.push_back(1);

        }
        return ans;
    }
};