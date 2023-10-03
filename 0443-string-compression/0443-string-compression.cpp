class Solution {
public:
    int compress(vector<char>& chars) {
        int cur=0;
        int ct=1,s,e;
        char ch=chars[0];
        for(int i=1;i<chars.size();i++){
            if(ch==chars[i])ct++;
            else {
                chars[cur++]=ch;
                ch=chars[i];
                if(ct>1){
                    s=cur;
                    while(ct){
                        chars[cur++]=ct%10 +'0';
                        ct/=10;
                    }
                    e=cur-1;
                    while(s<=e){
                        swap(chars[s],chars[e]);
                        s++;e--;
                    }
                }
                ct=1;
            }
        }

        chars[cur++]=ch;
         if(ct>1){
            s=cur;
            while(ct){
                chars[cur++]=ct%10 +'0';
                ct/=10;
            }
            e=cur-1;
            while(s<=e){
            swap(chars[s],chars[e]);
            s++;e--;
             }
        }
        return cur;

    }
};