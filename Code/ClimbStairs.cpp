/*
https://leetcode-cn.com/problems/climbing-stairs/description/
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        int res = 0, a = 1, b = 2;
        for (int i = 3; i<=n; i++){
            res = a + b;
            a = b;
            b = res;
        }
        
        return res;
    }
};