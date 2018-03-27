/*
https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/34/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int n[26];
        memset(n, -1, 4*26);
        
        int a;
        for(int i=0; i<s.size(); i++){
            a=s[i]-'a';
            if(n[a]==-1)
                n[a]=i;
            else if(n[a]>-1)
                n[a]=-2;
        }
        
        int res = s.size();
        for(int i=0; i<26; i++){
            if(n[i]>-1 && n[i]<res){
                res=n[i];
            }
        }
        if(res == s.size())
            return -1;
        else
            return res;
    }
};
