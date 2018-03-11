#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

void selection_sort(int a[], int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int index = i;
		for (int j = i + 1; j < end; j++)
		{
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}

void bubble_sort(int a[], int start, int end)
{
	for (int i = end - 1; i > 0; i--)
	{
		bool flag = false;
		for (int j = start; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			return;
		}
	}
}

void insertion_sort(int a[], int start, int end)
{
	for (int i = start + 1; i < end; i++)
	{
		int temp = a[i];
		int j;
		for (j = i; j > start && a[j - 1] > temp; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}

void shell_sort(int a[], int start, int end)
{
	for (int i = (end - start) / 2; i > 0; i /= 2)
	{
		for (int j = start + i; j < end; j++)
		{
			int temp = a[j];
			int k;
			for (k = j; k > start && a[k - i] > temp; k -= i)
			{
				a[k] = a[k - i];
			}
			a[k] = temp;
		}
	}
}

int quick_sort_partition(int a[], int start, int end)
{
	//int index = RandomInRange(start, end);
	//Swap(&a[index], a[end - 1]);
	int temp = a[end - 1];
	int index = start - 1;
	for (int i = start; i < end - 1; i++)
	{
		if (a[i] < a[end - 1])
		{
			index++;
			if (index != i)
			{
				swap(a[i], a[index]);
			}
		}
	}
	index++;
	swap(a[index], a[end - 1]);
	return index;
}

void quick_sort(int a[], int start, int end)
{
	if (start == end)
	{
		return;
	}
	int index = quick_sort_partition(a, start, end);
	if (index > start)
	{
		quick_sort(a, start, index);
	}
	if (index < end)
	{
		quick_sort(a, index + 1, end);
	}
}

void heap_down(int a[], int pos, int length)
{
	int parent, child;
	int temp = a[pos];
	for (parent = pos; parent * 2 + 1 < length; parent = child)
	{
		child = parent * 2 + 1;
		if (child != length - 1 && a[child] < a[child + 1])
		{
			child++;
		}
		if (temp >= a[child])
		{
			break;
		}
		else
		{
			a[parent] = a[child];
		}
	}
	a[parent] = temp;
}

void heap_sort(int a[], int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heap_down(a, i, length);
	}
	for (int i = length - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heap_down(a, 0, i);
	}
}

void merge(int a[], int temp[], int start, int mid, int end)
{
	int i, j, k;
	for (i = 0; i < end; i++)
	{
		temp[i] = a[i];
	}
	for (i = start, j = mid, k = start; i < mid && j < end; k++)
	{
		if (temp[i] < temp[j])
		{
			a[k] = temp[i++];
		}
		else
		{
			a[k] = temp[j++];
		}
	}
	while (i < mid)
	{
		a[k++] = temp[i++];
	}
	while (j < end)
	{
		a[k++] = temp[j++];
	}
}

void merge_sort(int a[], int temp[], int start, int end)
{
	if (start < end - 1)
	{
		int mid = (start + end) / 2;
		merge_sort(a, temp, start, mid);
		merge_sort(a, temp, mid, end);
		merge(a, temp, start, mid, end);
	}
}

typedef struct treeNode
{
	treeNode *left;
	treeNode *right;
	int value;
}treeNode;

void pre_order(treeNode *root)
{
	if (root != NULL)
	{
		//do things here
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(treeNode *root)
{
	if (root != NULL)
	{
		in_order(root->left);
		//do things here
		in_order(root->right);
	}
}

void post_order(treeNode *root)
{
	if (root != NULL)
	{
		post_order(root->left);
		post_order(root->right);
		//do things here
	}
}

void level_order(treeNode *root)
{
	treeNode *p = root;
	queue<treeNode *> q;
	if (p != NULL)
	{
		q.push(p);
	}
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		//do things here
		if (p->left != NULL)
		{
			q.push(p->left);
		}
		if (p->right != NULL)
		{
			q.push(p->right);
		}
	}
}

int binary_search(int a[], int length, int value)
{
	int left = 0;
	int right = length - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (value > a[mid])
		{
			left = mid + 1;
		}
		else if (value < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

const int m = 10;
const int n = 10;

void dfs_edge(int u, int g[m][n], int visited[m][n])
{
	for (int v = 0; v < n; v++)
	{
		if (g[u][v] && !visited[u][v])
		{
			//无向图
			visited[u][v] = visited[v][u] = 1;
			//有向图
			visited[u][v] = 1;
			dfs_edge(v, g, visited);
			//do things here
		}
	}
}

void dfs_vertex(int u, int g[m][n], int visited[n])
{
	visited[u] = 1;
	for (int v = 0; v < n; v++)
	{
		if (g[u][v] && !visited[v])
		{
			dfs_vertex(v, g, visited);
			//do things here
		}
	}
}

void permutation(char *pStr, int index, int n)
{
	if (index == n)
	{
		cout << pStr;
	}
	else
	{
		for (int i = index; i <= n; i++)
		{
			swap(pStr[i], pStr[index]);
			permutation(pStr, index + 1, n);
			swap(pStr[i], pStr[index]);
		}
	}
}

//字典序全排列

void reverse(char *pBegin, char *pEnd)
{
	while (pBegin < pEnd)
	{
		swap(*pBegin++, *pEnd--);
	}
}

bool next_permutation(char a[])
{
	char *p, *q, *pFind;
	char *pEnd = a + strlen(a) - 1;
	if (a == pEnd)
	{
		return false;
	}
	p = pEnd;
	while (p != a)
	{
		q = p;
		p--;
		if (*p < *q)
		{
			pFind = pEnd;
			while (*pFind < *p)
			{
				--pFind;
			}
			swap(*p, *pFind);
			reverse(q, pEnd);
			return true;
		}
	}
	reverse(a, pEnd);
	return false;
}

int cmp(const void *a, const void *b)
{
	return int(*(char *)a - *(char *)b);
}

void dictionary_permutation()
{
	char str[4] = "bca";
	int num = 1;
	qsort(str, strlen(str), sizeof(char), cmp);
	do
	{
		cout << num++ << ":" << str;
	} while (next_permutation(str));
}

void subset1(int *set, int index, int n, int *flag)
{
	if (index == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (flag[i])
			{
				cout << set[i];
			}
		}
		cout << endl;
		return;
	}
	flag[index] = 1;
	subset1(set, index + 1, n, flag);
	flag[index] = 0;
	subset1(set, index + 1, n, flag);
}

void subset2(int *set, int n)
{
	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				cout << set[j];
			}
		}
		cout << endl;
	}
}

int dp[n];
int vis[n];
int map[m][n];
//无固定终点
int dag_dp1(int i)
{
	if (dp[i] > 0) return dp[i];
	for (int j = 0; j < n; j++)
	{
		if (map[i][j] != INT_MIN)
		{
			dp[i] = max(dp[i], dag_dp1(j) + map[i][j]);
		}
	}
	return dp[i];
}

//有固定终点，除了终点dp值为0之外，其他皆为INF
int dag_dp2(int i)
{
	if (vis[i])
	{
		return dp[i];
	}
	vis[i] = true;
	for (int j = 0; j<n; j++)
	{
		if (map[i][j] != INT_MIN) {
			dp[i] = max(dp[i], dag_dp2(j) + map[i][j]);
		}
	}
	return dp[i];
}

char *my_strcpy(char *dst, const char *src)
{
	assert(dst != NULL && src != NULL);
	char *ret = dst;
	int length = strlen(src) + 1;
	if (dst >= src && dst <= src + length - 1)
	{
		dst += length - 1;
		src += length - 1;
		while (length--)
		{
			*dst-- = *src--;
		}
	}
	else
	{
		while (length--)
		{
			*dst++ = *src++;
		}
	}
	return ret;
}

typedef struct listNode
{
	int value;
	listNode *next;
}listNode;

listNode *ReverseList(listNode* pHead)
{
	listNode *pReversedHead = NULL;
	listNode *pNode = pHead;
	listNode *pPrev = NULL;
	while (pNode != NULL)
	{
		listNode *pNext = pNode->next;
		if (pNext == NULL)
		{
			pReversedHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}

class MyString
{
public:
	MyString(const char *str = NULL);
	MyString(const MyString &str);
	~MyString();
	MyString operator +(const MyString &str);
	MyString &operator =(const MyString &str);
	MyString &operator =(const char *str);
	bool operator == (const MyString &str);
	int length();
	MyString substr(int start, int n);
	friend ostream &operator << (ostream &o, const MyString &str);
private:
	char *data;
	int size;
};

MyString::MyString(const char *str)
{
	if (str == NULL)
	{
		data = new char[1];
		data[0] = '\0';
		size = 0;
	}
	else
	{
		size = strlen(str);
		data = new char[size + 1];
		strcpy(data, str);
	}
}

MyString::MyString(const MyString &str)
{
	size = str.size;
	data = new char[size + 1];
	strcat(data, str.data);
}

MyString::~MyString()
{
	delete[] data;
}

MyString &MyString::operator = (const MyString &str)
{
	if (this != &str)
	{
		MyString strTemp(str);
		char *pTemp = str.data;
		strTemp.data = data;
		data = pTemp;
	}
	return *this;
}

MyString &MyString::operator = (const char *str)
{
	if (data == str)
	{
		return *this;
	}
	delete[] data;
	size = strlen(str);
	data = new char[size + 1];
	strcpy(data, str);
	return *this;
}

bool MyString::operator ==(const MyString &str)
{
	return strcmp(data, str.data) == 0;
}

int MyString::length()
{
	return size;
}

ostream &operator <<(ostream &o, const MyString &str)
{
	return o << str.data;
}

MyString MyString::operator+(const MyString &str)
{
	MyString newStr;
	delete[] newStr.data;
	newStr.size = size + str.size;
	newStr.data = new char[size + 1];
	strcpy(newStr.data, data);
	strcpy(newStr.data, str.data);
	return newStr;
}

MyString MyString::substr(int start, int n)
{
	MyString newStr;
	delete[] newStr.data;
	newStr.data = new char[n + 1];
	for (int i = 0; i < n; ++i) {
		newStr.data[i] = data[start + i];
	}
	newStr.data[n] = '\0';
	newStr.size = n;
	return newStr;
}



int main()
{
	//排序测试
	int a[7] = { 3,4,1,2,9,5,7 };
	//selection_sort(a, 0, 7);
	bubble_sort(a, 0, 7);
	//insertion_sort(a, 0, 7);
	//shell_sort(a, 0, 7);
	//quick_sort(a, 0, 7);
	//heap_sort(a,7);
	//int temp[7];
	//merge_sort(a, temp, 0, 7);
	//cout << binary_search(a, 7, 3);
	for (int i = 0; i < 7; i++)cout << a[i];
	//char str[4] = "bac";
	//permutation(str, 0, 2);
	//int a[3] = { 0,1,2 };
	//int b[3] = { 0,0,0 };
	//subset1(a, 0, 3, b);
	//subset2(a, 3);s
	//char a[5] = "hell";
	//char b[5];
	//my_strcpy(b, a);
	//cout << b;
	//dictionary_permutation();

	//生产者消费者
	//读者写者
}
