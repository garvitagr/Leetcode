class Solution {
public:

    string add(string &num1,string &num2,string &ans,int i,int j,int carry){
        if(i<0 and j<0 and carry==0)return ans;
        int temp=0;
        if(i>=0){
            temp+=num1[i]-'0';
            i--;
        }
        if(j>=0){
            temp+=num2[j]-'0';
            j--;
        }
        temp+=carry;
        char ch;
        if(temp>9){
            ch=(temp%10)+'0';
            carry=1;
        }
        else{
            ch=(temp)+'0';
            carry=0;
        }
        ans+=ch;
       return add(num1,num2,ans,i,j,carry);

    }

    string addStrings(string num1, string num2) {
        string ans="",pp;
        pp= add(num1,num2,ans,num1.size()-1,num2.size()-1,0);
        reverse(pp.begin(),pp.end());
        return pp;
    }
};