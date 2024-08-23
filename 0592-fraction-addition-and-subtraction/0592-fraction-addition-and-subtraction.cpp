class Solution {
public:
    string fractionAddition(string s) {
        vector<int>deno,num;
        int x,y,sign=1,lcm;
        string temp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='/'){
                x=stoi(temp);
                num.emplace_back(x*sign);
                sign=1;
                temp="";
            }
            else if(s[i]=='-' or s[i]=='+'){
                if(temp.size()){
                    y=stoi(temp);
                    deno.emplace_back(y*sign);
                }
                temp="";
                if(s[i]=='-')sign=-1;
                else sign=1;
                // cout<<sign<<endl;
            }
            else temp+=s[i];
        }
        y=stoi(temp);
        deno.emplace_back(y*sign);

    if(deno.size()>1){
        int gcd=deno[0],mul=1;
        for(int i=0;i<deno.size();i++){
            gcd=__gcd(gcd,deno[i]);
            mul*=deno[i];
        }
        lcm=mul/gcd;
    }
    else lcm=deno[0];
        
        // cout<<lcm<<endl;
        x=0;
        for(int i=0;i<num.size();i++){
            int times=lcm/deno[i];
            x+=times*num[i];
        }   

        int gcd=__gcd(x,lcm);

        x/=gcd;
        y=lcm/gcd;
        sign=((x<0 or y<0)?-1:1);
        if(sign==-1)temp="-";
        else temp="";
        return temp+to_string(abs(x))+"/"+to_string(abs(y));
    }
};
