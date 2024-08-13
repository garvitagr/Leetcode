class Solution {
public:

    void combination(int ind,int target,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans){

        if(target==0){
            ans.push_back(ds);
            return;
        }

        int i;
        for(i=ind;i<candidates.size();i++){

            if(i>ind and candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            combination(i+1,target-candidates[i],candidates,ds,ans);
            ds.pop_back();
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>ans;
        combination(0,target,candidates,ds,ans);
        return ans;
    }
};