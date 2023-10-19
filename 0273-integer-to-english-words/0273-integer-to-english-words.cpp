class Solution {
public:

    string print(int &num,vector<pair<int,string>>&v){
        if(num==0)return "Zero";
        
        int i;
        string ans="";
        for(i=0;i<v.size();i++){
            if(num/v[i].first >0){
                int x=num/v[i].first;
                if(num>=100)ans+=(print(x,v)+" ");
                ans+=v[i].second;
                int y=num%v[i].first;
                if((y)!=0)ans+=" "+print(y,v);
                return ans;
            }
        }
        return "";
    }


    string numberToWords(int num) {
        vector<pair<int,string>>v;
        v.push_back(make_pair(1000000000,"Billion"));
        v.push_back(make_pair(1000000,"Million"));
        v.push_back(make_pair(1000,"Thousand"));
        v.push_back(make_pair(100,"Hundred"));
        v.push_back(make_pair(90,"Ninety"));
        v.push_back(make_pair(80,"Eighty"));
        v.push_back(make_pair(70,"Seventy"));
        v.push_back(make_pair(60,"Sixty"));
        v.push_back(make_pair(50,"Fifty"));
        v.push_back(make_pair(40,"Forty"));
        v.push_back(make_pair(30,"Thirty"));
        v.push_back(make_pair(20,"Twenty"));
        v.push_back(make_pair(19,"Nineteen"));
        v.push_back(make_pair(18,"Eighteen"));
        v.push_back(make_pair(17,"Seventeen"));
        v.push_back(make_pair(16,"Sixteen"));
        v.push_back(make_pair(15,"Fifteen"));
        v.push_back(make_pair(14,"Fourteen"));
        v.push_back(make_pair(13,"Thirteen"));
        v.push_back(make_pair(12,"Twelve"));
        v.push_back(make_pair(11,"Eleven"));
        v.push_back(make_pair(10,"Ten"));
        v.push_back(make_pair(9,"Nine"));
        v.push_back(make_pair(8,"Eight"));
        v.push_back(make_pair(7,"Seven"));
        v.push_back(make_pair(6,"Six"));
        v.push_back(make_pair(5,"Five"));
        v.push_back(make_pair(4,"Four"));
        v.push_back(make_pair(3,"Three"));
        v.push_back(make_pair(2,"Two"));
        v.push_back(make_pair(1,"One"));
       return print(num,v);        
    }
};