class Solution {
public:
    string decodeMessage(string key, string message) {
        char ch='a';
        char mapping[260]={0};
        int i;

        for(i=0;i<key.size();i++){
            if(key[i]!=' ' and mapping[key[i]]==0){
                mapping[key[i]]=ch++;
            }
        }
        for(i=0;i<message.size();i++){
            if(message[i]!=' ')message[i]=mapping[message[i]];
        }
        return message;
    }
};