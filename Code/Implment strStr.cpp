/*
https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/38/
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int hlen = haystack.size(), nlen = needle.size();
        
        if(hlen < nlen)
            return -1;
        
        while(i <= hlen - nlen){
            for(j = 0; j<nlen; j++){
                if(haystack[i+j]!=needle[j]){
                    i++;
                    break;
                }
            }
            if(j!=nlen)
                continue;
            else
                return i;
        }
        
        return -1;
    }
};