class Solution {
public:
    int maxDiff(int num) {
        string s1=to_string(num);
        string num1,num2;
        pair<char,int>p1={'9','9'};
        pair<char,int>p2={'0','0'};
        
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='9'){
                num1+='9';
            }
            else if(p1.first=='9')p1.first=s1[i],p1.second='9',num1+='9';
            else if(p1.first==s1[i])num1+='9';
            else num1+=s1[i];
        }
        if(s1[0]=='1'){
            num2+='1';
            for(int i=1;i<s1.size();i++){
                if(s1[i]=='0' or s1[i]=='1'){
                    num2+=s1[i];
                }
                else if(p2.first=='0')p2.first=s1[i],p2.second='0',num2+='0';
                else if(p2.first==s1[i])num2+='0';
                else num2+=s1[i];
            }
        }
        else{
            p2={s1[0],'1'};
            for(auto it:s1){
                if(it==p2.first)num2+='1';
                else num2+=it;
            }
        }
        return stoi(num1)-stoi(num2);
    }
};