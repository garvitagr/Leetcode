class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>v;
        vector<int>ans;
        int i,k=nums.size(),mini=INT_MAX;
        priority_queue<pair<int,pair<int,int>>>mn,mx;
        
        for(i=0;i<k;i++){
            mx.push({nums[i][0],{i,0}});
            mn.push({-nums[i][0],{i,0}});
        }
        while(true){
            int minimum=mn.top().first *-1;
            int maximum=mx.top().first;
            v.push_back({minimum,maximum});
            int arrnum=mn.top().second.first;
            int index=mn.top().second.second;
            mn.pop();
            if(index+1<nums[arrnum].size()){
                mn.push({-nums[arrnum][index+1],{arrnum,index+1}});
                mx.push({nums[arrnum][index+1],{arrnum,index+1}});
            }
            else break;
        }

        for(i=0;i<v.size();i++){
            mini=min(v[i].second-v[i].first,mini);
        }
        for(i=0;i<v.size();i++){
            if(mini==v[i].second-v[i].first)return{v[i].first,v[i].second};
        }
        return ans;
    }
};