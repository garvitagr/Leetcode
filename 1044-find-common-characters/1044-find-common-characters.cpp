class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int i;
        for(char ch='a';ch<='z';ch++){
            int ct=INT_MAX;
            for(i=0;i<words.size();i++){
                int count=0;
                for(int j=0;j<words[i].size();j++){
                    if(words[i][j]==ch)count++;
                }
                ct=min(ct,count);
            }
            string s;
            s.push_back(ch);
            for(i=0;i<ct;i++)ans.push_back(s);
        }
        return ans;
    }
};