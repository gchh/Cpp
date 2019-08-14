/*********************************************************************************************
029:简单的Filter
总时间限制: 1000ms 内存限制: 65536kB 
描述
编写Filter模板，使得程序产生指定输出 不得编写 Filter函数

输出
MikeJackLucy
3,4,5,
*********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// 在此处补充你的代码
template<class T1,class T2>
T1* Filter(T1* t1, T1* t2, T1* t3, bool(*fun)(T2 t))
{
	while (t2 - t1 > 0)
	{
		if ((*fun)(*t1) == true)
		{
			*t3 = *t1;
			t3++;
		}
		t1++;
	}
	return t3;
}
// 在此处补充你的代码

bool LargerThan2(int n)
{
	return n > 2;
}
bool LongerThan3(string s) 
{
	return s.length() > 3;
}

string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
string as2[5];
int  a1[5] = { 1,2,3,4,5};
int a2[5];
int main() {
	string * p = Filter(as1,as1+5,as2,LongerThan3);
	for(int i = 0;i < p - as2; ++i)
		cout << as2[i];
	cout << endl; 
	int * p2 = Filter(a1,a1+5,a2,LargerThan2);
	for(int i = 0;i < p2-a2; ++i)
		cout << a2[i] << ",";
	return 0;
}
