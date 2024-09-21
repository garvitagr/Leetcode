class Solution {
public:
    void helper(vector<int>&ans,int n,int curnum){
        ans.push_back(curnum);
        for(int i=0;i<=9;i++){
            if(curnum*10+i<=n){
                helper(ans,n,curnum*10+i);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            if(i<=n)helper(ans,n,i);
        }
        return ans;
    }
};