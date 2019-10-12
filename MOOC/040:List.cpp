/*********************************************************************************
040:List
总时间限制: 4000ms 内存限制: 65536kB 

描述
写一个程序完成以下命令：
new id ——新建一个指定编号为id的序列(id<10000)
add id num——向编号为id的序列加入整数num
merge id1 id2——合并序列id1和id2中的数，并将id2清空
unique id——去掉序列id中重复的元素
out id ——从小到大输出编号为id的序列中的元素，以空格隔开

输入
第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。

输出
按题目要求输出。

样例输入
16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1

样例输出
1 2 3 
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4
**********************************************************************************/
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
list<int> all[10005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		string line;
		cin >> line;
		if (line == "new") 
		{
			int id;
			cin >> id;
		}
		if (line == "add") 
		{
			int id, num;
			cin >> id >> num;
			all[id].push_back(num);
			all[id].sort();
		}
		if (line == "out") 
		{
			int id;
			cin >> id;
			list<int>::iterator p;
			p = all[id].begin();
			if (p != all[id].end())
			{
				cout << *p++;
				for (; p != all[id].end(); p++)
					cout << " " << *p;
			}
			cout << endl;
		}
		if (line == "merge") 
		{
			int a, b;
			cin >> a >> b;
			all[a].merge(all[b]);
			all[a].sort();
		}
		if (line == "unique") 
		{
			int id;
			cin >> id;
			all[id].unique();
		}
	}
	return 0;
}

