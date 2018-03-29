/*
数列: 1, 12, 123,...12345678910,1234567891011...。
计算从数列的第l个到第r个(包含端点)这些数中，有几个是能被3整除的
https://www.nowcoder.com/question/next?pid=9763997&qid=152606&tid=14672349
*/

#include <iostream>
using namespace std;
int main(){
    int s, t;
    cin >> s >> t;
    int res=0;
    int group = 2*((t-s+1)/3);
    int remain = (t-s+1) %3;
    if(remain == 0)
        cout << group;
    else{
        switch(t%3){
            case 0: cout << group+remain;break;
            case 1: cout << group+remain-1;break;
            case 2: cout << group +1;break;
        }
    }
    return 0;
}