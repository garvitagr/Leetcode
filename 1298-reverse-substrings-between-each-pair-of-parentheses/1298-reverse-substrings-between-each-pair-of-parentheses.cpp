class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=')')st.push(s[i]);
            else{
                string str="";
                while(st.top()!='('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto it:str)st.push(it);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};