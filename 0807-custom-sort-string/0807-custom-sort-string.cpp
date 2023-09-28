class Solution {
public:
    // This question needs some prerequisites of the oops 
    static string str;
    static bool cmp(char c1, char c2){
        return(str.find(c1)<str.find(c2));
    }

    string customSortString(string order, string s) {
        str=order;
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};
string Solution::str;