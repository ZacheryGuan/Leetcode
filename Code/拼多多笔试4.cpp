/*
给定一个序列 寻找最长的斐波那契子序列
输入整数n 再输入n个整数
输出最长子序列的长度
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	if (n <= 2)
		return n;

	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector< vector<int> > dp(n, vector<int>(n, 2));	//shortest Fib is at least 2
	int maxlen = 2;
	for (int i = 1; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = 0; k < i; k++) {
				if (nums[j] == nums[k] + nums[i]) {
					if (dp[i][j] <= dp[k][i]) {
						//if nums[k]+nums[i]=nums[j], and there is no loger Fib
						dp[i][j] = dp[k][i] + 1;
						if (dp[i][j] > maxlen)
							maxlen = dp[i][j];
					}
				}
			}
			
		}
	}

	cout << maxlen;
	cin >> maxlen;
	return 0;
}