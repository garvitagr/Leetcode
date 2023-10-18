class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s.find(part)== string:: npos)return s;
        s.erase(s.find(part),part.size());
       return removeOccurrences(s,part);
    }
};