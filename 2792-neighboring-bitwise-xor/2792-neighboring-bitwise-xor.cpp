class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        if(n==1 and derived[0])return false;
        else if(n==1)return true;
        vector<int>ans;
        if(derived[0]){
            ans.push_back(0);
            ans.push_back(1);    
        }
        else{
            ans.push_back(0);
            ans.push_back(0);
        }
        for(int i=1;i<n-1;i++){
            if(derived[i]){
                if(ans[i])ans.push_back(0);
                else ans.push_back(1);
            }
            else{
                if(ans[i])ans.push_back(1);
                else ans.push_back(0);
            }
        }
        return ans[0]^ans.back()==derived.back();
    }
};