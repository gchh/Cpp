/**************************************************************************************
038:白给的list排序
总时间限制: 1000ms 内存限制: 65536kB 
描述
程序填空，产生指定输出

输入
无
输出
9.8,7.3,3.4,2.6,1.2,
***************************************************************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
	double a[] = { 1.2, 3.4, 9.8, 7.3, 2.6 };
	list<double> lst(a, a + 5);
	lst.sort(
		// 在此处补充你的代码
		[](double a, double b)->bool
		{
			if (a > b)return true;
			else return false;
		}
		// 在此处补充你的代码
		);

	for (list<double>::iterator i = lst.begin(); i != lst.end(); ++i)
		cout << *i << ",";
	return 0;
}

