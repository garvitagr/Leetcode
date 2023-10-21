class Solution {
public:
    void f(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&ds,int i){
        if(i==candidates.size()){
           if(target==0) ans.push_back(ds);
            return;
        }
        
        if(target-candidates[i]>=0){
            ds.push_back(candidates[i]);
            f(candidates,target-candidates[i],ans,ds,i);
            ds.pop_back();
        }
        f(candidates,target,ans,ds,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(candidates,target,ans,ds,0);
        return ans;
    }
};