class Solution {
public:

    void f(int open,int close,int n,string s,vector<string>&ans){
        if((s.size())==2*n){
            cout<<open<<" "<<close<<" ";
            ans.push_back(s);
            return;
        }

        if(open<n){
            f(open+1,close,n,s+"(",ans);
        }
        if(close<open){
            f(open,close+1,n,s+=")",ans);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f(0,0,n,"",ans);
        return ans;
    }
};