#include <iostream>
#include <vector>

//给定一个数串，求其不能组成的最小整数
//123456789->10; 123679->4;01123456789->22
using namespace std;

int main() {
	vector<int> h(10, 0);
	char a;
	while (a=getchar()) {
		//统计每个数有几个
		if (a == '\n')
			break;
		if (a >= '0' && a <= '9') {
			h[a - '0'] += 1;
		}
	}

	h[0] += 1;	//0 可以少一个
	
	int idx=0;
	for (int i = 1; i < 9; i++) {
		//最少的个数
		if (h[i] < h[idx]) {
			idx = i;
		}
	}

	int res = 0;
	if (idx == 0) {
		res = pow(10, h[0]);
	}
	else {
		res = idx;
		for (int i = 0; i < h[idx]; i++) {
			res = res * 10 + idx;
		}
	}

	cout << res;
	//system("pause");
}