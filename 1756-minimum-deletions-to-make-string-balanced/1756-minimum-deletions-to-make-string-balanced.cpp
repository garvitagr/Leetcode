class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ct=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')st.push(s[i]);
            else if((st.empty() or st.top()=='a'))st.push(s[i]);
            else st.pop(),ct++;
        }
        return ct;
    }
};