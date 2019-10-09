/*************************************************************************************
033:排序，又见排序!
总时间限制: 1000ms 内存限制: 65536kB
描述
自己编写一个能对任何类型的数组进行排序的mysort函数模版。只能写一个mysort模板，不能写mysort函数！

输入
无

输出
4,8,10,11,123,
123,11,10,8,4,
1.4,1.2,1.8,3.1,3.2,2.1,

***************************************************************************************/
#include <iostream>
using namespace std;
bool Greater1(int n1, int n2)
{
	return n1 < n2;
}
bool Greater2(int n1, int n2)
{
	return n1 > n2;
}
bool Greater3(double d1, double d2)
{
	return d1 < d2;
}
// 在此处补充你的代码
template <class T1, class T2>
void mysort(T1* first, T1* last, T2* op)
{
	T1 tmp;
	for (int i = 0; i < last - first; ++i)
	{
		for (int j = i + 1; j < last - first; ++j)
		{
			if (op(*(first + i), *(first + j)) == false)
			{
				tmp = *(first + i);
				*(first + i) = *(first + j);
				*(first + j) = tmp;
			}
		}
	}
}
// 在此处补充你的代码
#define NUM 5
int main()
{
	int an[NUM] = { 8,123,11,10,4 };
	mysort(an, an + NUM, Greater1); //从小到大排序 
	for (int i = 0; i < NUM; i++)
		cout << an[i] << ",";
	mysort(an, an + NUM, Greater2); //从大到小排序 
	cout << endl;
	for (int i = 0; i < NUM; i++)
		cout << an[i] << ",";
	cout << endl;
	double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1 };
	mysort(d + 1, d + 5, Greater3); //将数组从下标1到下标4从小到大排序 
	for (int i = 0; i < 6; i++)
		cout << d[i] << ",";
	return 0;
}
