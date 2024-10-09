class Solution {
public:
    int minAddToMakeValid(string s) {
        int i,n=s.size();
        stack<char>st;
        for(i=0;i<n;i++){
            if(!st.empty() and st.top()=='(' and s[i]==')')st.pop();
            else st.push(s[i]);
        }
        return st.size();
    }
};