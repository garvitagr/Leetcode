class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        st.push(0);
        string ans;
        for(int i=0;i<num.size();i++){
            int val=num[i]-'0';
            while((!st.empty()) and (st.top()>val) and (k>0))st.pop(),k--;
            st.push(val);
        }
        while(!st.empty()){
            ans+=st.top()+'0';
            st.pop();
        }
        while(!ans.empty() and ans.back()=='0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        while(!ans.empty() and k>0)ans.pop_back(),k--;
        return (ans.empty()?"0":ans);
    }
};