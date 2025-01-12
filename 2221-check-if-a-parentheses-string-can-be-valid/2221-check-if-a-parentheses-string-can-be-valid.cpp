class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1)return false;
        int open=0,close=0;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0' or s[i]=='(')open++;
            else if(s[i]==')')open--;
            if(open<0)return false;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i]=='0' or s[i]==')')close++;
            else if(s[i]=='(')close--;
            if(close<0)return false;
        }
        return true;
    }
};