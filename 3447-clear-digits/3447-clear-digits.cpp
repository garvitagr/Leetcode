class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]>='a' and s[i]<='z')st.push(s[i]);
            else if(st.size()) {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};