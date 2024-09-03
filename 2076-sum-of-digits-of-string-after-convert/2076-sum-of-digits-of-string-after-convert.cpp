class Solution {
public:
    int getLucky(string s, int k) {
        int num=0;
        string val;
        for(int i=0;i<s.size();i++){
            int temp=s[i]-'a'+1;
            val+=to_string(temp);
        }
        while(k--){
            string str=val;
            num=0;
            for(int i=0;i<str.size();i++){
                num+=str[i]-'0';
            }   
            val=to_string(num);
        }
        return num;
    }
};