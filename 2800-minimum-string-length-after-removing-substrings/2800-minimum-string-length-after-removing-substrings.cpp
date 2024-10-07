class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='B' and !st.empty() and st.top()=='A')st.pop();
            else if(s[i]=='D' and !st.empty() and st.top()=='C')st.pop();
            else st.push(s[i]);
        }
        return st.size();
    }
};