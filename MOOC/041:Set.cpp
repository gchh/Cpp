/**********************************************************************************************
041:Set
总时间限制: 5000ms 内存限制: 100000kB 

描述
现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
add x 把x加入集合
del x 把集合中所有与x相等的元素删除
ask x 对集合中元素x的情况询问
对每种操作，我们要求进行如下输出。
add 输出操作后集合中x的个数
del 输出操作前集合中x的个数
ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。

输入
第一行是一个整数n，表示命令数。0<=n<=100000。
后面n行命令，如Description中所述。

输出
共n行，每行按要求输出。

样例输入
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1

样例输出
1
2
1 2
0 0
0
2
1 0

提示
Please use STL’s set and multiset to finish the task
***********************************************************************************************/
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
	multiset<int>s;
	multiset<int>s_erase;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		string line;
		cin >> line;
		if (line == "add") 
		{
			int num;
			cin >> num;
			s.insert(num);
			cout << s.count(num) << endl;
		}
		if (line == "del") 
		{
			int num;
			cin >> num;
			int ct;
			ct = s.erase(num);
			if (ct > 0)s_erase.insert(num);
			cout << ct << endl;
		}
		if (line == "ask") 
		{
			int num;
			cin >> num;
			if (s.find(num) == s.end() && s_erase.find(num) == s_erase.end())
			{
				cout << 0 << " ";
			}
			else cout << 1 << " ";
			cout << s.count(num) << endl;
		}
	}
	return 0;
}


