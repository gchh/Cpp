/*******************************************************************************************
011:Big & Base 封闭类问题
总时间限制: 1000ms 内存限制: 65536kB 
描述
程序填空，输出指定结果

输入
多组数据，每组一行，是一个整数

输出
对每组数据，输出两行，每行把输入的整数打印两遍

样例输入
3
4

样例输出
3,3
3,3
4,4
4,4	
*******************************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big
{
public:
	int v;
	Base b;
// 在此处补充你的代码
Big(int x) :v(x), b(x){}
// 在此处补充你的代码
};
int main()
{
	int n;
	while(cin >>n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
}
