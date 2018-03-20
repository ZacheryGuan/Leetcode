/*
输入一个表达式及结果，判断其是从左至右（类老式计算器）还是先乘后加（正确计算）
输出L表示从左至右，M表示先乘后加，I表示两者都不，U表示无法判断（两者结果一致）
*/

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main() {
	stack<float> num;
	stack<char> sig;
	string exp;
	float Mnum, Lnum, Dnum;

	getline(cin, exp);
	cin >> Dnum;

	//calc Lnum
	//read an int
	float left = 0;
	int i, j;
	for (j = 0; j < exp.size(); j++) {
		if (exp[j] >= '0' && exp[j] <= '9') {
			left = 10.0 * left + exp[j] - '0';
		}
		else {
			break;
		}
	}
	num.push(left);

	for (i=j ; i < exp.size(); i++) {
		float right = 0;
		char op=exp[j];
		j++;
		for ( ; j < exp.size(); j++) {
			if (exp[j] >= '0' && exp[j] <= '9') {
				right = 10.0 * right + exp[j] - '0';
			}
			else {
				break;
			}
		}
		i = j;
		float top = num.top();
		
		num.pop();
		if (op == '+')
			num.push(top + right);
		else
			num.push(top*right);
	}
	Lnum = num.top();
	num.pop();

	//calc Mnum
	left = 0;
	for (j = 0; j < exp.size(); j++) {
		if (exp[j] >= '0' && exp[j] <= '9') {
			left = 10.0 * left + exp[j] - '0';
		}
		else {
			i = j;
			break;
		}
	}
	num.push(left);

	for (i = j; i < exp.size(); i++) {
		float right = 0;
		char op = exp[j];
		j++;

		//get right num
		for (; j < exp.size(); j++) {
			if (exp[j] >= '0' && exp[j] <= '9') {
				right = 10.0 * right + exp[j] - '0';
				//cout << right << endl;
			}
			else {
				break;
			}
		}
		i = j;
		float top = num.top();
		if (op == '*') {
			num.pop();
			num.push(top*right);
		}
		//op == '+'
		else {	
			if (sig.size() == 0) {
				sig.push('+');
				num.push(right);
			}
			else {
				float a = num.top();
				num.pop();
				float b = num.top();
				num.pop();

				num.push(a + b);
				num.push(right);
			}

		}
		
	}
	
	if (sig.size() != 0) {
		float a = num.top();
		num.pop();
		float b = num.top();
		num.pop();

		num.push(a + b);
	}
	Mnum = num.top();
	num.pop();
	
	if (abs(Dnum - Mnum)<0.001) {
		if (abs(Lnum -Mnum)<0.001) {
			cout << 'U';
		}
		else {
			cout << 'M';
		}
	}
	else if(abs(Dnum - Lnum)<0.001)
	{
		cout << 'L';
	}
	else
	{
		cout << 'I';
	}
	
	system("pause");
	return 0;
}