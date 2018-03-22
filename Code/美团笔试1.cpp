#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

/*
字符串由ab两种字母构成，两个串x y，保证x比y长
以y的长度在x中截取所有子串，并计算这些子串与y串的距离，最后求和
如aabb与baba的距离为2
*/

// 1. 遍历
// int main()
// {
// 	string a, b;
// 	cin >> a >> b; //a is longer;

// 	int s = a.size(), t = b.size();
// 	int sum = 0;

// 	for (int i = 0; i < s - t + 1; i++)
// 	{
// 		for (int j = 0; j < t; j++)
// 		{
// 			if (a[i + j] ^ b[j])
// 				sum += 1;
// 		}
// 	}

// 	cout << sum;
// 	//system("pause");
// 	return 0;
// }

//2. 利用每个字符比较的独立性，不用串与串比较，而是统计区间中'a'的数量（能推算出'b'）
//因而转化为前缀和（部分和问题）
int main()
{
	string a, b;
	cin >> a >> b;

	int alen = a.size(), blen = b.size();

	vector<int> numOfa(alen + 1, 0); //the number of 'a' BEFORE a[i](not included a[i])

	if (alen == 0 || blen == 0)
		return 1;

	for (int i = 1; i <= alen; i++) //1 more loger than string a
	{
		if (a[i - 1] == 'a')
			numOfa[i] = numOfa[i - 1] + 1;
		else
			numOfa[i] = numOfa[i - 1];
	}

	int res = 0, len = alen - blen;
	for (int i = 0; i < blen; i++)
	{
		int aCnt = numOfa[i + len + 1] - numOfa[i];
		if (b[i] == 'b')
			res += aCnt;
		else
			res += (len - aCnt);
	}

	cout >> res;
	return 0;
}
