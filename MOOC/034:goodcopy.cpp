/*****************************************************************************************
034:goodcopy
总时间限制: 1000ms 内存限制: 65536kB
描述
编写GoodCopy类模板，使得程序按指定方式输出

输入
第一行是整数 t,表示数据组数
每组数据：
第一行是整数 n , n < 50
第二行是 n 个整数
第三行是 n 个字符串

输出
将输入的整数原序输出两次，用","分隔
然后将输入的字符串原序输出两次，也用 ","分隔

样例输入
2
4
1 2 3 4
Tom Jack Marry Peking
1
0
Ted

样例输出
1,2,3,4,
1,2,3,4,
Tom,Jack,Marry,Peking,
Tom,Jack,Marry,Peking,
0,
0,
Ted,
Ted, 
******************************************************************************************/
#include <iostream>
using namespace std;

template <class T>
struct GoodCopy {
	// 在此处补充你的代码
public:
	void operator()(T* first, T* last, T* dest)
	{
		int i;
		T* tmp = new T[(last - first)*sizeof(T)];
		for (i=0;i<last-first;++i)
		{
			*(tmp+i) = *(first+i);
		}
		for (i = 0; i < last - first; ++i)
		{
			*(dest + i) = *(tmp + i);
		}
		delete[] tmp;
	}
	// 在此处补充你的代码
};

int a[200];
int b[200];
string c[200];
string d[200];

template <class T>
void Print(T s, T e) {
	for (; s != e; ++s)
		cout << *s << ",";
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> a[i];
		GoodCopy<int>()(a, a + m, b);
		Print(b, b + m);
		GoodCopy<int>()(a, a + m, a + m / 2);
		Print(a + m / 2, a + m / 2 + m);

		for (int i = 0; i < m; ++i)
			cin >> c[i];
		GoodCopy<string>()(c, c + m, d);
		Print(c, c + m);
		GoodCopy<string>()(c, c + m, c + m / 2);
		Print(c + m / 2, c + m / 2 + m);
	}
	return 0;
}


